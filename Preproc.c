#include <stdio.h>
#include <inttypes.h>

#define WORD uint64_t
#define PF PRIX64
#define W 64
#define BYTE uint8_t

// Var related to each other package
union Block {
    // 64 * 64 bits
    BYTE bytes[128];
    // 16 * 64 bits
    WORD words[64];
    uint64_t sixf[16];
};

// Enum is essentially a flag
enum Status {
    READ, PAD, END
};

// Get next block
int next_block(FILE *f, union Block *B, enum Status *S, uint64_t *nobits){
    // Number of bites to read
    size_t nobytes;
    
    if(*S == END){
        return 0;
    } else if (*S == READ){
        // Try to read 64 bytes
        nobytes = fread(B->bytes, 1, 128, f);
        // Calculate total bits read so far
        *nobits = *nobits + (8 * nobytes);

        if(nobytes == 128){
            return 1;
        }

        // Enough room for padding
        // 100?
        else if(nobytes <= 100){
            // Append a 1 bit 
            B->bytes[nobytes++] = 0x80; 
            // Append enough 0 bits, leaving 128 at the end
            while (nobytes++ < 128){
                B->bytes[nobytes] = 0x00;
            }

            // Append length of original input (CHECK ENDIANESS)
            B->sixf[15] = *nobits;
            // Last block
            *S = END;
        } else {
            // Got to the end of the input message
            // Not enough room in this block for all the padding
            // Append a 1 bit and 15 0 bits to make a full byte

            // check 0x80
            B->bytes[nobytes] = 0x80;
            // Append 0 bits
            while (nobytes++ < 128){
                B->bytes[nobytes] = 0x00;
            }
            // Change the status to PAD
            *S = PAD;
        }
    } else if(*S == PAD){
        nobytes = 0;
        // Append 0 bits
        while (nobytes++ < 128){
            B->bytes[nobytes] = 0x00;
        }
        // Append no bits as an int
        B->sixf[15] = *nobits;
        // Change the status to PAD
        *S = PAD;
    }

    return 1;
}

int main(int args, char *argv[]){
    // Error checking here. Testing
    // If file opened correctly

    int i = 0;
    // Current block
    union Block B;
    uint64_t nobits = 0;
    // Current status of bits read
    enum Status S = READ;

    // File pointer
    FILE *f;
    // Open file from command line for reading
    f = fopen(argv[1], "r");

    // Loop through preprocessed blocks from input
    while (next_block(f, &B, &S, &nobits)){
        // Print the 16 64-bit words
        for(i=0; i < 16; i++){
            printf("%08" PF " ", B.words[i]);
        }
        printf("\n");
    }

    fclose(f);
    printf("Total bits read: %d. \n", nobits);

    return 0;
}
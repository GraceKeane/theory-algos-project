#include <stdio.h>
// Fixed number of bits
#include <inttypes.h>

#define WORD uint64_t 
#define PF PRIX64
#define W 64
#define BYTE uint8_t

// Var related to each other package
// SHA works on blocks of 1024 bits
union Block {
    // 8 * 128 bits
    BYTE bytes[128]; // correct num
    // 16 * 64 bits
    WORD words[16];  // correct num
    // 64 * 8
    uint64_t sixf[8];
};

// Enum is essentially a flag for
// keeping track of input message/ padding
enum Status {
    READ, PAD, END
};

// Get next block
// Return 1 if it created a new block from original message 
// or padding
// Returns 0 if all padded message has already been consumed
int next_block(FILE *f, union Block *B, enum Status *S, uint64_t *nobits){
    
    // File error handling
    if(f == NULL){
        printf("Error opening file");
        return 0;
    } else {
    
    // Number of bites to read
    size_t nobytes;
    
    // Check if status is end
    if(*S == END){
        return 0;
    } else if (*S == READ){
        // Try to read 128 bytes from file
        nobytes = fread(B->bytes, 1, 128, f); // correct
        // Calculate total bits read so far
        *nobits = *nobits + (8 * nobytes);

        if(nobytes == 128){
            // This happens when we can read 64 bytes from f
            return 1;
        }

        // step 3
        // Enough room for padding 128 - 9 = 119
        else if(nobytes < 119){
            // Append a 1 bit 
            // This happens when have enough room for padding
            B->bytes[nobytes] = 0x80;
            // Append enough 0 bits, leaving 128 at the end
            for (nobytes++; nobytes < 119; nobytes++){
                // Keep adding 0's
                B->bytes[nobytes] = 0x00;
            }

            // Append length of original input (CHECK ENDIANESS)
            B->sixf[7] = *nobits;
            // Last block
            // Set status to end
            *S = END;
        } else {
            // Got to the end of the input message
            // Not enough room in this block for all the padding
            // Append a 1 bit and 7 0 bits to make a full byte

            // check 0x80
            B->bytes[nobytes] = 0x80;
            // Append 0 bits
            for (nobytes++; nobytes < 128; nobytes++){
                // Error: trying to write to B->nobytes[128]
                B->bytes[nobytes] = 0x00;
            }
            // Change the status to PAD
            *S = PAD;
        }

        // Dont have enough padding to do the last block
        } else if(*S == PAD){
            nobytes = 0;
            // Append 0 bits
            for (nobytes = 0; nobytes < 119; nobytes++){
                B->bytes[nobytes] = 0x00;
            }
            // Append no bits as an int  CHECK ENDINESS
            B->sixf[7] = *nobits;
            // Change the status to PAD
            *S = END;
        }
        return 1;
    }
}

int main(int args, char *argv[]){
    // Error checking here. Testing
    // If file opened correctly

    // Iterator
    int i;
    // Current block
    union Block B;
    uint64_t nobits = 0;
    // Current status of bits read
    enum Status S = READ;

    // File pointer
    FILE *f;

    // File error handling
    if(f == NULL){
        printf("Error opening file");
        return 0;
    } else {
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
        // Close this file
        fclose(f);
        // Print total number of bits read
        printf("Total bits read: %d. \n", nobits);

        return 0;
    }
}
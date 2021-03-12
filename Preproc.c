#include <stdio.h>
#include <inttypes.h>

#define WORD uint64_t
#define PF PRIX64
#define W 64
#define BYTE uint8_t

// Var related to each other package
union Block {
    // 64 * 64 bits
    BYTE bytes [128];
    // 16 * 64 bits
    WORD words[16];
};

int main(int args, char *argv[]){
    // Error checking here. Testing
    // If file opened correctly

    int i = 0;
    // Current block
    union Block B;
    uint64_t nobits = 0;

    // File pointer
    FILE *f;
    // Open file from command line for reading
    f = fopen(argv[1], "r");

    // Number of bites to read
    size_t nobytes;
    // Read a byte from a file using fread
    nobytes = fread(B.bytes, 1, 128, f);
    // Tell command line how many read
    printf("Read %d bytes. \n", nobytes);
    // Update num of bits read
    nobits = nobits + (8 * nobytes);
    // Print the 16 64-bit words
    for(i=0; i < 16; i++){
        printf("%08" PF " ", B.words[i]);
        if ((i + 1) % 8 == 0)
        printf("\n");
    }
    
    while (!feof(f)){
        nobytes = fread(&B.bytes, 1, 128, f);
        printf("Read %d bytes. \n", nobytes);
        nobits = nobits + (8 * nobytes);

        // Print the 16 64-bit words
        for(i=0; i < 16; i++){
            printf("%08" PF " ", B.words[i]);
            if ((i + 1) % 8 == 0)
            printf("\n");
        }
    }

    fclose(f);
    printf("Total bits read: %d. \n", nobits);

    return 0;
}
#include <stdio.h>
#include <inttypes.h>

// Words and bytes.
#define WORD uint32_t
#define PF PRIx32
#define BYTE uint8_t

// SHA256 works on blocks of 512 bits.
union Block {
    // 8 x 64 = 512 - dealing with block as bytes.
    BYTE bytes[64];
    // 32 x 16 = 512 - dealing with block as words.
    WORD words[16];
    // 64 x 8 = 512 - dealing with the last 64 bits of last block.
    uint64_t sixf[8];
};


int update(union Block *M) {
    for (int i = 0; i < 16; i++)
        M->words[i] = M->words[i] + 1;
    return 0;
}

int main(int argc, char *argv) {
    union Block M;
    int i, j;

    for (i = 0; i < 64; i++)
        M.bytes[i] = i;
    
    for (i = 0; i < 64; i++)
        printf("%02x,", M.bytes[i]);
    printf("\n");    
    
    for (i = 0; i < 16; i++)
        printf("%08" PF ",", M.words[i]);
    printf("\n\n");

    
    for (j = 0; j < 3; j++) {
        update(&M);
        for (i = 0; i < 64; i++)
            printf("%02x,", M.bytes[i]);
        printf("\n");    
        
        for (i = 0; i < 16; i++)
            printf("%08" PF ",", M.words[i]);
        printf("\n\n");
    
    }

    return 0;
}
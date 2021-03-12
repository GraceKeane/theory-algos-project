#include <stdio.h>
#include <inttypes.h>

#define BYTE uint8_t

void bin_print(BYTE i){
    // Number of bits in an integer
    // sizeof - build in operator (unary)
    int j = sizeof(BYTE) * 8;

    // Temporary variable
    int k;

    // Loop over the number of bits in i
    for(j-- ; j >= 0; j--){
        /*  
            Ternary operator
            ? - check true or false
            1 - true  0 - false
            -1 = always true val
        */

        // Pick out the j'th bit of i
        // true if j'th bit is 1, else 0
        k = ((1 << j) & i) ? 1 : 0;
        printf("%d", k);
    }
}

int main(int args, char *argv[]){
    // Error checking here. Testing
    // If file opened correctly

    BYTE b;

    FILE *f;
    // r - read file
    f = fopen(argv[1], "r");

    size_t nobytes;

    // Read a byte from a file using fread
    nobytes = fread(&b, 1, 1, f);
    while (nobytes){
        bin_print(b);
        nobytes = fread(&b, 1, 1, f);
    }
    fclose(f);
    printf("\n");

    return 0;
}
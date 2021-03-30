#include <stdio.h>

// Showing how the bitoperations work

void bin_print(unsigned int i){
    // Number of bits in an integer
    // sizeof - build in operator (unary)
    int j = sizeof(unsigned int) * 8;

    // Temporary variable
    int k;

    // Loop over the number of bits in i
    for(j-- ; j >= 0; j--){
        /*  
            Notes: 
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

// Arg count & vector list of strings
// Standard main signiture
int main(int argc, char *argv[]){

    for(int i = 0; i < argc; i++){
        printf("%s\n", argv[i]);
    }
    return 0;


    // Set i to a literal value - hard coded val
    unsigned int i = 0x0f0f0f0f;

    printf("Original:\t");
    // Prints out i in binary
    bin_print(i);
    printf("\t%x\t%u\n", i, i);

    // 32
    int j = sizeof(unsigned int) * 8;

    for(j--; j >=0; j--){
        // 1 shifted left j times
        bin_print(1 << j); printf("\n");
        // i.
        bin_print(i); printf("\n");
        printf("__________________________________  &\n");
        // (1 shifted left j times) bitwise logical and i
        bin_print((1 << j) & i); printf("\n\n");
    }
    return 0;
}
#include <stdio.h>

void bin_print(int i){
    // Number of bits in an integer
    int j = sizeof(int) * 8;

    // Temporary variable
    int k;

    // EXPLANATION HERE...
    for(j-- ; j >= 0; j--){
        k = ((1 << j) & i) ? 1 : 0;
        printf("%d", k);
    }
}

// arg count & vector list of strings
int main(int argc, char *argv[]){

    int i = 0xf1; 

    printf("Original: ");
    bin_print(i);
    printf("\n");

    for(int j = 0; j < 40; j++){
        // Bin printing
        printf("%3d << %2d: ", i, j);
        bin_print(i << j);
        printf("\n");
    }

    return 0;
}
#include <stdio.h>

// arg count & vector list of strings
int main(int argc, char *argv[]){

    int i = 0xF1; // 11110001

    printf("Dec: %d\n", i);
    printf("Hex: %X\n", i);

    printf("Size of i: %d\n", sizeof(i));
    printf("Size of int: %d\n", sizeof(int));
    printf("Size of char: %d\n", sizeof(char));

    char c = 41;
    printf("c in char is: %c\n", c);
    printf("c in int is: %d\n", c);

    // Testing overflow value
    int j = 1000000000; 
    printf("j in int is: %d\n", j);
    printf("j in char is: %c\n", (char) j);
    printf("j in int from char is: %d\n", (int)(char) j);

    return 0;
}
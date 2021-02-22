#include <stdio.h>
#include <inttypes.h>

// Referance - https://web.microsoftstream.com/video/9d3237fb-55e9-4159-9e08-aa2e086495e5

// Replacing word & pf (32 bits)
// 64 bits for SHA512
#define WORD uint64_t
// X - prints hex val
#define PF PRIX64

// Function called Ch that takes x,y,z as inputs
// 32 bits 
WORD Ch(WORD x, WORD y, WORD z) {
    // Bitwise XOR = ^
    // Bitwise AND (^) = &
    // Bitwise complement (L) = ~ 
    return (x&y)^(~x&z);
}

// Maj

int main(int argc, char *argv[]) {

    WORD x = 0x0F0F0F0F;
    WORD y = 0x0A0A0A0A;
    WORD z = 0xB0B0B0B0;
    
    WORD ans = Ch(x, y, z);

    // String literal (hard coded string)
    printf("Ch(%08" PF ",%08" PF ",%08" PF ")=%08" PF "\n", x, y, z, ans);

    return 0;
}

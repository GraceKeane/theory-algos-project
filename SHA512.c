// Standard C package
#include <stdio.h>
// Package for retrieving fixed number of bits
#include <inttypes.h>

#define WLEN 64
#define WORD uint64_t 
#define PF PRIX64
#define BYTE uint8_t

/*
    Setting up functions
*/

// Ch function - choose bits
#define CH(x,y,z) (x&y)^(~x&z)
// Maj function - majority vote
#define MAJ(x,y,z) (x&y)^(x&z)^(y&z)  

#define ROTL(x,n) (x<<n)|(x>>(WLEN-n))
#define ROTR(x,n) (x>>n)|(x<<(WLEN-n))
// Shift right
#define SHR(x,n) x>>n

#define SIG0(x) ROTR(x,28)^ROTR(x,34)^ROTR(x,39)
#define SIG1(x) ROTR(x,14)^ROTR(x,18)^ROTR(x,41)
#define sig0(x) ROTR(x,1)^ROTR(x,8)^SHR(x,7)
#define sig1(x) ROTR(x,19)^ROTR(x,61)^SHR(x,6)

// Types
// SHA512 works on blocks of 1024 bits
union Block {
    BYTE bytes[128]; 
    WORD words[16]; 
    uint64_t sixf[8];
};

// Enum is essentially a flag for keeping
// track of input message/ padding
enum Status {
    READ, PAD, END
};

// 64 bits words from Secure Hash Standard documentation
const WORD K[] = {
    0x428a2f98d728ae22, 0x7137449123ef65cd, 0xb5c0fbcfec4d3b2f, 0xe9b5dba58189dbbc,
    0x3956c25bf348b538, 0x59f111f1b605d019, 0x923f82a4af194f9b, 0xab1c5ed5da6d8118,
    0xd807aa98a3030242, 0x12835b0145706fbe, 0x243185be4ee4b28c, 0x550c7dc3d5ffb4e2,
    0x72be5d74f27b896f, 0x80deb1fe3b1696b1, 0x9bdc06a725c71235, 0xc19bf174cf692694,
    0xe49b69c19ef14ad2, 0xefbe4786384f25e3, 0x0fc19dc68b8cd5b5, 0x240ca1cc77ac9c65,
    0x2de92c6f592b0275, 0x4a7484aa6ea6e483, 0x5cb0a9dcbd41fbd4, 0x76f988da831153b5,
    0x983e5152ee66dfab, 0xa831c66d2db43210, 0xb00327c898fb213f, 0xbf597fc7beef0ee4,
    0xc6e00bf33da88fc2, 0xd5a79147930aa725, 0x06ca6351e003826f, 0x142929670a0e6e70,
    0x27b70a8546d22ffc, 0x2e1b21385c26c926, 0x4d2c6dfc5ac42aed, 0x53380d139d95b3df,
    0x650a73548baf63de, 0x766a0abb3c77b2a8, 0x81c2c92e47edaee6, 0x92722c851482353b,
    0xa2bfe8a14cf10364, 0xa81a664bbc423001, 0xc24b8b70d0f89791, 0xc76c51a30654be30,
    0xd192e819d6ef5218, 0xd69906245565a910, 0xf40e35855771202a, 0x106aa07032bbd1b8,
    0x19a4c116b8d2d0c8, 0x1e376c085141ab53, 0x2748774cdf8eeb99, 0x34b0bcb5e19b48a8,
    0x391c0cb3c5c95a63, 0x4ed8aa4ae3418acb, 0x5b9cca4f7763e373, 0x682e6ff3d6b2b8a3,
    0x748f82ee5defb2fc, 0x78a5636f43172f60, 0x84c87814a1f0ab72, 0x8cc702081a6439ec,
    0x90befffa23631e28, 0xa4506cebde82bde9, 0xbef9a3f7b2c67915, 0xc67178f2e372532b,
    0xca273eceea26619c, 0xd186b8c721c0c207, 0xeada7dd6cde0eb1e, 0xf57d4f7fee6ed178,
    0x06f067aa72176fba, 0x0a637dc5a2c898a6, 0x113f9804bef90dae, 0x1b710b35131c471b,
    0x28db77f523047d84, 0x32caab7b40c72493, 0x3c9ebe0a15c9bebc, 0x431d67c49c100d4c,
    0x4cc5d4becb3e42b6, 0x597f299cfc657e2a, 0x5fcb6fab3ad6faec, 0x6c44198c4a475817
};

/*
    Carrying out the preprocessing (3 steps)
*/

/*
    Get next block & Return 1 if it created a new block from original
    message or padding.

    Returns 0 if all padded message has already been consumed.
*/
int next_block(FILE *f, union Block *M, enum Status *S, uint64_t *nobits){
    
    // File error handling -> TODO add more error handling
    // & test -> error handling not working properly
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
        nobytes = fread(M->bytes, 1, 128, f); // correct
        // Calculate total bits read so far
        *nobits = *nobits + (8 * nobytes);

        if(nobytes == 128){
            // This happens when we can read 64 bytes from f
            return 1;
        }

        // step 3
        // Enough room for padding? 128 - 9 = 119
        else if(nobytes < 119){
            // Append a 1 bit 
            // This executes when program has enough room for padding
            M->bytes[nobytes] = 0x80;
            // Append enough 0 bits, leaving 128 at the end
            for (nobytes++; nobytes < 119; nobytes++){
                // Keep adding 0's
                M->bytes[nobytes] = 0x00;
            }

            // Append length of original input -> TODO: CHECK ENDINESS
            M->sixf[7] = *nobits;
            // Last block
            // Set status to end
            *S = END;
        } else {
            /*
                Got to the end of the input message but not enough room in 
                this block for all the padding.
            */
            M->bytes[nobytes] = 0x80;
            // Append 0 bits
            for (nobytes++; nobytes < 128; nobytes++){
                M->bytes[nobytes] = 0x00;
            }
            // Change the status to PAD
            *S = PAD;
        }

        // Executes when program does not have enough padding  for the last block
        } else if(*S == PAD){
            nobytes = 0;
            // Append 0 bits
            for (nobytes = 0; nobytes < 119; nobytes++){
                M->bytes[nobytes] = 0x00;
            }
            // Append no bits as an int -> TODO: CHECK ENDINESS
            M->sixf[7] = *nobits;
            // Change the status to PAD
            *S = END;
        }
        return 1;
    }
}

/*
    Step 1, 2, 3, 4 from Sec 6.4.2 - Message Schedule

    Function to calculate the next hash values.
    (H_0 -> H_1 -> H_2 -> ... -> H_N)

    Hash values calculated with corresponding
    message. e.g. H_1 uses M_2 to calculate H_2.

    Message block is made up of 1024 bits.
*/
int next_hash(union Block *M, WORD H[]){
    WORD W[80];
    // Iterator
    int t;
    // Temporary variables
    WORD a, b, c, d, e, f, g, h, T1, T2;

    // Step 1
    for(t = 0; t < 16; t++)
         W[t] = M->words[t];
    for (t = 16; t < 80; t++)
        W[t] = sig1(W[t-2]) + W[t-7] + sig0(W[t-15])  + W[t-16];

    // Step 2
    a = H[0];
    b = H[1];
    c = H[2];
    d = H[3];
    e = H[4];
    f = H[5];
    g = H[6];
    h = H[7];

    // Step 3
    for(t = 0; t < 80; t++)
        T1 = h + SIG1(e) + CH(e, f, g) + K[t] + W[t];
        T2 = SIG0(a) + MAJ(a, b, c);
        h = g;
        g = f;
        f = e;
        e = d + T1;
        d = c;
        c = b;
        b = a;
        a = T1 + T2;

    /* Step 4 - Cal next hash from currect message block
       and current hash value.
    */
    H[0] = a + H[0];
    H[1] = b + H[1];
    H[2] = c + H[2];
    H[3] = d + H[3];
    H[4] = e + H[4];
    H[5] = f + H[5];
    H[6] = g + H[6];
    H[7] = h + H[7];

}

/*

*/
int sha512(FILE *f, WORD H[]){
    // Function that performs the SHA512 algo on message file

    // Message block
    union Block M;
    // 64 bit integer to keep track of num bits
    uint64_t nobits = 0;
    // Current status of the bits read
    enum Status S = READ;

    // Loop through the preprocessing blocks
    while (next_block(f, &M, &S, &nobits)){
        // Passed address of next message block and hash val
        next_hash(&M, H);
    }
    // return type is int, therefore return 0
    return 0;
}

/*
    Sets the initial hash value, opens file for reading 
    and sends a message to sha512 to calculate the hash 
    value by using the initial hash value and file 
    pointer.

    Prints out the H array with final hash value. When
    the function is completed the file is then closed.
*/
int main(int args, char *argv[]){
    
    // Initial hash value (described in preprocessing section)
    // H is a local variable
    WORD H[] = {
        0x6a09e667f3bcc908, 0xbb67ae8584caa73b, 0x3c6ef372fe94f82b, 0xa54ff53a5f1d36f1,
        0x510e527fade682d1, 0x9b05688c2b3e6c1f, 0x1f83d9abfb41bd6b, 0x5be0cd19137e2179
    };

    // *Need error checking here*

    // File pointer
    FILE *f;
    // Open file from command line for reading
    f = fopen(argv[1], "r");

    sha512(f, H);

    // Print the SHA512 hash of f
    for (int i = 0; i < 8; i++)
        printf("%08" PF, H[i]);
    printf("\n");
    
    // Close this file
    fclose(f);

    return 0;
}
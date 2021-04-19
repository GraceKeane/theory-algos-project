<h2 align="center">
    SHA512 Calculator
</h3>

<h3 align="center">
    A program written in C that calculates the SHA512 of an input file
</h4>

<p align="center">
  <img src="./img/logo.jpeg" width=600 height=250/>
</p>

## Project Details
Heading  | Details
-------- | -------------------------------------
Project  | [Project Spec](https://github.com/ianmcloughlin/theory-algos-project)
Course   | BSc (Hons) in Software Development
Module   | Theory of Algorithms
Author   | Grace Keane 
ID       | G00359990
Lecturer | Dr Ian McLoughlin

## Contents
- [Repository Description](#repository-description)
- [SHA512 Overview](#sha512-overview)
- [Software Requirements](#software-requirements)
- [Command Line Installations](#command-line-installations)
- [Running the Program](#running-the-program)
- [Command Line Arguments](#command-line-arguments)
- [Project Implementation](#project-implementation)
- [Testing](#testing)
- [Assignment Questions](#assignment-questions)
- [Referances](#referances)

## Repository Description
This repository contains the C code to compute the SHA512 algorithm based on an input file. The result of the program is a SHA512 message digest. This program also incorporates error handling, a make file, command line arguments and testing.

- Final image of project output will go here

```bash
├── img # Folders contains images discussed in README.md
│   ├──  # logo.jpeg
│   └──  # diagram.png
├── videos # Folder containing screencasts of how to set-up, deploy and run project
│   ├── # Screencast 1
|   └── # Screencast 2
├── .gitignore # Text file listing files to ignore
├── README.md # Full overview of project
├── SHA512.c # SHA512 algorithm coded using C programming language
├── abc.txt # Input file containing a string of "abc"
├── Makefile # Makefile of the program
├── tests.sh # Bash tests file to test if the algorithm if working correctly
```

## SHA512 Overview
There are numerous secure hash algorithms such as the SHA-1, SHA-224, SHA-256, SHA-384, SHA-512, SHA-512/224 and SHA-512/256. These are used for computation of condensed representation of electronic data. When a message of any length  less than ![equation1](https://latex.codecogs.com/gif.latex?2%5E%7B64%7D) bits (for SHA-1, SHA-224 and SHA-256) or less than ![equation2](https://latex.codecogs.com/gif.latex?2%5E%7B128%7D) bits (for SHA-384, SHA-512, SHA-512/224 and SHA-512/256) is input to a hash algorithm. The result is a specific output also known as a message digest which is essentially a compact representation of the binary data recieved as input [8]. These digests range in length from 160 to 512 bits, depending on the algorithm.

The hash algorithms have secure in their name because, for a given algorithm, it is computationally infeasible to find a message that corresponds to a given message digest or to find two different messages that produce the same message digest. Any change at all to a message will give a different result.

The SHA512 algorithm is part of a set of crytographic hash functions designed by the United States National Security (NSA) and published in 2001 [4]. Hashing algorithms are primarily used to provide integrity [7].

## Software Requirements
1. [Windows 10 Education (recommended)](https://www.microsoft.com/en-ie/education/products/windows) <br>
2. [WSL2 for Windows 10](https://docs.microsoft.com/en-us/windows/wsl/install-win10#manual-installation-steps)<br>
3. [Debian](https://www.microsoft.com/en-us/p/debian/9msvkqc78pk6?SilentAuth=1&wa=wsignin1.0&activetab=pivot:overviewtab) <br>
4. [Windows Terminal](https://www.microsoft.com/en-ie/p/windows-terminal/9n0dx20hk701?rtc=1&activetab=pivot:overviewtab)<br>
5. [Visual Studio Code](https://code.visualstudio.com/download)

## Command Line Installations
<b>In windows terminal:</b> <br>
Install make and gcc: ``` sudo apt install build-essential```<br>
ZSH shell: ``` sudo apt install zsh``` <br>
Nicer ZSH shell (optional): ``` sh -c "$(curl -fsSL https://raw.github.com/ohmyzsh/ohmyzsh/master/tools/install.sh)" ```

## Running the Program
1. In your command line terminal: ```git clone https://github.com/GraceKeane/theory-algos-project.git```<br>
2. Navigate to the <b> \program\ </b> directory: ```cd theory-algos-project```<br>
3. Compile the program: ```make```<br>
4. Execute the program: ```./SHA512 abc.txt```<br>

- Add screencasts to explain how to run & code snippets

## Command Line Arguments

| Valid Arguments | Input Example | Output |
| :---:           |     :---:      |     :---: |
| --help          | ```./SHA512 --help``` | Will detail additional arguments and examples on how to execute them|
| --test          | ```./SHA512 --test``` | Runs a suite of tests based on the program |
| --explain       | ```./SHA512 --explain``` | Displays a brief explanation of SHA512 including an ASCII high-level diagram|

## Project Implementation
### Creating the SHA512 functions (Section 4.1.3)
SHA512 uses six logical functions, where each function operates on 64-bit words, which are represented as x, y, and z. The result of each function is a new 64-bit word. The SHA512 functions are defined below through C code as well as in section 4.1.3 of the Secure Hash Standard. 

``` c
#define ROTL(_x,_n) ((_x << _n) | (_x >> ((sizeof(_x)*8) - _n)))
#define ROTR(_x,_n) ((_x >> _n) | (_x << ((sizeof(_x)*8) - _n)))
#define SHR(_x,_n) (_x >> _n)
#define CH(_x,_y,_z) ((_x & _y) ^ (~_x & _z))
#define MAJ(_x,_y,_z) ((_x & _y) ^ (_x & _z) ^ (_y & _z))
#define SIG0(_x) (ROTR(_x,28) ^ ROTR(_x,34) ^ ROTR(_x,39))
#define SIG1(_x) (ROTR(_x,14) ^ ROTR(_x,18) ^ ROTR(_x,41))
#define sig0(_x) (ROTR(_x,1) ^ ROTR(_x,8) ^ SHR(_x,7))
#define sig1(_x) (ROTR(_x,19) ^ ROTR(_x,61) ^ SHR(_x,6))
``` 

### Declare SHA512 Constants (Section 4.2.3)
Declare a specific sequence of eighty constant 64-bit words. These words represent the first sixty-four bits of the fractional parts of the cube roots of the eighty prime numbers. These constants are defined in section 4.2.3 of the Secure Hash Standard. Below is a code example of how I defined these constants in my program.

``` c
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
```

### Preprocessing (Section 5)
<b>Preprocessing consists of 3 steps which are padding the message, parsing the message into message blocks and setting the initial hash value.</b>

#### Padding the message (Section 5.1.2)
The purpose of padding is to ensure that the padded message is a multiple of 1024 bits. The end result of padding should be a message in a multiple of 1024 bits.

<b>Code snippet goes here</b>

#### Parsing the message into message blocks (Section 5.2.2)
The message and its padding are parsed into <i>N</i> 1024-bit blocks. Since the 1024 bits of the input block may be expressed as 64-bit words, the first 64 bits <i>i</i> are donated ![equation3](https://latex.codecogs.com/svg.image?M\tfrac{(i)}{0})
, the next 64 bits are to the power of ![equation4](https://latex.codecogs.com/svg.image?M\tfrac{(i)}{0})
 and so on until ![equation5](https://latex.codecogs.com/svg.image?M\tfrac{(i)}{15}).

#### Setting the initial hash value (Section 5.3.5)
The initial hash value ![equation6](https://latex.codecogs.com/svg.image?H^{(0)}) must be initialised. The size and number of words depends on the message digest. For SHA512 the initial hash value consists of the following eight 64-bit words, in hex. These words were obtained by taking the first 64 bits of the fractional parts of the square roots of the first eight prime numbers.

``` c
WORD H[] = {
        0x6a09e667f3bcc908, 0xbb67ae8584caa73b, 0x3c6ef372fe94f82b, 0xa54ff53a5f1d36f1,
        0x510e527fade682d1, 0x9b05688c2b3e6c1f, 0x1f83d9abfb41bd6b, 0x5be0cd19137e2179
    };
```
### Hash Computation (Section 6.4.2)
The SHA-512 hash computation uses functions and constants defined in section section 6.4.2 of the Secure Hash Standard documentation. The hash computation is made up of four steps.

1) Prepare the message schedule
``` c
 for(t = 0; t < 16; t++)
        W[t] = M->words[t];
    for (t = 16; t < 80; t++)
        W[t] = sig1(W[t-2]) + W[t-7] + sig0(W[t-15]) + W[t-16];
``` 
2) Initialize the eight working variables with the ![equation7](https://latex.codecogs.com/svg.image?i-1^{st}) hash values
``` c
a = H[0];
b = H[1];
c = H[2];
d = H[3];
e = H[4];
f = H[5];
g = H[6];
h = H[7];
``` 

3) Create a for loop to loop initialized from 0 - 79 
``` c
for(t = 0; t < 80; t++) {
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
}
``` 

4) Compute the ![equation8](https://latex.codecogs.com/svg.image?i^{th}) intermediate hash value ![equation9](https://latex.codecogs.com/svg.image?H^{(i)})

``` c
H[0] = a + H[0];
H[1] = b + H[1];
H[2] = c + H[2];
H[3] = d + H[3];
H[4] = e + H[4];
H[5] = f + H[5];
H[6] = g + H[6];
H[7] = h + H[7];
``` 

### Solving Big-Endian
Little and big endian are two ways of storing multibyte data-types ( int, float, etc). In little endian machines, the last byte of binary representation of the multibyte data-type is stored first. On the other hand, in big endian machines, first byte of binary representation of the multibyte data-type is stored first.

Simple way of how I checked if my machine is big endian or little endian using Jupyter Notebook: 

``` py
from sys import byteorder
print(byteorder)
``` 

## Assignment Questions 
<b>Why can't we reverse the SHA512 algorithm to retrieve the original message from a hash digest?</b><br>

Hash algorithms such as the SHA-512 algorithm are most commonly used for security and for detecting if messages have been changed since the digests were generated. They provide encription using an algorithm and no key and are also known as "one-way hash functions" [A1]. There is no possible way to reverse the encription hence the reason they are called "hash" algorithms [7]. They are designed specifically to take in an input, compute the hash function and output a hashed value as shown in <i> figure 1 </i>. This ensures that every bit of output is dependant upon every bit of the input. It prevents others from splitting the algorithm up and trying to reverse calculate an input from each of the output hash separately.  

<p align="center">
  <img src="./img/diagram.png" width=600 height=250/>
</p>
<i><b>Figure 1, SHA algorithm diagram</b></i>

The SHA-512 algorithm is designed to make finding the corresponding input to an output extremely dificult. If ones goal is to find an input that generates a given hash, there should be no way to do it that's faster than brute force - trying every input in turn until one works.

Consider a simple example function 'OR'. If you applied this to an input function of 1 and 0 the solution would be 1. But now having known the answer you cannot revert post solution due to data loss. Instead you are left with three differant possible answers for example (1,1), (0,1) or (1,0). Only brute force could possibly find the correct input variables.

But why is it important to not be able to reverse? Security?

<b>Can you design an algorithm that, given enough time, will find input messages that give each of the possible 512-bit strings?</b><br>

<b>How difficult is it to find a hash digest beginning with at least twelve zeros?</b><br>

## Referances
[1] GitHub, Markdown Cheetsheet, <br>
https://github.com/adam-p/markdown-here/wiki/ <br>
[2] dotcms, Markdown Syntax, <br>
https://dotcms.com/docs/latest/markdown-syntax <br>
[3] Secure Hash Standard, Quynh H. Dang, <br>
https://www.nist.gov/publications/secure-hash-standard <br>
[4] Wikipedia, SHA-2, <br>
https://en.wikipedia.org/wiki/SHA-2 <br>
[5] IBM Developer; Writing endian-independent code in C, <br>
https://developer.ibm.com/technologies/systems/articles/au-endianc <br>
[6] Medium, Cryptography: Explaining SHA-512, <br>
https://medium.com/@zaid960928/cryptography-explaining-sha-512-ad896365a0c1 <br>
[7] ScienceDirect, Message Digest, <br>
https://www.sciencedirect.com/topics/computer-science/message-digest <br>
[8] ScienceDirect, Hashing Algorithm, <br>
https://www.sciencedirect.com/topics/computer-science/hashing-algorithm <br>

## Article Referances
[A1] Sumagita, M., Riadi, I., Sh, J.P.D.S. and Warungboto, U., 2018. Analysis of secure hash algorithm (SHA) 512 for encryption process on web based application. International Journal of Cyber-Security and Digital Forensics (IJCSDF), 7(4), pp.373-381.


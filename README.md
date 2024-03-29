<h2 align="center">
    SHA-512 Calculator
</h3>

<h3 align="center">
    A program written in C that calculates the SHA-512 of an input
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

## Program Output
<p align="center">
  <img src="./img/sampleoutput.PNG" width=650 heigh=500/>
</p>

<i>Figure 1, SHA-512 output</i>

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
This repository contains the C code to compute the SHA512 algorithm based on an input. The result of the program is a SHA512 message digest. This program also incorporates error handling, a make file, normal as well as getops command line arguments and bash testing.

```bash
├── img # Folders contains images discussed in README.md
│   ├──  # logo.jpeg
│   └──  # cmdselection.PNG
│   └──  # diagram.png
│   └──  # sampleoutput.png
|   └──  # cmdhelp.PNG
|   └──  # test.PNG
├── cmd-input # Folder containing getops command line inputted strings
│   ├──  StringInput.txt # Command line strings are written to this for SHA-512 calculation
├── .gitignore # Text file listing files to ignore
├── README.md # Full overview of project
├── SHA512.c # SHA512 algorithm coded using C programming language
├── abc.txt # Input file containing a string of "abc"
├── empty.txt # Blank file for testing
├── Makefile # Makefile of the program
├── tests.sh # Bash tests file to test if the algorithm if working correctly
```

## SHA512 Overview
The SHA512 algorithm is part of a set of crytographic hash functions designed by the [United States National Security (NSA)](https://nvlpubs.nist.gov/nistpubs/FIPS/NIST.FIPS.180-4.pdf) and published in 2001 [4]. Hashing algorithms are primarily used to provide integrity [7]. There are numerous secure hash algorithms such as the SHA-1, SHA-224, SHA-256, SHA-384, SHA-512, SHA-512/224 and SHA-512/256. These are used for computation of condensed representation of electronic data. When a message of any length  less than ![equation1](https://latex.codecogs.com/gif.latex?2%5E%7B64%7D) bits (for SHA-1, SHA-224 and SHA-256) or less than ![equation2](https://latex.codecogs.com/gif.latex?2%5E%7B128%7D) bits (for SHA-384, SHA-512, SHA-512/224 and SHA-512/256) is input to a hash algorithm. The result is a specific output also known as a message digest which is essentially a compact representation of the binary data recieved as input [8]. These digests range in length from 160 to 512 bits, depending on the algorithm.

The hash algorithms have secure in their name because, for a given algorithm, it is computationally infeasible to find a message that corresponds to a given message digest or to find two different messages that produce the same message digest. Any change at all to a message will give a different result. The secure hash algorithms such as SHA512 are very important as they are widely used in internet security, digital certificates and even blockchains [10].

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
4. Execute options program: ```./SHA512``` <br>
5. Execute help cmd line output: ```./SHA512 --help``` <br>
6. Execute explain cmd line output: ```./SHA512 --explain``` <br>
7. Execute hashstring cmd line output: ```./SHA512 --hashstring anystringhere``` <br>
8. Execute hashfile cmd line output:  ```./SHA512 --hashfile filename.txt``` <br>
9. Run tests: ```make test``` <br>

## Command Line Arguments
The C programming language allows for the use of command-line arguments. Command-line arguments allow data to be provided to the program at runtime. Arguments can be passed to the main method if the main method is declared as follows.
``` c
int main(int argc, char *argv[]){  

}
```

The program in this case can take two arguments, an integer called ```argc``` and a character array called ```*argv[]```

- ```argc```
  - Conventionally, argc, which stands for argument count, retrieves the amount of arguments the program has just taken. For example, if the following was ran ./SHA512 one two three, argc would be equal to four, since it includes the actual program declaration [9].

- ```*argv[]```
  - Meaning 'argument vector', argv[] is an array containing the command line arguments. Looking at the previous example, if the input was ./SHA512 one two three, argv[] would be of size four, the first index being SHA512, the second being one and so on [9].

### Functional Command Line Arguments
The table below contains a list of valid command-line arguments specific to the program, an example of how to input them and also their output. 

| Valid Arguments | Input Example | Output |
| :---:           |     :---:      |     :---: |
| --help          | ```./SHA512 --help``` | Will detail additional arguments and examples on how to execute them|
| --explain       | ```./SHA512 --explain``` | Displays a brief explanation of SHA512 including a diagram|
| --hashstring    | ```./SHA512 --hashstring abcde``` | Allows the user to input any string and calculates the SHA512 of that input|
| --hashfile      | ```./SHA512 --hashfile abc.txt``` | Allows the user to input a file and calculates the SHA512 of that specific file|


The arguments were implemented with help from the ```GetOpt::Long``` module. This allows quick definitions of Unix-like interfaces options into the program.

The Arguments could be declared and assigned to a character, in my case, after research [9] they were implemented as an array and associated with a single character meaning it could be utilized and delegated to a single Switch statement. Another benefit is that it could be specified whether to expect an additional argument, like in the case for both --hashfile and --hashstring.
``` c
static struct option long_options[] = {
    {"help"      , no_argument      , 0, 'h'},
    {"explain"   , no_argument      , 0, 'e'},
    {"hashfile"  , required_argument, 0, 'f'},
    {"hashstring", required_argument, 0, 's'},
    {0           , 0                , 0,  0 }
};
```

<b>Example of a command line argument executed: </b>
<p align="center">
  <img src="./img/cmdhelp.PNG" width=650 heigh=500/>
</p>

<i>Figure 2, --help getops command line argument executed</i>

<b>Additional feature: </b>
I have included an additional command line feature which executes when no command line argument is entered. By typing in ```./SHA512```  this executes a prompt which allows the user to pick one of two options.

1. Allows users to enter a string in manually 
2. Allow users to enter a file in manually

<p align="center">
  <img src="./img/cmdselection.PNG" width=650 heigh=500/>
</p>
<i>Figure 3, command line selection feature</i>

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
The purpose of padding is to ensure that the padded message is a multiple of 1024 bits. SHA-512 can’t hash a message input of any size, i.e. it has an input size limit. The entire formatted message has basically three parts: the original message, padding bits and the size of original message. This should all have a combined size of a whole multiple of 1024 bits. This is because the formatted message will be processed as blocks of 1024 bits each, so each bock should have 1024 bits to work with. The end result of padding should be a message in a multiple of 1024 bits.

#### Parsing the message into message blocks (Section 5.2.2)
The message and its padding are parsed into <i>N</i> 1024-bit blocks. Since the 1024 bits of the input block may be expressed as 64-bit words, the first 64 bits <i>i</i> are donated ![equation3](https://latex.codecogs.com/svg.image?M\tfrac{(i)}{0})
, the next 64 bits are to the power of ![equation4](https://latex.codecogs.com/svg.image?M\tfrac{(i)}{0})
 and so on until ![equation5](https://latex.codecogs.com/svg.image?M\tfrac{(i)}{15}).

#### Setting the initial hash value (Section 5.3.5)
The initial hash value ![equation6](https://latex.codecogs.com/svg.image?H^{(0)}) must be initialised. The size and number of words depends on the message digest. For SHA-512 the initial hash value consists of the following eight 64-bit words, in hex. These words were obtained by taking the first 64 bits of the fractional parts of the square roots of the first eight prime numbers.

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

3) Create a for loop initialized from 0 - 79 
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

Simple way of how I checked if my machine is big endian or little endian using Jupyter Notebook: From running this piece of code it specified that my machine is little endian.

``` py
from sys import byteorder
print(byteorder)
``` 

### Testing
I created a simple test bash script to determie does my SHA512 algorithm defined as ```myout``` work correctly when compared to ```expec``` which is assigned the value of ```sha512sum abc```. I also included another test based on an empty file. The output of this program is essentially either a pass or fail. My executed test file is defined below. 

Command for testing: ```make test```:

<p align="center">
  <img src="./img/test.PNG" width=650 heigh=500/>
</p>
<i>Figure 4, Executed bash tests</i>

## Assignment Questions 
<b>Why can't we reverse the SHA512 algorithm to retrieve the original message from a hash digest?</b><br>

Hash algorithms such as the SHA-512 algorithm are most commonly used for security and for detecting if messages have been changed since the digests were generated. They provide encryption using an algorithm and no key and are also known as "one-way hash functions" [A1]. There is no possible way to reverse the encryption hence the reason they are called "hash" algorithms [7], with hash generally meaning "one way". They are designed specifically to take in an input, compute the hash function and output a hashed value as shown in <i> figure 5 </i>. This ensures that every bit of output is dependant upon every bit of the input. It prevents others from splitting the algorithm up and trying to reverse calculate an input from each of the output hash separately.  

<p align="center">
  <img src="./img/diagram.png" width=600 height=250/>
</p>
<i>Figure 5, SHA algorithm diagram</i>
<br></br>


It is unclear whether one-way functions can actually exist. Right now, there are many functions that no one knows how to invert; but this does not mean that they are impossible to invert, in a mathematical sense [11]. The SHA-512 algorithm is designed to make finding the corresponding input to an output extremely dificult. If ones goal is to find an input that generates a given hash, there should be no way to do it that's faster than brute force - trying every input in turn until one works. 

There are two main reasons why the SHA-512 can not be reversed, one being hash functions essentially discard information in a very deterministic way – using the modulo operator. For a quick review, modulus is essentially the same as saying “the remainder of” (applying to division). An example of this would be 16 <i>mod</i> 5 = 1. What’s happening here is that by dividing 16 by 5, the result of the operation is whatever is left over – or the remainder. The modulo operation is not reversible [12]. There are infinite possible number combinations that you could use to get that original input value. 

Another reason is because data is lost after computation. Consider a simple example function 'OR'. If you applied this to an input function of 1 and 0 the solution would be 1. But now having known the answer you cannot revert post solution due to data loss. Instead you are left with three differant possible answers for example (1,1), (0,1) or (1,0). Only brute force could possibly find the correct input variables. The SHA-512 algorithm follows the same idea. Although the SHA-512 is not reversable, it can be cracked using a brute-force method aswell. You can not produce the password from a hash, but you can create hashes of millions of passwords until you find one that matches. For this reason, the hash's strength isn't based so much on the key length of the hashing algorithm, but on the length of the password itself. And because passwords have such low entropy, are predictable, and are often too short, this usually is not a difficult task but a task that would take months or even years to crack [8]. There would be approximately ![equation11](https://latex.codecogs.com/svg.image?2^{512}) posossible input values.

But why is it important for them to not be able to be reversed? The secure hash algorithms such as SHA512 are used in many things such as internet security, digital certificates and even blockchains [10]. Since hashing algorithms play such a vital role in digital security and crytography it is vital that they can not be reversed for security reasons.

<b>Can you design an algorithm that, given enough time, will find input messages that give each of the possible 512-bit strings?</b><br>

Hashing algorithms such as sha512 cannot be reverse computed to their original form as I have detailed above but it would be possible to design an algorithm that could find input messages that gives each possible 512-bit strings. 

Although you can not produce the inputs automatically from a hash, only brute force could possibly produce the final input value, but you could possibly program an algorithm that would be able to find possible input messages of each 512 bit strings. This algorithm would only work given you have enough space and time or even a quantum computer due to the fact that for any given hash there is approximately ![equation12](https://latex.codecogs.com/svg.image?2^{2^{512}}) posossible input values that the algorithm would have to search and output, this would take a tremendous amount of time and power to compute.

Quantum computers are great for solving optimization problems. They could possibly be able to find input messages that give each of the possible 512-bit strings. These computers are designed to crack the most complex of algorithms in little time. On the other hand it would take a normal computer millions of years to compute [15]. 

Another possible problem that could be faced when designing an algorithm of this sort would be hash collisions. A hash collision is essentially two input strings of a hash function that produce the same hash result. Because hash functions have infinite input length and a predefined output length, there is inevitably going to be the possibility of two different inputs that produce the same output hash. If two separate inputs produce the same hash output, it is called a collision. 

The odds of a collision are of course very low, especially so for functions with very large output sizes. However as available computational power increases, the ability to brute force hash collisions becomes more and more feasible [16, 17].

<b>How difficult is it to find a hash digest beginning with at least twelve zeros?</b><br>
Bitcoin mining is designed to find a string <i>s</i> such that the sha512 has <i>n</i> leading zeros, where <i>n</i> determines the mining difficulty [13]. The probability of calculating a hash that starts with many zeros is very low, therefore many attemps must be made. Difficulty is a value used to show how hard is it to find a hash that will be lower than a specific target defined by system, for example a hash with twelve leading zeros. Imagine a hash is only three digits long. If there is no leading zero ("999") then there are a thousand possible numbers (0-999) that are lower than that specific hash. If there is one leading zero ("099"), there are now only one hundred possible numbers lower than that hash value. The same idea relates to a hash with twelve leading zeros. The more leading zeros a value has, the longer and more difficult it will be to find, aswell as the additional computing power it will acquire. As a result there would be around ![equation13](https://latex.codecogs.com/svg.image?2^{48}) values that would have a hash with 12 leading zeros. The Bitcoin network has a global block difficulty. The mining difficulty formula is defined below.

```difficulty = difficulty_1_target / current_target```

The difficulty of finding a bitcoin with twelve leading zeros would be a 13 trillion mining difficulty. Today, Bitcoin miners are looking for an output greater than twelve leading zeros. Miners have to find a hash which starts with nineteen zeroes which is a difficulty level of 23.1 trillion. To get this number requires many, many attempts. Once the hash is found, the block is closed and it is added to the blockchain. After successfully mining a block, miners are rewarded with newly-created Bitcoins and transaction fees [14]. 

What are the benefits of Cryptocurrency difficulty? Satoshi Nakamoto explains how the proof-of-work difficulty helps to generate a steady production of new blocks added to the blockchain. <i>"To compensate for increasing hardware speed and varying interest in running nodes over time, the proof-of-work difficulty is determined by a moving average targeting an average number of blocks per hour. If they're generated too fast, the difficulty increases" </i> [A2]. This method is to endure fair game amongst bitcoin miners.

Difficulty rates are also important for network security. The higher the cryptocurrency difficulty, the more guesses or hashes are needed to reach the target hash requirement. As a result, this process makes it very difficult and expensive for attackers to gain the majority control and in turn prevents malicious attacks. 

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
[9] The C Programming Language, Brian W.Kernighan, Dennis M. Ritchie,
http://117.3.71.125:8080/dspace/bitstream/DHKTDN/6554/1/The%20C%20Programming%20Language4603.pdf <br>
[10] Medium, Cryptography: Explaining SHA-512, <br>
https://medium.com/@zaid960928/cryptography-explaining-sha-512-ad896365a0c1#:~:text=SHA%2D512%20is%20a%20hashing <br>
[11] StackExchange, Why are hash functions one way, <br>
https://security.stackexchange.com/questions/11717/why-are-hash-functions-one-way-if-i-know-the-algorithm-why-cant-i-calculate-t <br>
[12] Private Canada, Why Are Hashes Irreversible?, <br>
https://privacycanada.net/hash-functions/why-are-hashes-irreversible/ <br>
[13] StackExchange, Mining Difficulty and Leading Zeros, <br>
https://bitcoin.stackexchange.com/questions/85896/mining-difficulty-and-leading-zeros <br>
[14] Luno, Bitcoin’s hash rate is hitting record highs, but does it even matter?, <br>
https://www.luno.com/blog/en/post/bitcoins-hash-rate-is-hitting-record-highs-but-does-it-even-matter <br>
[15] GeeksforGeeks, Introduction to quantum computing, <br>
https://www.geeksforgeeks.org/introduction-quantum-computing/ <br>
[16] Privacy Canada, Hash Collision Attack, <br>
https://privacycanada.net/hash-functions/hash-collision-attack/ <br>
[17] ScienceDirect, Hash Collision, <br>
https://www.sciencedirect.com/topics/computer-science/hash-collision <br>

## Google Scholar Referances
[A1] Sumagita, M., Riadi, I., Sh, J.P.D.S. and Warungboto, U., 2018. Analysis of secure hash algorithm (SHA) 512 for encryption process on web based application. International Journal of Cyber-Security and Digital Forensics (IJCSDF), 7(4), pp.373-381. <br>

[A2] Nakamoto, S., 2019. Bitcoin: A peer-to-peer electronic cash system. Manubot.


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
- [Running the Tests](#running-the-tests)
- [Project Implementation](#project-implementation)
- [Command Line Arguments](#command-line-arguments)
- [Testing](#testing)
- [Assignment Questions](#assignment-questions)
- [Referances](#referances)

## Repository Description
This repository contains the C code to compute the SHA512 algorithm based on an input file. The result of the program is a SHA512 message digest. This program also incorporates error handling, a make file, command line arguments and testing.

- Final image of project output will go here

```bash
├── img # Folders contains images discussed in README.md
│   ├──  # logo.jpeg
│   └──  # constants.PNG
│   └──  # functions.PNG
│   └──  # diagram.png
├── screencasts # Folder containing screencasts of how to set-up, deploy and run project
│   ├── # Screencast 1
|   └── # Screencast 2
├── .gitignore # Text file listing files to ignore
├── README.md # Full overview of project
├── argc.c # getops from labs - to help me incorporate into sha512
├── sha512.c # SHA512 algorithm coded using C programming language
├── test.c # Relevant testing of the SHA512 algorithm
├── input.txt # Input file
├── test.txt # Large input file


```

## SHA512 Overview
There are numerous secure hash algorithms such as the SHA-1, SHA-224, SHA-256, SHA-384, SHA-512, SHA-512/224 and SHA-512/256. These are used for computation of condensed representation of electronic data. When a message of any length  less than ![equation1](https://latex.codecogs.com/gif.latex?2%5E%7B64%7D) bits (for SHA-1, SHA-224 and SHA-256) or less than ![equation2](https://latex.codecogs.com/gif.latex?2%5E%7B128%7D) bits (for SHA-384, SHA-512, SHA-512/224 and SHA-512/256) is input to a hash algorithm. The result is a specific output also known as a message digest which is essentially a compact representation of the binary data recieved as input [8]. These digests range in length from 160 to 512 bits, depending on the algorithm.

The hash algorithms have secure in their name because, for a given algorithm, it is computationally infeasible to find a message that corresponds to a given message digest or to find two different messages that produce the same message digest. Any change at all to a message will give a different result.

The SHA512 algorithm is part of a set of crytographic hash functions designed by the United States National Security (NSA) and published in 2001 [4]. The SHA512 is a hashing algorithm that performs a hashing function on given data such as an input file for this project [6].

Hashing algorithms are primarily used to provide integrity [7].

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
3. Compile the program: ```make sha512```<br>
4. Execute the program: ```./sha512 input.txt```<br>

- Add screencasts to explain how to run & code snippets

## Running the Tests
1. Compile the tests: ```make test```<br>

## Project Implementation
### Creating the SHA512 functions
SHA512 uses six logical functions, where each function operates on 64-bit words, which are represented as x, y, and z. The result of each function is a new 64-bit word. The SHA512 functions are defined below as well as in section 4.1.3 of the Secure Hash Standard. <i>Figure 1</i> gives the corresponding c code for these functions. 

<p align="center">
  <img src="./img/functions.PNG" width=500 height=320/>
</p>
<i>Figure 1. Code implementation of the Secure Hash Algorithm</i>

### Declare SHA512 Constants
Declare a specific sequence of eighty constant 64-bit words. These words represent the first sixty-four bits of the fractional parts of the cube roots of the eighty prime numbers. These constants are defined in section 4.2.3 of the Secure Hash Standard. <i>Figure 2</i> demonstrated how I included these constants in my program.

<p align="center">
  <img src="./img/constants.PNG" width=550 height=400/>
</p>
<i>Figure 2. Code implementation of the Secure Hash Algorithm constants</i>

### Preprocessing - 1) Padding the message
Ensuring the message is a multiple of 1024 bits. The end of the padded message is a multiple of 1024 bits.  

<b>Code snippet goes here</b>

### Preprocessing - 2) Parsing the message into message blocks
The message and its padding are parsed into <i>N</i> 1024-bit blocks. Since the 1024 bits of the input block may be expressed as 64-bit words, the first 64 bits <i>i</i> are donated <i>M</i> to the power of <i>0(i)</i>, the next 64 bits are to the power of <i>1(i)</i> and so on until <i>15(i)</i>.

<b>Code snippet goes here</b>

### Preprocessing - 3) Setting the initial hash value
The initial hash value <i>H(0)</i> must be set. The size and number of words depends on the message digest. For SHA512 the initial hash value consists of the following eight 64-bit words, in hex. These words were obtained by taking the first 64 bits of the fractional parts of the square roots of the first eight prime numbers.

<b>Code snippet goes here</b>

### Hash Computation

<b>Code snippet goes here</b>

### Solving Big-Endian
Big endian stores the most significant byte in the smallest address. An example of this can be seen in the table below.

Address  | Value
-------- | ------
1000     | 12
1001     | 34
1002     | 56
1003     | 78 


<b>Code snippet goes here</b>

## Command Line Arguments

## Assignment Questions 
<b>Why can't we reverse the SHA512 algorithm to retrieve the original message from a hash digest?</b><br>

Hash algorithms are most commonly used for security. They provide encription using an algorithm and no key and are also known as "one-way hash functions" because there is no possible way to reverse an encription [7]. They are designed specifically to take in an input, compute the hash function and output a hashed value as shown in <i> figure ... </i>. This ensures that every bit of output is dependant upon every bit of the input. It prevents others from splitting the algorithm up and trying to reverse calculate an input from each of the output hash separately.  

<p align="center">
  <img src="./img/diagram.png" width=600 height=250/>
</p>
<i>Figure .... SHA algorithm diagram</i>

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
[5] IBM Developer; Writing endian-independent code in C <br>
https://developer.ibm.com/technologies/systems/articles/au-endianc <br>
[6] Medium, Cryptography: Explaining SHA-512 <br>
https://medium.com/@zaid960928/cryptography-explaining-sha-512-ad896365a0c1 <br>
[7] ScienceDirect, Message Digest <br>
https://www.sciencedirect.com/topics/computer-science/message-digest <br>
[8] ScienceDirect, Hashing Algorithm <br>
https://www.sciencedirect.com/topics/computer-science/hashing-algorithm <br>


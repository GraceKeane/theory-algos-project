<h2 align="center">
    SHA512 Calculator
</h3>

<h3 align="center">
    A program written in C that calculates the SHA512 of an input
</h4>

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
- [Repository Contents](#repository-contents)
- [SHA512 Overview](#sha512-overview)
- [Software Requirements](#software-requirements)
- [Command Line Installations](#command-line-installations)
- [Running the Program](#running-the-program)
- [Project Implementation](#project-implementation)
- [Assignment Questions](#assignment-questions)
- [Referances](#referances)

## Repository Description 
Description of your repository and its contents pitched at a knowledgeable outsider.

## Repository Contents

```bash
├── Images # Folders contains images discussed in README.md
│   ├──  # Image 1
│   └──  # Image 2
├── Screencasts # Folder containing screencasts of how to set-up, deploy and run project
│   ├── # Screencast 1
│   ├── # Screencast 2
│   └── # Screencast 3
├── .gitignore # Text file listing files to ignore
├── README.md # Full overview of project
├── argc.c # File containing C code for testing lab exercices)
├── bitoperations.c # File containing C code from lab exercices)
├── SHA512.c # SHA512 algorithm coded using C programming language
├── Test.c # Relevant testing of the SHA512 algorithm


```

## SHA512 Overview
Explain & why is it important?

The SHA512 is part of a set of crytographic hash functions designed by the United States National Security (NSA) an published in 2001 [4]. The SHA512 is a hashing algorithm that performs a hashing function on given data. The algorithm needs certain variables in order for the algorithm to be solved.
1) A message schedule of eighty 64-bit words
2) Eight working variables of 64 bits each
3) A hash value of eight 64-bit words

The final result of the SHA512  algorithm is a 512-bit message digest [3].

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
2. Navigate to the <b> \program\ </b> directory: ```cd program```<br>
3. Compile the program: ```make bitoperations```<br>
4. Execute the program: ```./bitoperations```<br>

- Add screencasts to explain how to run & code snippets

## Project Implementation
- Add code snippets & explain how my code works

## Assignment Questions 
<b>Why can't we reverse the SHA512 algorithm to retrieve the original message from a hash digest?</b><br>

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


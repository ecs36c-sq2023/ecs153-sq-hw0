# Homework 0

> Due: 05-02-2023 11:59:59 PM

The goal of this homework is for you to

- setup and get familiarized with the development environment, build tools, and
  homework submission process;
- review C basics by implementing a parser calculator.
- get familar with C pointers

## Table of Contents

1. [Homework Spec](#homework-spec)
2. [Setup Dev Env & Run/Debug Your Program](#setup-dev-env--rundebug-your-program)
3. [CMakeFiles](#cmakefiles)
4. [Submission](#submission)

## Homework Spec

### Introduction

In this assignment, you will develop a C program that can calculate mathematical expressions provided as input strings. The program will support 

- Basic arithmetic operations: addition (`+`), subtraction (`-`), multiplication (`*`), division (`/`),  mod(`mod()`), and square (`square()`). 
- Scientific operations: sinOfDegree(`sinOfDegree`) and cosOfDegree(`cosOfDegree`)
- Self-defined function: getIntPart(`getIntPart`), getDecimalPart(`getDecimalPart`), getXdigit(`getXdigit`), sumFibonacci(`sumFibonacci`), sumIntPart(`sumIntPart`), sumDecimalPart(`sumDecimalPart`), crossMultiply(`crossMultiply`), and factorial(`factorial`).

The expressions may include nagtive number and floating-point numbers and will follow the standard mathematical rules for order of operations, including handling of parentheses. The primary goal of this assignment is to enhance your understanding of string manipulation, control flow, recursion, and the implementation of algorithms in C.

### File description

- calculator (`calculator.h/calculator.c`): 
  - Defines the `MAX_EXPRESSION_LENGTH, MAX_FUNC_LEN, MAX_STACK`
    - `MAX_EXPRESSION_LENGTH`: maximum length of input string.
    - `MAX_FUNC_LEN`: maximum length of expression.
    - `MAX_STACK`: maximum number of operations and digits in the input.

  - You need to implement the struct `Calculator`you will be use in parsing the string and do the calculation. 
  - Function `parseExpression` will take the pointer of struct `Calculator` as input and return the correct result.
  - Function `init_calculator` and `free_Calculator` are used to initilize your structure and clean up.
- `basic.h`/`basic.c` includes basic arithmetic operations.
- `scientific.h`/`scientific.c` includes sinOfDegree(`sinOfDegree`) and cosOfDegree(`cosOfDegree`).
- `fun.h`/`fun.c` includes Self-defined function: getIntPart(`getIntPart`), getDecimalPart(`getDecimalPart`), getXdigit(`getXdigit`), sumFibonacci(`sumFibonacci`), sumIntPart(`sumIntPart`), sumDecimalPart(`sumDecimalPart`), crossMultiply(`crossMultiply`), and factorial(`factorial`).
- We are using `gtest` for grading and testing your program, and we have provided two testcases as example in `/src/tests/AutograderTests.cpp`.
  - Note. those example will NOT be used for grading.

- **All operation expression inside the function will be quoted by the parentheses.** e.g. `sinOfDegree((1+2))` where expression`(1+2)` will be quoted by the parentheses.
- All function are defined in header file, including descriptions input and return type, please refer to the comment.
- `CMakeLists.txt` will compile the whole project. 

### Input and Output specifications

- Input
  - The program must accept a single string. 
  - The input string will represent a mathematical expression containing integers, floating-point numbers, negative number parentheses and the operators/functions mentioned above.
  - The input may contain extra spaces.
- Output
  - The program should only output the result of the mathematical expression to the standard output.
  - The grading will match the answer with your result in a precision of up to three decimal places.


### Programming guide

It's not a must, but its recommended that you follow this guide.

Implement `calculator`and`basic` first.

You will get 20% if you can do basic calculation.

You will get 20% more if you can handle calculation with brackets.

When you're finished with `basic`, you can move on to the more complicated `scientific` and `fun`.  Remember that some function has two parameters and some has only one parameter. The input may contain extra spaces, which you should remove. 

You will get 25% more if you get everything right in `scientific`.

You will get 25% more if you get everything right in `fun`.

Last 10% will test all operations.

#### Function defination

All function are defined in header file, including descriptions input and return type, please refer to the comment.

#### [Unit testing](https://en.wikipedia.org/wiki/Unit_testing)

We use unit testing to do grading in this homework.
You are also encouraged to write your own unit testing to see if your code works.

The framework we use is [GoogleTest](http://google.github.io/googletest/primer.html).
GoogleTest is a C++ testing framework, but it also works in C, mostly. 
("mostly" contains too many corner cases where it is not the case. I don't want to go into that, you can [read it](https://en.wikipedia.org/wiki/Compatibility_of_C_and_C%2B%2B) yourself, but for our use case GoogleTest is good enough)
Don't panic.
I have already taken care of the C++ part.

To write a test, you only need to:

```cpp
TEST(<TestGroup>, <TestName>) {
    // Your test code.
    int my_result = 1;

    // The following command to test if you code is running correctly
    EXPECT_EQ(my_result, 1);
    EXPECT_TRUE(my_result == 1);

    // ASSERT halt program immediately on error. That means you won't have a change to clean up the memory, leak sanitizer may not be too happy about it.
    ASSERT_EQ(my_result, 1);

    // Remember to clean up your memory!
}
```

GoogleTest will compile all your tests into one single binary executable.
In this homework, it is `CalculatorTests`.
Running `CalculatorTests` will execute all tests you have.
You can also use filters to run only a handful of tests:

```sh
./CalculatorTests --gtest_filter=<regex>
```

GoogleTest will find names whose name matchs the [regular expression](https://en.wikipedia.org/wiki/Regular_expression) you provided.

As a result, this homework doesn't have example input and output as well. I wrote some unit tests for you, but that's it. You should come up with your own unit tests, and pass them before submitting.

#### Compile guide

- Make a build directory and go to it `mkdir build && cd build`
- You can ask `CMake` to generate a `Makefile` that copmiles: `cmake -DCMAKE_BUILD_TYPE=asan ..`
- Compile the project `cmake --build .` 
- There will be a `CalculatorTests`, you can run it to test your code.
- You are encouraged to write more testcases to test your code before submit to the gradescope.

### Requirements

- For C and header files, you SHOULD NOT modify any code unless you see `/* Your code here ... */` or something similar. Specifically, you SHOULD NOT modify:
  - Any function declarations.
  - Any `#include`, the files have enough `#include` to write the code. Even if `main.c` doesn't include any struct definitions.
- You may modify `CMakeLists.txt` as you wish.
  - Try not to change compiler settings, but you can modify it for debuggin purposes.
  - You should remove the files you didn't finish to avoid a compiler failure.

### Submitting your Homework

- Run `./generate_submission.sh` to create a zip file `hw0-submission.zip`.
- Transfer `hw0-submission.zip` to your host (if necessary).
  - If you are in VS Code with Dev Container / Remote SSH / WSL2, you can right
    click on `hw0-submission.zip` and click `Download`.
  - If you are using a terminal, you can use `scp` or `sftp`.
- Submit `hw0-submission.zip` on Gradescope.

## Setup Dev Env & Run/Debug Your Program

Use one of the following options to setup your environment.

> ⚠️ If you're a student, **DO NOT FORK** this repository because you cannot
> change the visibility of a forked repo to private. If you plan to use Git for
> version control (which is encouraged), run `rm -rf .git && git init` after
> setting up using one of the options below and push to your **private**
> repository. Any public repository containing part of this homework solution
> will be reported to SJA.

### Option 1: VS Code with Local Dev Container

> This option provides a Graphical User Interface (GUI) for code editing and
> debugging.

> This option does not require internet connection when coding after initial
> setup.

- Install/update the following software on your local OS:

  - [WSL2](https://learn.microsoft.com/en-us/windows/wsl/install) (Required for
    Windows only) (Docker will use WSL2 as backend on Windows)
  - [Docker Desktop](https://www.docker.com/products/docker-desktop/)
    - Make sure you install the correct version based on your hardware
      (especially for Apple-chip powered Macbook and ARM-based Windows PC)
  - [Visual Studio Code](https://code.visualstudio.com/)

- Start Docker Desktop and keep it running in the background.

- Click the following button to setup the environment.


​	[![Setup Local Dev Container](https://img.shields.io/static/v1?label=Local%20Dev%20Container&message=Setup&color=blue&logo=visualstudiocode)](https://vscode.dev/redirect?url=vscode://ms-vscode-remote.remote-containers/cloneInVolume?url=https://github.com/ecs36c-sq2023/ECS153-sq-hw0)

- When asked for selecting a Kit to configure CMake, choose **GCC**.

- Click **Run -> Start Debugging** to run the program.

  - project is automatically (re)built (no need to run `make` or `cmake`
    initially or after making code modifications).
  - you can supply command line args in `.vscode/launch.json` through `args`
    array.
  - you may set breakpoints by hovering over the left of each line number and
    click the red dot.

### Option 2: VS Code with CSIF

> This option provides a Graphical User Interface (GUI) for code editing and
> debugging.

> Connecting to CSIF computer may require UC Davis Library VPN.

- Install/update the following software on your local OS:

  - [Visial Studio Code](https://code.visualstudio.com/)
  - [Remote SSH Extension](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-ssh)

- Open **VS Code**

- Click the little green button in the bottom-left corner of the window to open
  **Remote - SSH** extension

- Click **Remote-SSH: Connect to Host...**

- Select **csif** if you configured
  [Passwordless Login to CSIF](https://github.com/HazyFish/ucdavis-csif-passwordless)

  - If not, in the textbox prompted, enter `username@pcXX.cs.ucdavis.edu` (you
    need to replace `username` and `XX`), press **enter**, and then enter your
    password for CSIF

- Wait for VS Code to install VS Code Server on CSIF automatically

  - VS Code Server will be installed in `/home/<username>/.vscode-server` so
    other users don't have access to it
  - Retry if you get any error

- Install **C/C++ Extension Pack** (on Remote Server)

- Open an integrated terminal inside VS Code (**Terminal Menu** -> **New
  Terminal**)

  - Notice that this terminal is already connected to the CSIF

- Run the following command inside the integrated terminal

  `git clone https://github.com/ecs36c-sq2023/ECS153-hw0 ECS153-hw0`

- Run `code ./ECS153-hw0` to open the folder

- When prompted to configure CMake, confirm and choose **GCC** when prompted for
  kit selection.

- Click **Run -> Start Debugging** to run the program.

  - project is automatically (re)built (no need to run `make` or `cmake`
    initially or after making code modifications).
  - you can supply command line args in `.vscode/launch.json` through `args`
    array.
  - you may set breakpoints by hovering over the left of each line number and
    click the red dot.

### Option 3: Terminal with CSIF

> This option works but you will have to use print statements or command-line
> `gdb` for debugging. It is recommended that you try one of the other options
> to have more efficient, developer-friendly way of debugging.

> Connecting to CSIF computer may require UC Davis Library VPN.

- SSH into a CSIF computer

- Run the following commands

  ```bash
  git clone https://github.com/ecs36c-sq2023/ECS153-hw0 ECS153-hw0
  cd ./ECS153-hw0/src
  mkdir build
  cd build
  cmake ..
  make
  ```

- To rebuild after code modification, run `make` in `build` folder.

- To run the program, run `./main [INPUT_FILE] [OUTPUT_FILE]` in `build` folder.

### Other Options

You could use other options such as running it directly on your macOS or WSL2,
but you'll be responsible for having the correct build tools and making sure
your submission works on Gradescope.


## CSIF Docs

Information about using CSIF computers, such as how to remotely login to CSIF
computers from home and how to copy files to/from the CSIF computers using your
personal computer, can be found at
[http://csifdocs.cs.ucdavis.edu/about-us](http://csifdocs.cs.ucdavis.edu/about-us)
csif-general-faq.

# Submission

To submit your homework, you need to run `./generate_submission.sh` to generate a zip file. Make sure that the zip you got contains your code in it.
Then submit it to gradescope.

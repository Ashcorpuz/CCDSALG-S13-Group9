# CCDSALG-S13-Group9
This project contains source code for CCDSALG project, all organized within the src/ directory

#Prerequisites
Before running the project, ensure you have the necessary tool installed on your machine:
## GCC Compiler:
Required for compiling C programs. Available default on most Linux distributions and macOS. Windows users may need to install MinGW or Cygwin.
## Make:
A build utility that simplifies the compilation process. It is highly recommended for automating the build process.
### Installing Make:
#### Windows:
To install make, you can use choco. Open command prompt as Administrator and run:
choco install make -y

or download directly [here](https://gnuwin32.sourceforge.net/packages/make.htm)

#### macOS/Linux: 
You may visit [Stack Overflow](https://stackoverflow.com/) or [Youtube](https://youtube.com) on how to install make in your OS.

I recommend using make since you can configure it to automatically compile all C files, check Makefile file 

## How to run
### Using Make
Ensure make is installed, this method is preferred for its simplicity and efficiency.
Compile and run the project by navigating to the project's root directory and execute: make

^ This command reads the Makefile to compile all C files and generates the executable.
MC01

### Without Make

PRECEDENCE OF OPERATORS 
If you don't have make or prefer manual compilation, make sure you have gcc installed
gcc -g -Wall -c src/evaluate-postfix.c -o obj/evaluate-postfix.o && gcc -g






| Operators | Priority |
|:---------:|:--------:|
| ^ | 1 |
| * and / | 2 |
| + and - | 3 |

Infix Notation: 
- The operators are written in between their operands

Postfix Notation:
- The operaetors are written after their operands.
- The order of evaluation of operation is left to write with no brackets in the expression to change the order

Using Stack to convert infix to postfix 

Algorithm
Scan symbol from left to right and for each symbol, do the following:
- If sysmbol is an operand:
-- Print Symbol on to screen
- If symbol is a left parenthesis
-- Push it on the stack
- If symbol is a right parenthesis
-- Pop all the operators from the stack upto the first left parenthesis, and print on the screen
-- Discard left and right parenthesis
- If symbol is an operator 
-- If the precederence of the operator in the stack are greater than or equal to the current oprator, then pop the operator out of the stack and print them of the screen and push the current operator on to the stack
-- else push the current operator on to the stack

7+5*3/5^1+(3-2)
Output: 	753*51^/+32-+

8*(5^4+2)-6^2/(9*3)
Output:		8542+^*62^93*/-

Evalutating Postfix expression
Scan the symbols of the given postfix expression from left to right and for each symbol, do the following:
- If symbol is an operand
-- Push it on the stack.
- If symbol is an operator
-- Pop two symbols out of the stack and apply the operator on these symbols.
-- Push the result on the stack
- After scanning all the symbols of the postfix expression, pop the remaining symbol out of the stack and print it on the screen. The remaining symbol is the result obtained after evaluating the postfix expression.

i# Monty Bytecode Interpreter
  Interpretes and executes opcodes from a monty bytecode file.

## Usage
   To compile, run:
   `gcc -Wall -Werror -Wextra -pedantic *.c -o monty`
   
   To run the program:
   `./monty <bytecode_file>`

## Accepted opcodes
   | Opcode | File                                                                        | Description                                              |
   | ------ | --------------------------------------------------------------------------- | -------------------------------------------------------- |
   | push   | [0-push_pall.c](https://github.com/awinabaab/monty/blob/main/0-push_pall.c) | Pushes an element to the stack                           |
   | pall   | [0-push_pall.c](https://github.com/awinabaab/monty/blob/main/0-push_pall.c) | Prints all the values on the stack starting from the top |
   | pint   | [1-pint.c](https://github.com/awinabaab/monty/blob/main/1-pint.c)           | Prints the value at the top of the stack                 |
   | pop    | [2-pop.c](https://github.com/awinabaab/monty/blob/main/2-pop.c)             | Removes the top element of the stack                     |
   | swap   | [3-swap.c](https://github.com/awinabaab/monty/blob/main/3-swap.c)           | Swaps the top two elements of the stack                  |
   | add    | [4-add.c](https://github.com/awinabaab/monty/blob/main/4-add.c)             | Adds the top two elements of the stack. The result is stored in the second top element and the top element is removed                   |
   | nop    | [5-nop.c](https://github.com/awinabaab/monty/blob/main/5-nop.c)             | Does nothing                                             |
   | sub    | [6-sub.c](https://github.com/awinabaab/monty/blob/main/6-sub.c)             | Subtracts the top element of the stack from the second top element of the stack. The result is stored in the second top element and the top element is removed                 |
   | div    | [7-div.c](https://github.com/awinabaab/monty/blob/main/7-div.c)             | Divides the second top element of the stack by the top element of the stack. The result is stored in the second top element and the top element is removed                 |
   | mul    | [8-mul.c](https://github.com/awinabaab/monty/blob/main/8-mul.c)             | Multiplies the second top element of the stack with the top element of the stack. The result is stored in the second top element and the top element is removed                 |
   | mod    | [9-mod.c](https://github.com/awinabaab/monty/blob/main/9-mod.c)             | Computes the modulo division of the second top element of the stack by the top element of the stack. The result is stored in the second top element and the top element is removed                 |
   | pchar  | [11-pchar.c](https://github.com/awinabaab/monty/blob/main/11-pchar.c)       | Prints the ASCII equivalent of the integer at the top of the stack |
   | pstr   | [12-pstr.c](https://github.com/awinabaab/monty/blob/main/12-pstr.c)         | Prints the ASCII equivalent of the integer in each element of the stack followed by a new line |
   | rotl   | [13-rotl.c](https://github.com/awinabaab/monty/blob/main/13-rotl.c)         | Rotates the stack to the top. The top element becomes the last one and the second top element becomes the first one |
   | rotr   | [14-rotr.c](https://github.com/awinabaab/monty/blob/main/14-rotr.c)         | Rotates the stack to the bottom. The last element of the stack becomes the top element of the stack |
   | stack  | [15-set_mode.c](https://github.com/awinabaab/monty/blob/main/15-set_mode.c) | Sets the format of the data structure to a stack (LIFO). This is the default behaviour of the program |
   | queue  | [15-set_mode.c](https://github.com/awinabaab/monty/blob/main/15-set_mode.c) | Sets the format of the data structure to a queue (FIFO) |

   :warning: ==Note: When the first non-space character of a line is `#`, it is treated as a comment.==
   :warning: ==Note: `push` is the only opcode that expects an argument. The argument must be an integer.==

## Sample Bytecode
   ``
   push 1
   push 2
   push 3
   pall
   ```
   
## C - Stacks, Queues - LIFO, FIFO
   - What do LIFO and FIFO mean
   - What is a stack, and when to use it
   - What is a queue, and when to use it
   - What are the common implementations of stacks and queues
   - What are the most common use cases of stacks and queues
   - What is the proper way to use global variables
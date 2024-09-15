# queue_using_two_stack_hackerrank_c

This is a C program implementing a queue using two stacks. Here's a breakdown of the code:

Includes and definitions

- The program includes the standard input/output (stdio.h) and standard library (stdlib.h) headers.
- It defines a constant MAX_SIZE with a value of 100000, which represents the maximum size of the stacks.
- It defines a struct Stack with two members: an array data of size MAX_SIZE to store the stack elements, and an integer top to keep track of the top element's index.

Stack functions

- init_stack(Stack *stack): Initializes a stack by setting its top index to -1.
- is_empty(Stack *stack): Returns 1 if the stack is empty (i.e., top is -1), 0 otherwise.
- is_full(Stack *stack): Returns 1 if the stack is full (i.e., top is MAX_SIZE - 1), 0 otherwise.
- push(Stack *stack, int value): Pushes an element onto the stack if it's not full. If the stack is full, it prints an error message.
- pop(Stack *stack): Pops an element from the stack if it's not empty. If the stack is empty, it prints an error message and exits the program.
- peek(Stack *stack): Returns the top element of the stack if it's not empty. If the stack is empty, it prints an error message and exits the program.
- transfer(Stack *src, Stack *dest): Transfers all elements from the source stack to the destination stack.

Main function

- The program uses two stacks, stack_in and stack_out, to implement a queue.
- It reads the number of queries from the user and processes each query in a loop.
- There are three types of queries:
    - Query type 1: Enqueue operation. Reads an integer value and pushes it onto stack_in.
    - Query type 2: Dequeue operation. If stack_out is empty, it transfers all elements from stack_in to stack_out. Then, it pops an element from stack_out.
    - Query type 3: Print front of the queue. If stack_out is empty, it transfers all elements from stack_in to stack_out. Then, it prints the top element of stack_out.

The program uses the two stacks to implement a queue, where stack_in is used for enqueue operations and stack_out is used for dequeue and peek operations. The transfer function is used to move elements from stack_in to stack_out when necessary.

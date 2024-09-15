#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100000

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

void init_stack(Stack *stack) {
    stack->top = -1;
}

int is_empty(Stack *stack) {
    return stack->top == -1;
}

int is_full(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(Stack *stack, int value) {
    if (is_full(stack)) {
        printf("Stack overflow\n");
        return;
    }
    stack->data[++(stack->top)] = value;
}

int pop(Stack *stack) {
    if (is_empty(stack)) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->data[(stack->top)--];
}

int peek(Stack *stack) {
    if (is_empty(stack)) {
        printf("Stack is empty\n");
        exit(EXIT_FAILURE);
    }
    return stack->data[stack->top];
}

void transfer(Stack *src, Stack *dest) {
    while (!is_empty(src)) {
        push(dest, pop(src));
    }
}

int main() {
    Stack stack_in, stack_out;
    init_stack(&stack_in);
    init_stack(&stack_out);

    int queries;
    scanf("%d", &queries);

    while (queries--) {
        int query_type;
        scanf("%d", &query_type);

        if (query_type == 1) {
            // Enqueue operation
            int value;
            scanf("%d", &value);
            push(&stack_in, value);
        } else if (query_type == 2) {
            // Dequeue operation
            if (is_empty(&stack_out)) {
                transfer(&stack_in, &stack_out);
            }
            pop(&stack_out);
        } else if (query_type == 3) {
            // Print front of the queue
            if (is_empty(&stack_out)) {
                transfer(&stack_in, &stack_out);
            }
            printf("%d\n", peek(&stack_out));
        }
    }

    return 0;
}
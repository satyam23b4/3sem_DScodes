#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack *s) {
    s->top = -1;
}

void push(Stack *s, int value) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    s->items[++(s->top)] = value;
}

int pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return s->items[(s->top)--];
}

int is_operator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int evaluate_prefix(char prefix[]) {
    Stack operands;
    initialize(&operands);

    int i;
    int len = strlen(prefix);

    for (i = len - 1; i >= 0; i--) {
        if (prefix[i] == ' ' || prefix[i] == '\t') {
            continue;
        }

        if (is_operator(prefix[i])) {
            int operand1 = pop(&operands);
            int operand2 = pop(&operands);

            switch (prefix[i]) {
                case '+':
                    push(&operands, operand1 + operand2);
                    break;
                case '-':
                    push(&operands, operand1 - operand2);
                    break;
                case '*':
                    push(&operands, operand1 * operand2);
                    break;
                case '/':
                    push(&operands, operand1 / operand2);
                    break;
            }
        } else {
            int operand = prefix[i] - '0';
            push(&operands, operand);
        }
    }

    return pop(&operands);
}

int main() {
    char prefix[MAX_SIZE];

    printf("Enter a prefix expression: ");
    gets(prefix);

    int result = evaluate_prefix(prefix);

    printf("Result: %d\n", result);

    return 0;
}

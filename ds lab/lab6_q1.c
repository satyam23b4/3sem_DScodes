#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char items[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack *s) {
    s->top = -1;
}

void push(Stack *s, char c) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    s->items[++(s->top)] = c;
}

char pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return s->items[(s->top)--];
}

int is_operator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int precedence(char operator) {
    if (operator == '+' || operator == '-') {
        return 1;
    } else if (operator == '*' || operator == '/') {
        return 2;
    }
    return 0;
}

void infix_to_prefix(char infix[], char prefix[]) {
    Stack operators, result;
    initialize(&operators);
    initialize(&result);

    int i, j = 0;
    int len = strlen(infix);

    for (i = len - 1; i >= 0; i--) {
        if (infix[i] == ' ' || infix[i] == '\t') {
            continue;
        }

        if (is_operator(infix[i])) {
            while (operators.top != -1 && precedence(operators.items[operators.top]) > precedence(infix[i])) {
                prefix[j++] = pop(&operators);
            }
            push(&operators, infix[i]);
        } else if (infix[i] == ')') {
            push(&operators, infix[i]);
        } else if (infix[i] == '(') {
            while (operators.items[operators.top] != ')') {
                prefix[j++] = pop(&operators);
            }
            pop(&operators); // Discard the ')'
        } else {
            prefix[j++] = infix[i];
        }
    }

    while (operators.top != -1) {
        prefix[j++] = pop(&operators);
    }

    prefix[j] = '\0';

    // Reverse the prefix expression
    int start = 0, end = j - 1;
    while (start < end) {
        char temp = prefix[start];
        prefix[start] = prefix[end];
        prefix[end] = temp;
        start++;
        end--;
    }
}

int main() {
    char infix[MAX_SIZE];
    char prefix[MAX_SIZE];

    printf("Enter an infix expression: ");
    gets(infix);

    infix_to_prefix(infix, prefix);

    printf("Equivalent prefix expression: %s\n", prefix);

    return 0;
}

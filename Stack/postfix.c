#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_SIZE 100

// Stack structure definition
typedef struct Stack {
    char items[MAX_SIZE];
    int top;
} stack;

// Function prototypes
void initialize(stack* stack);
int isEmpty(stack* stack);
int isFull(stack* stack);
void push(stack* stack, char value);
char pop(stack* stack);
char peek(stack* stack);
int precedence(char operator);
void infixToPostfix(const char* infixExpression, char* postfixExpression);
int evaluatePostfix(const char* postfixExpression);

int main() {
    char infixExpression[MAX_SIZE];
    char postfixExpression[MAX_SIZE];

    // Get infix expression from the user
    printf("Enter the infix expression: ");
    scanf("%s", infixExpression);

    // Convert infix to postfix
    infixToPostfix(infixExpression, postfixExpression);
    printf("Postfix expression: %s\n", postfixExpression);

    // Evaluate the postfix expression
    int result = evaluatePostfix(postfixExpression);
    printf("Result: %d\n", result);

    return 0;
}

// Initialize the stack
void initialize(stack* stack) {
    stack->top = -1;
}

// Check if the stack is empty
int isEmpty(stack* stack) {
    return stack->top == -1;
}

// Check if the stack is full
int isFull(stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// Push an element onto the stack
void push(stack* stack, char value) {
    if (isFull(stack)) {
        printf("Stack Overflow. Cannot push %c\n", value);
        exit(EXIT_FAILURE);
    }
    stack->items[++stack->top] = value;
}

// Pop an element from the stack
char pop(stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow. Cannot pop.\n");
        exit(EXIT_FAILURE);
    }
    return stack->items[stack->top--];
}

// Peek at the top element of the stack
char peek(stack* stack) {
    return stack->items[stack->top];
}

// Determine the precedence of an operator
int precedence(char operator) {
    switch (operator) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

// Convert infix expression to postfix
void infixToPostfix(const char* infixExpression, char* postfixExpression) {
    stack* stack = malloc(sizeof(stack));
    initialize(stack);

    int i, j;
    for (i = 0, j = 0; infixExpression[i] != '\0'; i++) {
        if (isdigit(infixExpression[i])) {
            postfixExpression[j++] = infixExpression[i];
        } else if (infixExpression[i] == '(') {
            push(stack, infixExpression[i]);
        } else if (infixExpression[i] == ')') {
            while (!isEmpty(stack) && peek(stack) != '(') {
                postfixExpression[j++] = pop(stack);
            }
            pop(stack); // Pop '('
        } else {
            while (!isEmpty(stack) && precedence(peek(stack)) >= precedence(infixExpression[i])) {
                postfixExpression[j++] = pop(stack);
            }
            push(stack, infixExpression[i]);
        }
    }

    while (!isEmpty(stack)) {
        postfixExpression[j++] = pop(stack);
    }

    postfixExpression[j] = '\0';

    free(stack);
}

// Evaluate postfix expression
int evaluatePostfix(const char* postfixExpression) {
    stack* stack = malloc(sizeof(stack));
    initialize(stack);

    for (int i = 0; postfixExpression[i] != '\0'; i++) {
        if (isdigit(postfixExpression[i])) {
            push(stack, postfixExpression[i] - '0'); // Convert char to int
        } else {
            int operand2 = pop(stack);
            int operand1 = pop(stack);

            switch (postfixExpression[i]) {
                case '+':
                    push(stack, operand1 + operand2);
                    break;
                case '-':
                    push(stack, operand1 - operand2);
                    break;
                case '*':
                    push(stack, operand1 * operand2);
                    break;
                case '/':
                    if (operand2 == 0) {
                        printf("Error: Division by zero.\n");
                        exit(EXIT_FAILURE);
                    }
                    push(stack, operand1 / operand2);
                    break;
                default:
                    printf("Error: Unknown operator %c\n", postfixExpression[i]);
                    exit(EXIT_FAILURE);
            }
        }
    }

    int result = pop(stack);
    free(stack);
    return result;
}

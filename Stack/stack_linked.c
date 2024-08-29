/*stack using linked list*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

void initialize(Stack* stack);
int isEmpty(Stack* stack);
void push(Stack* stack, int value);
int pop(Stack* stack);
void display(Stack* stack);
void clean(Stack* stack);

int main() {
    Stack* stack = malloc(sizeof(Stack));
    initialize(stack);
    bool keepRun = true;
    printf("\t\t*STACK OPERATIONS*\t\t\n");
    while (keepRun) {
        printf("1. Push \n2. Pop \n3. Peek \n4. Count \n5. Display \n6. Clear Stack \n7. Quit\n");
        int choice, value;
        scanf("%d", &choice);
        switch (choice) {
            case 1:    // push case
                printf("Enter the push value: ");
                scanf("%d", &value);
                push(stack, value);
                break;

            case 2:    // pop case
                printf("Popped %d \n", pop(stack));
                break;

            case 3:    // peek case
                if (!isEmpty(stack))
                    printf("The top value is: %d\n", stack->top->data);
                else
                    printf("Stack is empty.\n");
                break;

            case 4:    // count function
                printf("The number of elements in the stack is: %d\n", isEmpty(stack) ? 0 : 1);
                break;

            case 5:    // display function
                display(stack);
                break;

            case 6:    // clean stack
                clean(stack);
                printf("Stack Cleaned.\n");
                break;

            case 7:    // exit
                keepRun = false;
                break;

            default:
                printf("Wrong Option, choose again. \n");
                break;
        }
    }
    return 0;
}

void initialize(Stack* stack) {
    stack->top = NULL;
}

int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

void push(Stack* stack, int value) {
    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
    printf("Pushed %d.\n", value);
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow. Cannot pop.\n");
        return 0;
    }
    Node* temp = stack->top;
    int poppedValue = temp->data;
    stack->top = temp->next;
    free(temp);
    return poppedValue;
}

void display(Stack* stack) {
    if (isEmpty(stack)) {
        printf("CANNOT DISPLAY EMPTY STACK\n");
        return;
    }
    printf("Stack is: ");
    Node* current = stack->top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    putchar('\n');
}

void clean(Stack* stack) {
    while (!isEmpty(stack)) {
        pop(stack);
    }
    free(stack);
}

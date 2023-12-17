#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 100 //declaring the max size of the stack

typedef struct Stack{   //structure of the stack containing the items of stack and top of the stack.
    int items[MAX_SIZE];
    int top;
}stack;

void initialize(stack* stack);  //initializing the stack top
int isEmpty(stack* stack);      //checking if the stack is empty
int isFull(stack* stack);       //checking if the stack is full
void push(stack* stack, int value); //pushing an element at the top of the stack
int pop(stack* stack);              //popping an element from the top of the stack
void display(stack* stack);         //displaying the whole stack
void clean(stack* stack);

int main(){
    stack* stack = malloc(sizeof(stack));
    initialize(stack);
    bool keepRun = true;
    printf("\t\t*STACK OPERATIONS*\t\t\n");
    while(keepRun){
        printf("1. Push \n2. Pop \n3.Peek \n4.Count \n5.Display \n6.Clear Stack \n7. Quit\n");
        int choice, value;
        scanf("%d", &choice);
        switch(choice)  {

            case 1:    //push case
            printf("Enter the push value: ");
            scanf("%d", &value);
            push(stack, value);
            break;

            case 2:     //pop case
            printf("Popped %d \n", pop(stack));
            break;

            case 3:     //peek case
            printf("The top value is: %d\n", stack->items[stack->top]);
            break;

            case 4:     //count function
            printf("The number of elements in the stack is: %d\n", stack->top+1);
            break;

            case 5:     //display function
            display(stack);
            break;

            case 6:     //clean stack
            clean(stack);
            printf("Stack Cleaned.\n");
            break;

            case 7:     //exit
            keepRun = false;
            break;

            default:
            printf("Wrong Option choose again. \n");
            break;
            
        }

    }
    return 0;
}

void initialize(stack* stack){
    stack->top = -1;
}

int isEmpty(stack* stack){
    return stack->top == -1;    //returns 1 if stack empty
}
int isFull(stack* stack){
    return stack->top == MAX_SIZE-1;    //returns 1 if stack full
}

void push(stack* stack, int value){
    if(isFull(stack)){  //if stack full no elements can be pushed
        printf("Stack Overflow. Cannot push %d\n", value);
        return;
    }
    stack->items[++stack->top] = value;    // top increments and put the value inside items[] array.
    printf("Pushed %d.\n", value);
}

int pop(stack* stack)   {
    if(isEmpty(stack)){
        printf("Stack Underflow. Cannot pop %d\n", stack->items[stack->top]);
        return 0;
    }
    return stack->items[stack->top--];
}

void display(stack* stack){
    if(isEmpty(stack)){
        printf("CANNOT DISPLAY EMPTY STACK");
        return;
    }
    printf("Stack is: ");
    for(int i = 0; i < stack->top + 1; i++)
        printf("%d ", stack->items[i]);
    putchar('\n');
}

void clean(stack* stack){
    if(stack->items != NULL)
    free(stack->items);
    free(stack);
}
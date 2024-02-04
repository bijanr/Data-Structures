#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    char name[128];
    int age;
    long int roll;
    struct list* next;
}List;

int main() {
    List* top = (List*)calloc(1, sizeof(List));
    List* customer;
    int limit, i = 1;
    printf("Enter the Number of Customerss: \n");
    scanf("%d", &limit);
    printf("Enter the customer details : \n");
    printf("1.Name\n2.Age\n3.Roll\n");
    printf("Customer 1: \n");
    scanf("%s", &top->name);
    scanf("%d", &top->age);
    scanf("%ld", &top->roll);
    top->next = NULL;
    customer = (List*)calloc(1, sizeof(List));
    customer = top;
    do{
        List* temp = (List*)calloc(1, sizeof(List));
        printf("Customer %d: \n", i+1);
        scanf("%s", &temp->name);
        scanf("%d", &temp->age);
        scanf("%ld", &temp->roll);
        temp->next = NULL;
        customer->next = temp;
        customer = customer->next;
        i++;
    }while(i < limit);
    //traversing
    customer = top;
    for(int i = 0; i < limit; i++){
        printf("%s\n", customer->name);
        printf("%d\n", customer->age);
        printf("%ld\n", customer->roll);
        customer = customer->next;
    }


    
    
    return 0;
}
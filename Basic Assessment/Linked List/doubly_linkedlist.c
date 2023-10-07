#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* prev;
    struct node* next;
}Node;

void traverse(Node* list);


int main(){


    Node* head = malloc(sizeof(Node));
    Node* list;

    int limit;
    printf("Enter the limit: ");
    scanf("%d", &limit);

    printf("Enter the elements: ");
    scanf("%d", &head->data);
    head->prev = NULL;
    head->next = NULL;

    list = head;
    for(int i = 0; i<limit-1; i++)
    {
        Node* temp = malloc(sizeof(Node));
        scanf("%d", &temp->data);
        temp->next = NULL;
        temp->prev = list;
        list->next = temp;
        list = list->next;
    }

    list = head;
    traverse(list);
}

void traverse(Node* list){
    printf("the list is: \n");
    while(list != NULL) 
    {
    printf("%d ", list->data);
    list = list->next;
    }
}
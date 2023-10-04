#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
    struct node* previous;
}Node;

int main(){
    Node* head = (Node*)calloc(1, sizeof(Node));
    int limit;
    Node* list;
    head = list;
    list->previous = head;
    printf("Enter the limit: ");
    scanf("%d", &limit);
    printf("Enter the elements: \n");
    for(int i = 0; i<limit; i++)
    {
        Node* temp = (Node*)calloc(1, sizeof(Node));
        scanf("%d", &temp->data);
        list->next = (Node*)calloc(1, sizeof(Node));
        list->next = temp;
        list = list->next;
    }
    list = head->next;
    while(list != NULL){
        printf("%d ",list->data);
        list = list->next;
    }
    return 0;
}
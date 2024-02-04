#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct  node* next;
}Node;

void input(Node* list, int limit);
void display(Node* list, int limit);

int main()
{
    Node* head = (Node*)calloc(1,sizeof(Node));
    int limit;
    printf("Enter the limit of the node: ");
    scanf("%d", &limit);
    printf("Enter the element of the linked list: \n");
    scanf("%d", &head->data);
    Node* list = head;
    input(list, limit);

    list = head;
    display(list, limit);
    return 0;
}

void input(Node* list, int limit){
    for(int i = 1; i< limit; i++){
        Node* temp = (Node*)calloc(1,sizeof(Node));
        scanf("%d", &temp->data);
        list->next = (Node*)calloc(1,sizeof(Node));
        list->next = temp;
        list = list->next;
    }

}

void display(Node* list, int limit){
    printf("The list is: ");
    for(int i = 0;i< limit; i++){
        printf("%d ", list->data);
        list = list->next;
    }
}

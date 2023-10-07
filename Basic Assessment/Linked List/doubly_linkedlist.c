#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* prev;
    struct node* next;
}Node;

Node* addtoEmpty(Node* head, int data);
int main(){

}

Node* addtoEmpty(Node* head, int data){
    Node* temp = malloc(sizeof(Node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    head = temp;
    return head;

}
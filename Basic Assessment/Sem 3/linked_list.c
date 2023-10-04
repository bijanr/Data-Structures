#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int data;
  struct node* next;
}Node;    // defining the struct node as a new datatype "Node"
int main()  
{
    Node *T, *head, *T1;     
    int limit;
    T = (Node *)calloc(1, sizeof(Node));
    head = T;
    printf("Enter the element 1 : ");
    scanf("%d", &T->data);
    T->next = (Node *)calloc(1, sizeof(Node));
    T = T->next;

    printf("Enter the element 2 : ");
    scanf("%d", &T->data);
    T->next = (Node *)calloc(1, sizeof(Node));
    T = T->next;

    printf("Enter the element 3 : ");
    scanf("%d", &T->data);
    T->next = NULL;
    while (T != NULL)
    {
      printf("%d ",T->data);
      T = T->next;
    } 

}

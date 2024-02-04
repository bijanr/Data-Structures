#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}Node;

void input(Node* list, int i, int limit);
Node* alloc();
void traverse(Node* list);
void bubbleSort(Node* list);
int main(){
    Node* head = alloc();
    Node* list;
    int limit;
    int choice;
    printf("\tLinked List Operations\t\n");
    printf("1. Creation\n-Insertion    ( 2.Front  3.N  4.Back )\n-Deletion     ( 5.Front  6.N  7.Back )\n8.Traversal   9.Sort\n10.Quit\n");
    do {
        printf("Operation Number: \n");
        scanf("%d", &choice);
        switch (choice)
        {
            Node* newNode;
            case 1: 
                printf("Enter the number of initial nodes: ");
                scanf("%d", &limit);
                printf("Enter the elements: ");
                scanf("%d", &head->data);
                head->next = NULL;
                list = (Node*)calloc(1, sizeof(Node));
                list = head;
                int i = 1;
                input(list, i, limit);
                break;
            case 2:     //front insertion
                newNode = alloc();
                printf("Enter the element to insert at Front: ");
                scanf("%d", &newNode->data);
                newNode->next = head;
                head = newNode;
                break;

            case 3:     //n position insertion
                list = head;
                int listCount = 1;
                int location;
                while(list != NULL){    //counting the number of variables
                    list = list->next;
                    listCount++;
                }

                do{         //taking the position input
                    printf("Enter any index between 2 and %d: ", listCount);
                    scanf("%d", &location);

                    if(location < 2 || location > listCount)
                        printf("Enter a valid index.\n");
                }while(location < 2 || location > listCount);

                list = head;
                for(int i = 2; i < location; i++){      //traversing till list< list[location]
                    list = list->next;
                }

                newNode = alloc();
                printf("Enter the element to insert: ");
                scanf("%d", &newNode->data);
                Node* temp = alloc();
                temp = list->next;
                list->next = newNode;
                newNode->next = temp;
                listCount = 1;
                break;

            case 4:     //insertion at back
                newNode = alloc();
                printf("Enter the element to insert at Back: ");
                scanf("%d", &newNode->data);
                newNode->next = NULL;
                while(list->next != NULL){
                    list = list->next;
                }
                list->next = newNode;
                break;

            case 5: //deletion at front
                if(head != NULL){
                    list = head;
                    printf("Element deleted: %d\n", head->data);
                    head = head->next;
                    free(list);
                    break;
                }
                else{
                    printf("List is already empty.\n");
                    break;
                }
            case 6: //deletion at n position
                listCount = 1;
                while(list != NULL){
                    list = list->next;
                    listCount++;
                }

                do{
                    printf("Enter an index between 2 and %d: ", listCount);
                    scanf("%d", &location);
                    if(location < 2 || location > listCount){
                        printf("Enter a valid index.\n");
                    }
                }while(location < 2 || location > listCount);

                list = head;
                for(int i = 2; i < location; i++){
                    list = list->next;
                }

                newNode = alloc();
                printf("Element deleted: %d\n", list->next->data);
                temp = list->next;
                list->next = temp->next;
                free(temp);
                break;
            case 7: //delete at back
            if(head == NULL){
                printf("Empty List, unable to delete.\n");
                break;}
                list = head;
                while(list->next->next != NULL)
                    list = list->next;
                printf("Deleted node: %d\n", list->next->data);
                temp = alloc();
                temp = list->next;
                list->next = NULL;
                free(temp);
                break;
            
            case 8: //traverse
                list = head;
                traverse(list);
                break;
            
            case 9: //bubble sort
                list = head;
                bubbleSort(list);
                break;

            case 10:    //terminate 
                printf("Terminated!");
                break;
                
        }
    }while(choice != 10);
    return 0;
}

void input(Node* list, int i, int limit){
    for(int i = 1; i<limit; i++){
        Node* temp = alloc();
        scanf("%d", &temp->data);
        temp->next = NULL;
        list->next = temp;
        list = list->next;
    }
}

Node* alloc(){
    Node* newNode = (Node*)calloc(1, sizeof(Node));
    return newNode;
}
void bubbleSort(Node* list){
    int swapped;
    Node* pointer  = list;
    Node* lastPointer = NULL;
    do{
        pointer = list;
        swapped = 0;
        while(pointer->next != lastPointer){
            if(pointer->data > pointer->next->data){
                int temp = pointer->data;
                pointer->data = pointer->next->data;
                pointer->next->data = temp;
                swapped = 1;
            }
            
            pointer = pointer->next;

        }
        lastPointer = pointer;
    }while(swapped);

}

void traverse(Node* list){
    if(list == NULL){
        printf("Empty list.");
    }
    else
    {
        while(list != NULL )
            {
                printf("%d ", list->data);
                list = list->next;
            }
            putchar('\n');
    }
    
}
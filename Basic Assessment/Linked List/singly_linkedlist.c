#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
}Node;

void input(Node* list, int i, int size);
void traverse(Node* list);


int main()  {
    Node* head;
    Node* list;
    int terminate = 0, choice, loop = 0, size;
    head = (Node*)calloc(1,sizeof(Node));

    printf(" *Linked List Operations*");
    while(loop == 0)
    {
        printf("\n1. Creation\n2. Insertion (Beginning)\n3. Insertion (End)\n4. Insertion (N Position)\n5. Deletion(Beginning)\n6. Deletion(End)\n7. Deletion(N Position)\n8. Peek and Count\n9.Average \n10. Traverse\n11. Quit\n");
        scanf("%d", &choice);
        switch (choice)
        {
            Node* newNode;
            int location;
            case 1: // Creation of Linked List with 1 or more elements.
                printf("Enter the N number of Initial Nodes : \n");
                scanf("%d", &size);
                printf("Enter the elements: \n");
                scanf("%d", &head->data);
                head->next = NULL;
                list = (Node*)calloc(1,sizeof(Node));
                list = head;
                int i = 1;
                input(list, i, size);
                break;
            
            case 2: //insertion of element at the beginning 
                newNode = (Node*)calloc(1,sizeof(Node));
                printf("Enter element to add at beginning: ");
                scanf("%d", &newNode->data);
                newNode->next = head;
                head = newNode;
                break;


            case 3: //insertion of element at the end.
                newNode = (Node*)calloc(1,sizeof(Node));
                printf("Enter element to add at end: ");
                scanf("%d", &newNode->data);
                newNode->next = NULL;
                list = head;
                while(list->next!= NULL)
                {
                    list = list->next;
                }
                list->next = newNode;
                break;


            case 4: // insertion of element at tNh position
                list = head;
                int count = 1;
                while(list != NULL)
                {
                    list = list->next;
                    count++;
                }
                invalid:
                printf("Enter any element between index 2 to %d : ", count);
                scanf("%d", &location);
                if(location < 2 || location >count){
                    printf("Enter correct Index! ");
                    goto invalid;
                }
                newNode = (Node*)calloc(1,sizeof(Node));
                printf("Enter the element to add in location %d : ", location);
                scanf("%d", &newNode->data);
                list  = head;
                for(i = 2; i< location; i++)
                {
                    list = list->next;
                }
                Node* temp = (Node*)calloc(1,sizeof(Node));
                temp = list->next;
                list->next = newNode;
                newNode->next = temp;
                free(temp);
                count = 1;
                break;


            case 5: //deleting on beginning
                list = head;
                printf("Element deleted: %d", head->data);
                head = head->next;
                list->next = NULL;
                break;

            case 6: //deletion at end
                list = head;
                while(list->next->next != NULL)
                {
                    list = list->next;
                }
                printf("Element deleted: %d",list->next->data);
                temp = (Node*)calloc(1, sizeof(Node));
                temp = list->next;
                list->next = NULL;
                free(temp);
                break;


            case 7: //deletion at n position
                list = head;
                while(list != NULL)
                {
                    list = list->next;
                    count++;
                }

                invalid1:
                printf("Enter any element from 2 to %d: ", count);
                scanf("%d", &location);
                if(location<2 || location>count){
                    printf("Invalid Position");
                    goto invalid1;
                }

                list = head;
                for(int i = 2; i<location; i++){
                    list = list->next;
                }
                printf("Deleted item: %d", list->next->data);
                temp = list->next;
                list->next = temp->next;
                temp->next = NULL;
                count = 1;
                break;
            
            case 8: 
                list = head;
                while(list != NULL){
                    list = list->next;
                    count++;
                }
                printf("The last element is: %d", list->data);
                printf("The Number of elements are: %d", count);
                count = 1;
                break;

            case 9:
                list = head;
                int average = 0;
                int sum = 0, c = 1;
                while(list != NULL){
                    sum += list->data;
                    list = list->next;
                    c++;
                }
                
                average = sum/c;
                printf("The average = %f", average);
                break;
            case 10: //displaying
                list = head;
                printf("The list is: ");
                traverse(list);
                break;
            case 11: 
                printf("Terminated!\n");
                loop = 1;
                break;
            default:
                printf("Enter Correct Choice: ");
                break;
        }
    }
    

    
}

void input(Node* list, int i, int size){
    for(i= 1; i<size; i++)
    {
        Node *temp = (Node*)calloc(1,sizeof(Node));
        scanf("%d", &temp->data);
        temp->next = NULL;
        list->next = temp;
        list = list->next;

    }
}

//displaying
void traverse(Node* list)    {
    while(list != NULL) {
        printf("%d ", list->data);
        list = list->next;
    }
}  
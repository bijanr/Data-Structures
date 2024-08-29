#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
    struct node* prev;
} Node;

void input(Node* list, int i, int size);
void traverse(Node* list);
void sortLinkedList(Node* list);

int main() {
    Node* head = NULL;
    Node* list = NULL;
    int terminate = 0, choice, loop = 0, size;

    printf(" *Doubly Circular Linked List Operations*\n");

    while (loop == 0) {
        printf("\n1. Creation\n2. Insertion (Beginning)\n3. Insertion (End)\n4. Insertion (N Position)\n5. Deletion (Beginning)\n6. Deletion (End)\n7. Deletion (N Position)\n8. Peek and Count\n9. Average \n10. Sort \n11. Traverse\n12. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
            Node* newNode;
            int location;

            case 1: // Creation of Linked List with 1 or more elements.
                printf("Enter the N number of Initial Nodes: ");
                scanf("%d", &size);

                if (head == NULL) {
                    head = (Node*)malloc(sizeof(Node));
                    printf("Enter the elements: ");
                    scanf("%d", &head->data);
                    head->next = head;
                    head->prev = head;
                    list = head;
                    input(list, 1, size);
                } else {
                    printf("List already created. Please choose another option.\n");
                }
                break;

            case 2: // Insertion of element at the beginning
                newNode = (Node*)malloc(sizeof(Node));
                printf("Enter element to add at the beginning: ");
                scanf("%d", &newNode->data);
                newNode->next = head;
                newNode->prev = head->prev;
                head->prev->next = newNode;
                head->prev = newNode;
                head = newNode;
                break;

            case 3: // Insertion of element at the end
                newNode = (Node*)malloc(sizeof(Node));
                printf("Enter element to add at end: ");
                scanf("%d", &newNode->data);
                newNode->next = head;
                newNode->prev = head->prev;
                head->prev->next = newNode;
                head->prev = newNode;
                break;

            case 4: // Insertion of element at Nth position
                list = head;
                int count = 1;

                while (list->next != head) {
                    list = list->next;
                    count++;
                }

                do {
                    printf("Enter any element between index 2 to %d: ", count);
                    scanf("%d", &location);

                    if (location < 2 || location > count) {
                        printf("Enter correct Index! ");
                    }
                } while (location < 2 || location > count);

                newNode = (Node*)malloc(sizeof(Node));
                printf("Enter the element to add in location %d: ", location);
                scanf("%d", &newNode->data);

                list = head;
                for (int i = 2; i < location; i++) {
                    list = list->next;
                }

                newNode->next = list->next;
                newNode->prev = list;
                list->next->prev = newNode;
                list->next = newNode;
                break;

            case 5: // Deletion on beginning
                if (head != NULL) {
                    list = head;

                    if (head->next == head) {
                        // Only one node in the list
                        printf("Element deleted: %d\n", head->data);
                        free(head);
                        head = NULL;
                    } else {
                        // More than one node
                        head->next->prev = head->prev;
                        head->prev->next = head->next;
                        Node* temp = head;
                        head = head->next;
                        printf("Element deleted: %d\n", temp->data);
                        free(temp);
                    }
                } else {
                    printf("List is empty. Cannot delete from an empty list.\n");
                }
                break;

            case 6: // Deletion at end
                if (head != NULL) {
                    list = head;

                    if (head->next == head) {
                        // Only one node in the list
                        printf("Element deleted: %d\n", head->data);
                        free(head);
                        head = NULL;
                    } else {
                        Node* temp = head->prev;
                        temp->prev->next = head;
                        head->prev = temp->prev;
                        printf("Element deleted: %d\n", temp->data);
                        free(temp);
                    }
                } else {
                    printf("List is empty. Cannot delete from an empty list.\n");
                }
                break;

            case 7: // Deletion at N position
                list = head;
                count = 1;

                while (list->next != head) {
                    list = list->next;
                    count++;
                }

                do {
                    printf("Enter any element from 2 to %d: ", count - 1);
                    scanf("%d", &location);

                    if (location < 2 || location >= count) {
                        printf("Invalid Position. ");
                    }
                } while (location < 2 || location >= count);

                list = head;
                for (int i = 2; i < location; i++) {
                    list = list->next;
                }

                Node* temp = list->next;
                temp->next->prev = list;
                list->next = temp->next;
                printf("Deleted item: %d\n", temp->data);

                free(temp);
                break;

            case 8: // Peek and Count
                if (head != NULL) {
                    list = head;
                    count = 0;

                    do {
                        printf("%d ", list->data);
                        list = list->next;
                        count++;
                    } while (list != head);

                    printf("\nThe Number of elements are: %d\n", count);
                } else {
                    printf("List is empty.\n");
                }
                break;

            case 9: // Average
                if (head != NULL) {
                    list = head;
                    float average = 0;
                    int sum = 0, c = 0;

                    do {
                        sum += list->data;
                        list = list->next;
                        c++;
                    } while (list != head);

                    average = sum / (float)c;
                    printf("The average = %f\n", average);
                } else {
                    printf("List is empty.\n");
                }
                break;

            case 10: // Sorting
                list = head;
                sortLinkedList(list);
                break;

            case 11: // Traverse
                if (head != NULL) {
                    list = head;

                    do {
                        printf("%d ", list->data);
                        list = list->next;
                    } while (list != head);

                    printf("\n");
                } else {
                    printf("List is empty.\n");
                }
                break;

            case 12: // Quit
                printf("Terminated!\n");
                loop = 1;
                break;

            default:
                printf("Enter Correct Choice: ");
                break;
        }
    }

    // Free memory before exiting
    while (head != NULL) {
        list = head;
        head = head->next;
        free(list);
    }

    return 0;
}

void input(Node* list, int i, int size) {
    for (i = 1; i < size; i++) {
        Node* temp = (Node*)malloc(sizeof(Node));
        scanf("%d", &temp->data);
        temp->next = list->next;
        temp->prev = list;
        list->next->prev = temp;
        list->next = temp;
        list = list->next;
    }
}

void sortLinkedList(Node* list) {
    int swapped;
    Node* ptr1;
    Node* lptr = NULL;

    if (list == NULL)
        return;

    do {
        swapped = 0;
        ptr1 = list;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                // Swap data
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;

                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}


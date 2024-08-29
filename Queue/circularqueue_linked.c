#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Circular Queue structure
typedef struct {
    Node* front;
    Node* rear;
    int size;
} CircularQueue;

// Function prototypes
void initialize(CircularQueue* queue);
int isEmpty(CircularQueue* queue);
void enqueue(CircularQueue* queue, int value);
int dequeue(CircularQueue* queue);
void display(CircularQueue* queue);

int main() {
    CircularQueue queue;
    initialize(&queue);

    int choice, value;

    do {
        printf("\nCircular Queue Operations using Linked List:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(&queue, value);
                break;

            case 2:
                if (!isEmpty(&queue)) {
                    printf("Dequeued value: %d\n", dequeue(&queue));
                } else {
                    printf("Queue is empty. Cannot dequeue.\n");
                }
                break;

            case 3:
                display(&queue);
                break;

            case 4:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 4);

    return 0;
}

// Initialize the circular queue
void initialize(CircularQueue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
}

// Check if the circular queue is empty
int isEmpty(CircularQueue* queue) {
    return queue->size == 0;
}

// Enqueue an element into the circular queue
void enqueue(CircularQueue* queue, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation error. Cannot enqueue %d.\n", value);
        exit(EXIT_FAILURE);
    }

    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        queue->front = newNode;
    } else {
        queue->rear->next = newNode;
    }

    queue->rear = newNode;
    queue->size++;

    printf("Enqueued %d.\n", value);
}

// Dequeue an element from the circular queue
int dequeue(CircularQueue* queue) {
    int value;

    if (isEmpty(queue)) {
        printf("Queue Underflow. Cannot dequeue.\n");
        exit(EXIT_FAILURE);
    }

    Node* temp = queue->front;
    value = temp->data;

    if (queue->front == queue->rear) {
        initialize(queue);
    } else {
        queue->front = queue->front->next;
    }

    free(temp);
    queue->size--;

    return value;
}

// Display the elements of the circular queue
void display(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
    } else {
        printf("Circular Queue elements: ");
        Node* current = queue->front;
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct {
    int items[MAX_SIZE];
    int front, rear;
    int size;
} CircularQueue;

void initialize(CircularQueue* queue);
int isEmpty(CircularQueue* queue);
int isFull(CircularQueue* queue);
void enqueue(CircularQueue* queue, int value);
int dequeue(CircularQueue* queue);
void display(CircularQueue* queue);

int main() {
    CircularQueue queue;
    initialize(&queue);

    int choice, value;

    do {
        printf("\nCircular Queue Operations:\n");
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

void initialize(CircularQueue* queue) {
    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;
}

int isEmpty(CircularQueue* queue) {
    return queue->size == 0;
}

int isFull(CircularQueue* queue) {
    return queue->size == MAX_SIZE;
}

void enqueue(CircularQueue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue Overflow. Cannot enqueue %d.\n", value);
    } else {
        if (isEmpty(queue)) {
            queue->front = 0;
        }

        queue->rear = (queue->rear + 1) % MAX_SIZE;
        queue->items[queue->rear] = value;
        queue->size++;

        printf("Enqueued %d.\n", value);
    }
}

int dequeue(CircularQueue* queue) {
    int value;

    if (isEmpty(queue)) {
        printf("Queue Underflow. Cannot dequeue.\n");
        exit(EXIT_FAILURE);
    } else {
        value = queue->items[queue->front];

        if (queue->front == queue->rear) {
            initialize(queue);
        } else {
            queue->front = (queue->front + 1) % MAX_SIZE;
        }

        queue->size--;

        return value;
    }
}

void display(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
    } else {
        printf("Circular Queue elements: ");
        int i = queue->front;
        do {
            printf("%d ", queue->items[i]);
            i = (i + 1) % MAX_SIZE;
        } while (i != (queue->rear + 1) % MAX_SIZE);

        printf("\n");
    }
}

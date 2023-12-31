#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int front, rear;
} Queue;

void initialize(Queue *queue);
int isEmpty(Queue *queue);
int isFull(Queue *queue);
void enqueue(Queue *queue, int value);
int dequeue(Queue *queue);
void display(Queue *queue);

int main() {
    Queue queue;
    initialize(&queue);

    int choice, value;

    do {
        printf("\nLinear Queue Operations:\n");
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

void initialize(Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isEmpty(Queue *queue) {
    return queue->front == -1;
}

int isFull(Queue *queue) {
    return (queue->rear == MAX_SIZE - 1 && queue->front == 0) || (queue->rear + 1 == queue->front);
}

void enqueue(Queue *queue, int value) {
    if (isFull(queue)) {
        printf("Queue Overflow. Cannot enqueue %d.\n", value);
    } else {
        if (isEmpty(queue)) {
            queue->front = 0;
        }
        queue->rear = (queue->rear + 1) % MAX_SIZE;
        queue->items[queue->rear] = value;
        printf("Enqueued %d.\n", value);
    }
}

int dequeue(Queue *queue) {
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

        return value;
    }
}

void display(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        int i;
        for (i = queue->front; i != queue->rear; i = (i + 1) % MAX_SIZE) {
            printf("%d ", queue->items[i]);
        }
        printf("%d\n", queue->items[i]); // Display the last element
    }
}

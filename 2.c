#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = 0, rear = -1;

void enqueue() {
    if (rear == MAX - 1) {
        printf("Queue is full (Overflow)\n");
    } else {
        int value;
        printf("Enter the number to enqueue: ");
        scanf("%d", &value);
        queue[++rear] = value;
        printf("Inserted: %d\n", value);
    }
}

void dequeue() {
    if (front > rear) {
        printf("Queue is empty (Underflow)\n");
    } else {
        printf("Deleted: %d\n", queue[front++]);
    }
}

void display() {
    if (front > rear) {
        printf("Queue is empty\n");
    } else {
        printf("Queue: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting program.\n");
            return 0;
        default:
            printf("Invalid");
        }
    }
}

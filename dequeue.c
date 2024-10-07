#include <stdio.h>

#define MAX 100

int deque[MAX];
int front = -1, rear = -1;

void enqueueFront(int data) {
    if (front == -1) {
        front = rear = 0;
    } else if (front == 0) {
        front = MAX - 1;
    } else {
        front--;
    }
    deque[front] = data;
}

void enqueueRear(int data) {
    if (front == -1) {
        front = rear = 0;
    } else if (rear == MAX - 1) {
        rear = 0;
    } else {
        rear++;
    }
    deque[rear] = data;
}

int dequeueFront() {
    int data = deque[front];
    if (front == rear) {
        front = rear = -1;  // Reset queue after last element is removed
    } else if (front == MAX - 1) {
        front = 0;
    } else {
        front++;
    }
    return data;
}

int dequeueRear() {
    int data = deque[rear];
    if (front == rear) {
        front = rear = -1;  // Reset queue after last element is removed
    } else if (rear == 0) {
        rear = MAX - 1;
    } else {
        rear--;
    }
    return data;
}

void displayDeque() {
    if (front == -1) {
        printf("Deque is empty\n");
        return;
    }

    int i = front;
    while (i != rear) {
        printf("%d ", deque[i]);
        i = (i + 1) % MAX;
    }
    printf("%d\n", deque[rear]);  // Print the rear element
}

int main() {
    enqueueRear(10);
    enqueueRear(20);
    enqueueFront(5);
    enqueueFront(1);

    printf("Deque after enqueuing elements: ");
    displayDeque();

    printf("Dequeued from front: %d\n", dequeueFront());
    printf("Dequeued from rear: %d\n", dequeueRear());

    printf("Deque after dequeuing elements: ");
    displayDeque();

    return 0;
}

#include <stdio.h>

int queue[100];
int front = 0, rear = -1;

void enqueue(int data) {
    queue[++rear] = data;
}

int dequeue() {
    return queue[front++];
}

int main() {
    int n, data;

    printf("Enter number of elements to enqueue: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter data to enqueue: ");
        scanf("%d", &data);
        enqueue(data);
    }

    printf("Dequeued elements:\n");
    while (front <= rear) {
        printf("%d\n", dequeue());
    }

    return 0;
}

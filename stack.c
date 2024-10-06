#include <stdio.h>

int stack[100];
int top = -1;

void push(int data) {
    stack[++top] = data;
}

int pop() {
    return stack[top--];
}

int main() {
    int n, data;

    printf("Enter number of elements to push: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter data to push: ");
        scanf("%d", &data);
        push(data);
    }

    printf("Popped elements:\n");
    while (top != -1) {
        printf("%d\n", pop());
    }

    return 0;
}

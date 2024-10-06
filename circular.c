#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void printList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);  // Loop back to the head

    printf("(back to head)\n");
}

int main() {
    struct Node* head = NULL;
    struct Node* temp;
    struct Node* tail = NULL;
    int n, data;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = head;  // Initialize the next to point to head (circular)

        if (head == NULL) {
            head = newNode;  // If the list is empty, set head
            tail = newNode;  // Set tail to the first node initially
        } else {
            tail->next = newNode;  // Set the last node to point to the new node
        }

        tail = newNode;  // Move the tail to the new node
    }

    // Make the list circular by pointing the last node back to the head
    if (tail != NULL) {
        tail->next = head;
    }

    printList(head);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *next;
};

int main() {
    int n, value, count = 0;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    // Read number of nodes
    scanf("%d", &n);

    // Create linked list
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);

        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Count nodes
    temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    // Print result
    printf("%d", count);

    return 0;
}
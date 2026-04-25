#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Node* insert(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    
    if (head == NULL) {
        newNode->next = newNode; 
        return newNode;
    }

    
    struct Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    
    temp->next = newNode;
    newNode->next = head;

    return head;
}


void traverse(struct Node* head) {
    if (head == NULL) return;

    struct Node* temp = head;

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head); 
}


int main() {
    int n, x;
    struct Node* head = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        head = insert(head, x);
    }

    traverse(head);

    return 0;
}
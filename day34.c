#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Node structure (stack)
struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

// Push
void push(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = top;
    top = newNode;
}

// Pop
int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    struct Node* temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);
    return val;
}

// Evaluate postfix
int evaluate(char* expr) {
    char* token = strtok(expr, " ");

    while (token != NULL) {

        // If operand
        if (isdigit(token[0])) {
            push(atoi(token));
        }

        // Operator
        else {
            int b = pop();
            int a = pop();

            switch (token[0]) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
            }
        }

        token = strtok(NULL, " ");
    }

    return pop();
}

// Main
int main() {
    char expr[100];

    fgets(expr, sizeof(expr), stdin);

    // Remove newline if present
    expr[strcspn(expr, "\n")] = '\0';

    int result = evaluate(expr);

    printf("%d", result);

    return 0;
}
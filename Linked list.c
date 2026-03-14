#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL;

// push function
void push(int x) {
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = top;
    top = temp;
}

// recursive function to print stack as queue
void printQueue(struct Node *temp) {
    if (temp == NULL)
        return;

    printQueue(temp->next);   // go to last node
    printf("%d ", temp->data); // print while returning
}

int main() {
    push(10);
    push(20);
    push(30);
    push(40);

    printf("Stack printed as Queue:\n");
    printQueue(top);

    return 0;
}

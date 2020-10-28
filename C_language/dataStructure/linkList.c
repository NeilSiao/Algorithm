#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *top = NULL;
Node *current;
void push(int data);
void loop();
void main()
{
    push(3);
    push(4);
    push(5);
    push(6);
    push(7);
    loop();
}
void loop()
{
    Node *temp = top;
    while (1)
    {
        printf("%d \r\n ", temp->data);
        temp = temp->next;
        if (temp == NULL)
            break;
    }
}
void push(int data)
{
    Node *newNode;
    newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (top == NULL)
    {
        top = newNode;
        current = top;
        return;
    }

    current->next = newNode;
    current = newNode;
}

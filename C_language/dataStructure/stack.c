#include <stdio.h>

#define STACK_SIZE 5  // doesn't need semicolon
int stack[STACK_SIZE];
int top = -1;
int isEmpty();
void push(int);
int pop();

void main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);

    printf("first val : %d \r\n", pop());
    printf("first val : %d \r\n", pop());
    printf("first val : %d \r\n", pop());
    printf("first val : %d \r\n", pop());
    printf("first val : %d", pop());
    printf("first val : %d", pop());
}

void push(int x)
{
    if (top < STACK_SIZE)
    {
        stack[++top] = x; // ++top 跟 top ++ 有天壤之別
    }
    else
    {
        printf("stack is full");
    }
}

int pop()
{
    if (top != -1)
    {
        int val = stack[top];
        printf("firsst in pop %d", stack[top]);
        top--;
        return val;
    }
    else
    {
        printf("stack is Empty");
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 3
int arr[MAX];
int front, rear;

int isEmpty()
{
    return (front == -1 && rear == -1) ? 1 : 0;
}

int isFull()
{
    return (rear + 1) % MAX == front ? 1 : 0;
}

void enQueue(int x)
{
    if (isFull())
    {
        printf("queue is full\n");
        return;
    }
    if (isEmpty())
        front = rear = 0;
    else
        rear = (rear + 1) % MAX;

    arr[rear] = x;
}
void deQueue()
{
    if (isEmpty())
    {
        printf("queue is empty\n");
        return;
    }
    else if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX;
}

void Display()
{
    int length = (rear + MAX - front) % MAX + 1;
    int i;
    for (i = 0; i < length; i++)
    {
        printf("%d ", arr[(front + i) % MAX]);
    }
    printf("\n");
}

int main()// use a switch case too
{
    front = -1;
    rear = -1;
    enQueue(11);
    enQueue(22);
    enQueue(33);
    Display();
    deQueue();
    Display();
    enQueue(44);
    Display();
    return 0;
}
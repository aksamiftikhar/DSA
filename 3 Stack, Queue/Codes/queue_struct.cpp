
#include <stdio.h>
#define SIZE 10


struct queue
{
    int data[SIZE];
    int front, back;
};
int isFull(struct queue myQueue)
{
    return myQueue.back==SIZE-1;
}
void enqueue(struct queue *myQueue, int e)
{
    if(isFull(*myQueue)) // Stub
    {
        printf("Queue overflow!");
    }
    else
    {
        myQueue->back=myQueue->back+1;
        myQueue->data[myQueue->back] = e;

        if(myQueue->front==-1)
            myQueue->front = 0;
    }
}

int dequeue(struct queue *myQueue)
{
    int e;
    if(isEmpty(*myQueue)) // Stub
    {
        printf("Queue overflow!");
    }
    else
    {
        e = myQueue->data[myQueue->front];
        if(myQueue->back==myQueue->front) // only 1 element
        {
            myQueue->back = -1;
            myQueue->front = -1;
        }
        else
            myQueue->front=myQueue->front+1;
    }
    return e;
}
int isEmpty(struct queue myQueue)
{
    return myQueue.front==-1 && myQueue.back==-1;
}
int peek_front(struct queue myQueue)
{
    return myQueue.data[myQueue.front];
}
int main()
{
    struct queue myQueue = {{0}, -1, -1};
    enqueue(&myQueue, 30);
    enqueue(&myQueue, 56);
    enqueue(&myQueue, 23);
    int x = dequeue(&myQueue);
    printf("%d\n", x);
    x = dequeue(&myQueue);
    printf("%d\n", x);
    x = dequeue(&myQueue);
    printf("%d", x);

    return 0;
}

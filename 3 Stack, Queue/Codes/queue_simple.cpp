
#include <stdio.h>
#define SIZE 10


    
void enqueue(int queue[], int *front, int *back, int e)
{
    if(isFull(*back)) // Stub
    {
        printf("Queue overflow!");
    }
    else
    {
        *back=*back+1;
        queue[*back] = e;
        
        if(*front==-1)
            *front = 0;
    }
}
int isFull(int back)
{
    return back==SIZE-1;
}
int dequeue(int queue[], int *front, int *back)
{
    int e;
    if(isEmpty()) // Stub
    {
        printf("Queue overflow!");
    }
    else
    {
        e = queue[*front];
        if(*back==*front) // only 1 element 
        {
            *back = -1;
            *front = -1;
        }
        else
            *front=*front+1;
    }
    return e;
}
int isEmpty(int front, int back)
{
    return (front==-1 && back ==-1);
}
int peek_front(int queue[], int front)
{
    return queue[front];
}
int main()
{
    
    int back=-1, front=-1;
    int queue[SIZE] = {0};
    // _ _ _
    enqueue(queue, &front, &back, 30); // (f,b)30 _ _ 
    enqueue(queue, &front, &back, 39); // (f)30 b(39) _
    enqueue(queue, &front, &back, 21); // (f)30 39 b(21)
    
    printf("\n%d", peek_front(queue, front));
    int x = dequeue(queue, &front, &back);
    printf("\n%d", x);
    x = dequeue(queue, &front, &back);
    printf("\n%d", x);
    x = dequeue(queue, &front, &back);
    printf("\n%d", x);
    
    return 0;
}

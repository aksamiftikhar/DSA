
#include <stdio.h>
#define SIZE 10


struct book
{
    char book_name[100];
    int ISSN;
    char author_name[100];
};
struct book_queue
{
    struct book data[SIZE];
    int front, back;
};
int isFull(struct book_queue myQueue)
{
    return myQueue.back==SIZE-1;
}
void enqueue(struct book_queue *myQueue, struct book e)
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

struct book dequeue(struct book_queue *myQueue)
{
    struct book e;
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
int isEmpty(struct book_queue myQueue)
{
    return myQueue.front==-1 && myQueue.back==-1;
}
struct book peek_front(struct book_queue myQueue)
{
    return myQueue.data[myQueue.front];
}
int main()
{
    struct book_queue myQueue;
    myQueue.front = -1;
    myQueue.back = -1;
    struct book myBook = {"Easy C", 420, "Allah ditta"};
    enqueue(&myQueue, myBook);
    struct book myBook2 = {"Meri kitab", 786, "Allah rakha"};
    enqueue(&myQueue, myBook2);
    struct book myBook3 = {"Teri kitab", 9211, "Rab nawaz"};
    enqueue(&myQueue, myBook3);
    struct book x = dequeue(&myQueue);
    printf("%s\n", x.book_name);
    x = dequeue(&myQueue);
    printf("%s\n", x.book_name);
    x = dequeue(&myQueue);
    printf("%s", x.book_name);
    
    return 0;
}

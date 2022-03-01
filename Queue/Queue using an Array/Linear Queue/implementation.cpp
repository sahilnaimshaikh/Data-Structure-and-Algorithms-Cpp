#include <iostream>
using namespace std;
// creating the userdefined datatype named as queue.
struct queue
{
    int capacity;   // maximum no. of element that can be present in the queue.
    int frontIndex; // (index  of the first element)-1
    int rearIndex;  // index of the last element
    int *arr;
};

int isEmpty(queue *myQueue)
{
    if (myQueue->frontIndex == myQueue->rearIndex)
    {
        return 1;
    }
    return 0;
}
int isFull(queue *myQueue)
{
    if (myQueue->rearIndex == myQueue->capacity - 1)
    {
        return 1;
    }
    return 0;
}
void enqueue(queue *myQueue, int element)
{
    if (!isFull(myQueue))
    {
        myQueue->rearIndex++;
        myQueue->arr[myQueue->rearIndex] = element;
    }
    else
    {
        cout << "Queue is full, Can't enqueue." << endl;
    }
}

void dequeue(queue *myQueue)
{
    if (!isEmpty(myQueue))
        myQueue->frontIndex++;
    else
        cout << "Queue is already Empty";
}
void display(queue *myQueue)
{
    if (!isEmpty(myQueue))
    {
        for (int i = myQueue->frontIndex + 1; i < myQueue->rearIndex + 1; i++)
        {
            cout << myQueue->arr[i] << " ";
        }
        cout << endl;
    }
    else
        cout << "Queue is Empty, nothing to display.";
}
int firstVal(queue *myQueue)
{
    return myQueue->arr[myQueue->frontIndex + 1];
}
int lastVal(queue *myQueue)
{
    return myQueue->arr[myQueue->rearIndex];
}

int main()
{
    struct queue *myQueue = (queue *)malloc(sizeof(queue));

    myQueue->capacity = 4;
    myQueue->arr = (int *)malloc(myQueue->capacity * sizeof(int));
    myQueue->rearIndex = -1, myQueue->frontIndex = -1;

    enqueue(myQueue, 7);
    enqueue(myQueue, 34);
    enqueue(myQueue, 89);
    enqueue(myQueue, 389);

    dequeue(myQueue);
    dequeue(myQueue);
    dequeue(myQueue);
    dequeue(myQueue);

    enqueue(myQueue, 89);
    display(myQueue);

    return 0;
}
// There are certain drawbacks of the this queue. Thats why we use Circular Queue for efficient use of memory.
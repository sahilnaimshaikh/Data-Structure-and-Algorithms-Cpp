#include <iostream>
using namespace std;
// creating the userdefined datatype named as queue.
struct circularQueue
{
    int capacity;   // maximum no. of element that can be present in the queue.
    int frontIndex; // (index  of the first element)-1
    int rearIndex;  // index of the last element
    int *arr;
};

int isEmpty(circularQueue *myQueue)
{
    if (myQueue->frontIndex == myQueue->rearIndex)
    {
        return 1;
    }
    return 0;
}
int isFull(circularQueue *myQueue)
{
    if ((myQueue->rearIndex+1) % myQueue->capacity == myQueue->frontIndex)
    {
        return 1;
    }
    return 0;
}
void enqueue(circularQueue *myQueue, int element)
{
    if (!isFull(myQueue))
    {
        myQueue->rearIndex = (myQueue->rearIndex+1) % myQueue->capacity;
        myQueue->arr[myQueue->rearIndex] = element;
    }
    else
    {
        cout << "Queue is full, Can't enqueue." << endl;
    }
}

void dequeue(circularQueue *myQueue)
{
    if (!isEmpty(myQueue))
       myQueue->frontIndex =  (myQueue->frontIndex+1) % myQueue->capacity;
    else
        cout << "Queue is already Empty";
}
void display(circularQueue *myQueue)
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
int firstVal(circularQueue *myQueue)
{
    return myQueue->arr[myQueue->frontIndex + 1];
}
int lastVal(circularQueue *myQueue)
{
    return myQueue->arr[myQueue->rearIndex];
}

int main()
{
    struct circularQueue *myQueue = (circularQueue *)malloc(sizeof(circularQueue));

    myQueue->capacity = 20;
    myQueue->arr = (int *)malloc(myQueue->capacity * sizeof(int));
    myQueue->rearIndex =  0, myQueue->frontIndex = 0;

    enqueue(myQueue, 7);
    enqueue(myQueue, 34);
    enqueue(myQueue, 89);
    enqueue(myQueue, 389);

    dequeue(myQueue);
    dequeue(myQueue);
    dequeue(myQueue);
    dequeue(myQueue);

    enqueue(myQueue, 89);
    enqueue(myQueue, 389);
    
    display(myQueue);

    return 0;
}
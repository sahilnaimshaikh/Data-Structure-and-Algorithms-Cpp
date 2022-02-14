#include <iostream>
#include <stdlib.h>
using namespace std;

struct stack
{
        int size;
        int topElementIndex;
        int *arr;
};

int isEmpty(struct stack *stack1)
{
        if (stack1->topElementIndex == -1)
        {
                return 1;
        }
        return 0;
}
int isFull(struct stack *stack1)
{
        if (stack1->topElementIndex == stack1->size - 1)
        {
                return 1;
        }
        return 0;
}
void push(struct stack *stack1, int element)
{
        if (!isFull(stack1))
        {
                stack1->topElementIndex++;
                stack1->arr[stack1->topElementIndex] = element;
        }
        else
        {
                cout << " Stack Overflow, Cannot push element." << endl;
        }
}
void pop(struct stack *stack1)
{
        if (!isEmpty(stack1))
        {
                stack1->topElementIndex--;
        }
        else
        {
                cout << "Stack Underflow" << endl;
        }
}
int peek(struct stack *stack1, int peekNumber)
{
        int peekIndex = stack1->topElementIndex - peekNumber + 1;
        int valueAtPeekIndex = stack1->arr[peekIndex];
        if (peekIndex < 0)
        {
                cout << "Invalid Index number" << endl;
        }
        else
        {
                return valueAtPeekIndex;
        }
}

void checkPeeks(struct stack *stack1)
{
        cout << "Checking Peeks" << endl;
        for (int i = 0; i <= stack1->topElementIndex; i++)
        {

                cout << "Value at " << i + 1 << " from top of the stack is:" << peek(stack1, i + 1) << endl;
                /* code */
        }
}
int stackTop(struct stack *stack1)
{       if (!isEmpty(stack1))
        {
        int valueAtTop = stack1->arr[stack1->topElementIndex];
        return valueAtTop;
        }
        else{
                return -1;
        }
}
int stackBottom(struct stack *stack1)
{
        if (!isEmpty(stack1))
        {
                int valueAtBottom = stack1->arr[0];
                return valueAtBottom;
        }
        else{
                return -1;
        }
}

int main()
{
        struct stack *stack1 = (struct stack *)malloc(sizeof(struct stack));
        stack1->size = 5;
        stack1->topElementIndex = -1;
        stack1->arr = (int *)malloc(stack1->size * sizeof(int));

        push(stack1, 5);
        push(stack1, 554);
        push(stack1, 458);
        push(stack1, 98);
        push(stack1, 778);
        // checkPeeks(stack1);
        cout << "Element at the Top of the stack is " << stackTop(stack1) << endl;
        cout << "Element at the Bottom of the stack is " << stackBottom(stack1) << endl;
       

        // if(isFull(stack1))cout<<" It is Full"<<endl;
        pop(stack1);
        pop(stack1);
        pop(stack1);
        pop(stack1);
        pop(stack1);
         cout << "Element at the Top of the stack is " << stackTop(stack1) << endl;
        cout << "Element at the Bottom of the stack is " << stackBottom(stack1) << endl;
        // display(stack1);
        // if(isFull(stack1))cout<<" It is Full"<<endl;
        // else cout<<" not full";
        // display(stack1);

        return 0;
}
#include <iostream>
#include<stdlib.h>
using namespace std;

struct node
{
    int data;
    node *next;
};
node *f = NULL;
node *r = NULL;

int isEmpty()
{
    if (f == NULL)
    {
        return 1;
    }
    return 0;
}
void linkedListTraversal(struct node *ptr)
{
    printf("Printing the elements of this linked list\n");
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}
void enque(int val)
{
    node *n = (node *)malloc(sizeof(node));

    if (n == NULL)
    {
        cout << "Queue is full";
    }
    else
    {
        n->data = val;
        n->next = NULL;
        if (isEmpty())
        {
            f = r = n;
        }
        else
        {
            r->next = n;
            r = n;
        }
    }
}

int deque()
{
    int val = -1;
    if(isEmpty()){
        return val;
    }
    else{
        node* ptr = (node*)malloc(sizeof(node));
        ptr = f;
        f = f->next;
        val = ptr->data;
        free(ptr);
        return val;
    }
}
int main()
{
     
    enque(6);
    enque(56);
    enque(8);
    // deque();
    enque(844);
    enque(42);
    // deque();
    enque(76);

    // cout<<"Dequeing the element:"<<deque();
    linkedListTraversal(f);
    

    return 0;
}
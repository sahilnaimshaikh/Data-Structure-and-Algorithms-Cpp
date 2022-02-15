#include <iostream>
using namespace std;

struct stack
{
    int size;
    int topElementIndex;
    char *arr;
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
void push(struct stack *stack1, char element)
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
char pop(struct stack *stack1)
{
    if (!isEmpty(stack1))
    {   char element = stack1->arr[stack1->topElementIndex];
        stack1->topElementIndex--;
        return element;
    }
    else
    {
        cout << "Stack Underflow" << endl;
    }
}
int match(char a, char b){
    if(a=='{' && b=='}' || a=='[' && b==']' || a=='(' && b==')'){
        return 1;
    }
    return 0;
}
int matchParenthesis(string exp)
{
    struct stack *q = (struct stack *)malloc(sizeof(struct stack));
    q->size = 100;
    q->topElementIndex = -1;
    q->arr = (char *)malloc(q->size * sizeof(char));
    char poppedElement;

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(q, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (isEmpty(q))
            {
                return 0;
            }
           poppedElement =  pop(q);
           if(!match(poppedElement, exp[i])){
               return 0;
           }
        }

        
    }
    if (isEmpty(q))
        {
            return 1;
        }
        else{
            return 0;
        }
        
}
int main()
{   
string exp = "{4[2+5/4 x 5+4/8]";//initializing the expression to be passed
    
    if(matchParenthesis(exp))cout<<"This is a valid expression";
    else cout<<"This is not a valid expression";

    return 0;
}

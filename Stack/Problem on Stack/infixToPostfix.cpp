#include <iostream>
#include <string.h>
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
int stackTop(struct stack *stack1)
{
    if (!isEmpty(stack1))
    {
        int valueAtTop = stack1->arr[stack1->topElementIndex];
        return valueAtTop;
    }
    else
    {
        return -1;
    }
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
    {
        char element = stack1->arr[stack1->topElementIndex];
        stack1->topElementIndex--;
        return element;
    }
    else
    {
        cout << "Stack Underflow" << endl;
    }
}
int isOperator(char element)
{
    if (element == '+' || element == '-' || element == '*' || element == '/')
    {
        return 1;
    }
    return 0;
}
int precedence(char element)
{

    if (element == '+' || element == '-')
    {
        return 1;
    }
    else if (element == '*' || element == '/')
    {
        return 2;
    }
}

void inToPo(string infixExpression)
{
    struct stack *operators = (struct stack *)malloc(sizeof(struct stack));
    operators->size = infixExpression.size();
    operators->topElementIndex = -1;
    operators->arr = (char *)malloc(operators->size * sizeof(char));

    char *postfixExpression = (char *)malloc(sizeof(char));
    int j = 0;
    for (int i = 0; infixExpression[i] != '\0'; i++)
    {
        if (!isOperator(infixExpression[i]))
        {
            postfixExpression[j] = infixExpression[i];
            j++;
        }
        else
        {
            if (isEmpty(operators))
            {
                push(operators, infixExpression[i]);
            }
            else
            {
                if (precedence(infixExpression[i]) > precedence(stackTop(operators)))
                {
                    push(operators, infixExpression[i]);
                }
                else
                {   
                    while(precedence(infixExpression[i]) <= precedence(stackTop(operators)))
                    {
                        postfixExpression[j] = pop(operators);
                        j++;
                    }
                    push(operators, infixExpression[i]);
                    
                }
            }
        }
    }
    while (!isEmpty(operators))
    {
        postfixExpression[j] = pop(operators);
        j++;
    }
    cout << postfixExpression;
}

int main()
{
    string infixExpression = "3+2*2*5";
    inToPo(infixExpression);

    return 0;
}
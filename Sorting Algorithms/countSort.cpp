#include <iostream>
#include <limits.h>
using namespace std;

void displayArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}
void countSort(int *A, int n){
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if(max<A[i]){
            max = A[i];
        }
    }
    // creating an array of size of max+1.
    int * dynamicArray = (int *)malloc((max+1)*sizeof(int));
    for (int i = 0; i < max+1; i++)
    {
        dynamicArray[i] = 0;
    }

    for (int j = 0; j < n; j++)
    {
        dynamicArray[A[j]]++;
    }
    int s = 0;
    for (int k = 0; k <= max; k++)
    {
        if (dynamicArray[k] > 0)
        {
            A[s] = k;
            s++;
        }
       
    }
   
}
int main()
{
    int A[] = {13, 5, 22, 7, 99, 11};
    int n = sizeof(A) / sizeof(int);
    
    displayArray(A, n);
    countSort(A,n);
    displayArray(A, n);

    return 0;
}
#include <iostream>
using namespace std;

void bubbleSort(int *A, int n)
{   
    int isSorted = 0;
    for (int i = 0; i < n - 1; i++)
    {   
        cout<<"Working on Pass "<<i+1<<endl;
        isSorted = 1;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (A[j] > A[j + 1])
            {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                isSorted = 0;
            }
        }
        if(isSorted){
            return;
        }
    }
}
void displayArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main()
{

    int A[] = {1,2,3,4,5,7,6,8,9};
    int n = 9;
    displayArray(A, n);
    bubbleSort(A, n);
    displayArray(A, n);

    return 0;
}
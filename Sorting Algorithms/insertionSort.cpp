#include <iostream>
using namespace std;

void displayArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}
void insertionSort(int *A, int n){

    for (int i = 1; i <= n-1; i++)
    {
        int key = A[i];
        int j = i-1;
        while (j>=0 && A[j]<key)//if A[j]>key is used in while loop  then the Array is sorted in Ascending 
                                  // or if A[j]<keyy is used then the array is sorted in descending order.
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
        
    }
    
}

int main()
{
    int A[] = {34,54,2,65,7,4,87};
    int n = sizeof(A)/sizeof(int);
    displayArray(A, n);
    insertionSort(A, n);
    displayArray(A, n);
    return 0;
}
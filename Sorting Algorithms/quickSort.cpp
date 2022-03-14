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
int partition(int A[], int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;

    do
    {
        while (A[i] <= pivot)
        {
            i++;
        }
        cout << "i = "<<i << endl;
        while (A[j] > pivot)
        {
            j--;
        }
        cout <<"j= "<<j << endl;
        if (i < j)
        {
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i < j);
    // when the value of the pivot is the max in the array, the value of i will be incremented higher than the high,
    // in this case while condition of doWhile loop will become false.

    int temp = A[low];
    A[low] = A[j];
    A[j] = temp;

    return j;
}
void quickSort(int A[], int low, int high)
{
    if (low < high)
    {
        displayArray(A, 6);
        int partitionIndex = partition(A, low, high);

        quickSort(A, low, partitionIndex - 1);
        quickSort(A, partitionIndex + 1, high);
    }
}
int main()
{
    int A[] = {888, 43, 23, 557, 223, 556};
    int n = sizeof(A) / sizeof(int);
    // displayArray(A, n);
    quickSort(A, 0, n - 1);
    displayArray(A, n);

    return 0;
}
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
void merge(int *A , int low, int mid , int high ){
    int i,j,k;
    i = low;
    j = mid+1;
    k = low;
    int B[100];
    while(i<=mid && j<=high){
        if(A[i]<A[j]){
            B[k] = A[i];
            k++;
            i++;
        }
        else{
            B[k] = A[j];
            k++;
            j++;
        }
    }
    while(i<=mid){
        B[k] = A[i];
        i++;
        k++;
    }
    while(j<=high){
        B[k] = A[j];
        j++;
        k++;
    }
    for (int b = 0; b <= high; b++)
    {
       A[b] = B[b];
    }
    
}
void mergeSort(int *A, int low, int high){
    int mid;
    if(low<high){
        mid = (low+high)/2;
        mergeSort(A, low, mid);
        mergeSort(A, mid+1, high);
        merge(A, low, mid, high);

    }
}

int main()
{
    int A[] = {888, 4223, 123, 1557, 223, 556};
    int n = sizeof(A) / sizeof(int);
    displayArray(A, n);
    mergeSort(A, 0, n - 1);
    displayArray(A, n);


    return 0;
}

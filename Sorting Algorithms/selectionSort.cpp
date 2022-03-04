#include<iostream>
using namespace std;
void displayArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}     
void swap(int &A, int &B){
    int temp = A;
    A = B;
    B = temp;
}       
void selectionSort(int *A, int n){
    int indexOfMin;
    for (int i = 0; i <= n-1; i++)
    {
        indexOfMin = i;
        for (int j = i+1; j <= n-1; j++)
        {
            if (A[j]<A[indexOfMin])
            {
                indexOfMin = j;
            }
            
        }
        swap(A[indexOfMin],A[i]);
        
    }
    
}          
int main(){

       int A[] = {43,23,557,223,556};
       int n = sizeof(A)/sizeof(int);
       displayArray(A, n);
       selectionSort(A, n);     
       displayArray(A, n);
        
            
return 0;
}
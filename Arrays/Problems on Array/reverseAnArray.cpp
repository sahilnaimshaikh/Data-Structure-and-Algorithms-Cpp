#include<iostream>
using namespace std;

void reverseArray(int *A, int n){
    for (int i = 0; i < n/2; i++)
    {
        int temp = A[i];
        A[i] = A[n-i-1];
        A[n-i-1] = temp;
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
            
int main(){
            
        int A[] = {34,6,23,7,4};
        int n = sizeof(A)/sizeof(int);
        displayArray(A, n);
        reverseArray(A, n);
        displayArray(A, n);
            
return 0;
}
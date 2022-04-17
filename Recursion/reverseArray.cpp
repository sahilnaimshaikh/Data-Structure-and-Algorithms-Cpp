// Quick Note: Arrays are always passed as call by reference 

#include<bits/stdc++.h>
using namespace std;

  void reverse(int i, int arr[], int n){

      if(i>=n/2) return;
      swap(arr[i], arr[n-i-1]);
      reverse(i+1, arr, n);
  }          
            
int main(){
            
    int arr[] = {2,5,3,6,7,4};
    int n = sizeof(arr)/sizeof(int);
    // for(int i = 0; i < n; i++) cout<<arr[i]<<" ";
    reverse(0,arr,n);
    
    for(int i = 0; i < n; i++) cout<<arr[i]<<" ";

return 0;
}

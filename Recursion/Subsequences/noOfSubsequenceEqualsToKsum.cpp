
#include<bits/stdc++.h>
using namespace std;
            
    int sequence(int i, int arr[],  int n, int k, int sum){

        if(i>=n){
            if(sum==k){ // if the sum is equal to the given K then the subsequence will be printed
             return 1;
            }
           else  return 0; 
        }
        // if considering the arr[i] in the subsequence 
        
        sum += arr[i]; // updating the sum

       int pick = sequence(i+1, arr,  n, k, sum);

        // if not considering the arr[i] in the subsequence 
        sum-=arr[i];    // updating the sum
      int notPick =  sequence(i+1, arr, n, k, sum);

       return pick+notPick;

    }

int main(){

    int arr[] = {2,4,3,5,7};
    int n = sizeof(arr)/sizeof(int);
    vector<int> seq;
    int k = 7;
    cout<<sequence(0, arr, n, k, 0);
        
            
return 0;
}
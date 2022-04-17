#include<bits/stdc++.h>
using namespace std;
            
    void sequence(int i, int arr[], vector<int> seq, int n, int k, int sum){

        if(i>=n){
            if(sum==k){ // if the sum is equal to the given K then the subsequence will be printed
            for (auto it: seq)
             {
                 cout<<it<<" ";
             }
             cout<<endl;
            }
            return; // if the index reaches the last index then return
        }
        // if considering the arr[i] in the subsequence 
        seq.push_back(arr[i]);// psuhing the element in the subsequence
        sum += arr[i]; // updating the sum
        sequence(i+1, arr, seq, n, k, sum); // calling the function for the next index

        // if not considering the arr[i] in the subsequence 
        seq.pop_back(); //poping the already pushed element 
        sum-=arr[i];    // updating the sum
         sequence(i+1, arr, seq, n, k, sum);// calling the function for the next index

    }

int main(){

    int arr[] = {2,4,3,5,7};
    int n = sizeof(arr)/sizeof(int);
    vector<int> seq;
    int k = 7;
    sequence(0, arr, seq, n, k, 0);
        
            
return 0;
}
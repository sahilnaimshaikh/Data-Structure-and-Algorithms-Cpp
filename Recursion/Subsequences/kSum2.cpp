// this is as same as the ksumSubsequence but in this program only one subsequence will be printed ... 
#include<bits/stdc++.h>
using namespace std;
            
    bool sequence(int i, int arr[], vector<int> seq, int n, int k, int sum){

        if(i>=n){
            if(sum==k){ // if the sum is equal to the given K then the subsequence will be printed
            for (auto it: seq)
             {
                 cout<<it<<" ";
             }
             cout<<endl;
             return true;
            }
           else  return false; 
        }
        // if considering the arr[i] in the subsequence 
        seq.push_back(arr[i]);// psuhing the element in the subsequence
        sum += arr[i]; // updating the sum

       if(sequence(i+1, arr, seq, n, k, sum) == true) return true;

        // if not considering the arr[i] in the subsequence 
        seq.pop_back(); //poping the already pushed element 
        sum-=arr[i];    // updating the sum
       if( sequence(i+1, arr, seq, n, k, sum)==true ) return true;

       return false;

    }

int main(){

    int arr[] = {2,4,3,5,7};
    int n = sizeof(arr)/sizeof(int);
    vector<int> seq;
    int k = 7;
    sequence(0, arr, seq, n, k, 0);
        
            
return 0;
}
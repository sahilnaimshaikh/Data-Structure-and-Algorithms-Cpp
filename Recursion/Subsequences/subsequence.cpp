// subsequence is nothing but a powerset... 

#include<bits/stdc++.h>
using namespace std;

     void print(int i, vector<int> &set, int arr[], int n)  {

         if(i>=n){
             if(set.size()==0)cout<<"[]"<<endl;
             for (auto it: set)
             {
                 cout<<it<<" ";
             }
             cout<<endl;
             return;
         }
        set.emplace_back(arr[i]);
        print(i+1, set, arr, n);
        set.pop_back();
        print(i+1,set,arr,n);
     }    

      
int main(){
            
        int arr[] = {1,2,3,4};
        int n = sizeof(arr)/sizeof(int);
        vector<int> set;
        print(0,set,arr,n);
            
return 0;
}
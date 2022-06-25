// subsequence is nothing but a powerset... 

#include<bits/stdc++.h>
using namespace std;

     void print(int i, vector<int> &set, vector<int> &arr, int n,  vector<vector<int>> &ans)  {

         if(i>=n){
            //  if(set.size()==0)cout<<"{ }"<<endl;
             ans.push_back(set);
             return;
         }
        set.emplace_back(arr[i]);
        print(i+1, set, arr, n, ans);
        set.pop_back();
        print(i+1,set,arr,n,ans);
     }    
    vector<vector<int>> subsets(vector<int> &arr) {
        
         vector<int> set;
         vector<vector<int>> ans;
        print(0,set,arr,arr.size(), ans);
        return ans;
    }
      
int main(){
            
        vector<int> arr =  {1,2,3,4};
        for(auto it : subsets(arr)){
            for(auto i : it)cout<<i<<" ";
            cout<<endl;
        }

       
            
return 0;
}
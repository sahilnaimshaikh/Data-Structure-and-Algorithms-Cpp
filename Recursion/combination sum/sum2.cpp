#include<bits/stdc++.h>
using namespace std;

   void find(int index, int target, vector<vector<int>> &ans, vector<int> &ds, vector<int> &arr){

        if(target==0){
            ans.push_back(ds);
            return;
        }
        for (int i = index ; i < arr.size(); i++)
        {
            
            if(i>index && arr[i]==arr[i-1])continue;
            if(arr[i]>target) break;
            ds.push_back(arr[i]);
            find(i+1, target-arr[i], ans, ds,arr);
            ds.pop_back();
        }
        
   }      

 vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

     vector<vector<int>> ans;
     vector<int> ds;
     sort(candidates.begin(), candidates.end());
     find(0, target, ans, ds, candidates);
        return ans;

    }



int main(){
      vector<int> candidates = {1,1,1,2,2};
      int target = 4;
      vector<vector<int>> ans = combinationSum2(candidates, target);      
       for (auto it : ans)
       {
           for (auto i: it)
           {
               cout<<i<<" ";
           }
           cout<<endl;
       }
            
return 0;
}
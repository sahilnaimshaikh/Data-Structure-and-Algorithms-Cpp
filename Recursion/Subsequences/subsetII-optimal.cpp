#include<bits/stdc++.h>
using namespace std;

    void gen(int ind,vector<int> &nums,vector<int> &ds,vector<vector<int>> &res){
        res.emplace_back(ds);
        for (int i = ind; i < nums.size(); i++)
        {
            if(i != ind && (nums[i]==nums[i-1])) continue;
            ds.emplace_back(nums[i]);
            gen(i+1, nums, ds, res);
            ds.pop_back();
        }
    
    }
   vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<int> ds;
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        gen(0, nums, ds, res);
        return res;
    
    }         
            
int main(){
            
         vector<int> arr =  {0,1,1,2};
        for(auto it : subsetsWithDup(arr)){
            for(auto i : it)cout<<i<<" ";
            cout<<endl;
        }
            
return 0;
}
#include<bits/stdc++.h>
using namespace std;

    void generateSubset(int i, vector<int> &nums, set<vector<int>> &set, vector<int> ds){

        if(i == nums.size()){
            sort(ds.begin(), ds.end());
            set.insert(ds);
            return;
        }
        ds.push_back(nums[i]);
        generateSubset(i+1, nums, set, ds);
        ds.pop_back();
        generateSubset(i+1, nums, set, ds);
         return ;
    }
            
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        set<vector<int>> set;
        vector<vector<int>> result;
        vector<int> ds;
        generateSubset(0, nums, set, ds);
        for(auto it : set){
            result.push_back(it);
        }
        return result;
    }
            
int main(){
            
            
        vector<int> arr =  {0,1,2};
        for(auto it : subsetsWithDup(arr)){
            for(auto i : it)cout<<i<<" ";
            cout<<endl;
        }
            
return 0;
}
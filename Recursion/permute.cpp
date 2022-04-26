#include<bits/stdc++.h>
using namespace std;

    void findPermute(vector<int> &ds , vector<int> &nums, vector<vector<int>> &ans, int freq[]){

        if(ds.size()==nums.size()){
            ans.push_back(ds);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(!freq[i]){
                freq[i] = 1;
                ds.push_back(nums[i]);
                findPermute(ds, nums, ans, freq);
                freq[i] = 0;
                ds.pop_back();
            }
        }
    }
               
   vector<vector<int>> permute(vector<int> &nums) {
        
    vector<vector<int>> ans;
    vector<int> ds;
    int freq[nums.size()];
    for(int i = 0 ; i < nums.size(); i++) freq[i] = 0;
    findPermute(ds, nums, ans, freq);
    return ans;

    }    
          
int main(){
          
        vector<int> nums = {1,2,3};
       vector<vector<int>> ans =  permute(nums);
        for (auto it : ans)
        {
           for(auto i: it){
               cout<<i<<" ";
           }
           cout<<endl;
        }
          
          
return 0;
}
#include<bits/stdc++.h>
using namespace std;

void findPermute(int index,vector<int> &nums, vector<vector<int>> &ans){
    if(index == nums.size()){
        ans.push_back(nums);
        return;
    }
    for(int i = index; i< nums.size(); i++){
        swap(nums[index], nums[i]);
        findPermute(index+1, nums, ans);
        swap(nums[index], nums[i]);
    }

}              

vector<vector<int>> permute(vector<int> &nums) {
        
    vector<vector<int>> ans;
    findPermute(0,nums, ans);
    sort(ans.begin(), ans.end());
    return ans;
    }    
          
          
int main(){
        vector<int> nums = {1,2,3,4,5};
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
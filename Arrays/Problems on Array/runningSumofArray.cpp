#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
     vector<int> runningSum(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum = sum + nums[i];
            res[i] = sum;
        }
        return res;
    }      
};
          
int main(){
          
    vector<int> nums = {1,1,1,1,1,1};
    Solution sol;
    for(auto it : sol.runningSum(nums)){
        cout<<it<<" ";
    }
          
          
return 0;
}
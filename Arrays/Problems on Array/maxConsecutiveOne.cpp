#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
     int findMaxConsecutiveOnes(vector<int>& nums) {
         int max = 0, count = 0;
       for (int i = 0; i < nums.size(); i++)
       {
           if(nums[i]==1){
               count++;
               if(count > max) max = count;
           }
           else{
               count = 0;
           }
       }
       return max; 
    }      
};
          
int main(){
          
    vector<int> nums = {1,0,1,1,0,1,1,1};
    Solution sol;
    cout<<sol.findMaxConsecutiveOnes(nums);
          
          
return 0;
}
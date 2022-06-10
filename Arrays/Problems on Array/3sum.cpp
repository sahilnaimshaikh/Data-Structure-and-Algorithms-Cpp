#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
     vector<vector<int>> threeSum(vector<int>& nums) {

       vector<vector<int>> result;
       if(nums.size()< 3) return result;
       sort(nums.begin(), nums.end());
       for (int i = 0; i < nums.size()-2; i++)
       {
           if(i==0 || (i>0 && nums[i] != nums[i-1])){
           int low = i+1, high = nums.size()-1 ,sum = -1*nums[i];
                while(low<high){
                    if(nums[low]+nums[high] == sum){
                        vector<int> temp;
                        temp.emplace_back(nums[low]);
                        temp.emplace_back(nums[high]);
                        temp.emplace_back(nums[i]);
                        result.push_back(temp);

                        while (low<high && nums[low]==nums[low+1])
                        {
                            low++;
                        }
                        while (low<high && nums[high]==nums[high-1])
                        {
                            high--;
                        }
                        low++,high--;
                    }
                    else if(nums[low]+nums[high]>sum) high--;
                    else low++;

                }
           }
       }
        return result;
    }      
};
          
int main(){
          
  vector<int> nums = {0,0,0};
  Solution sol;
  for(auto it : sol.threeSum(nums)){
      for(auto i : it){
          cout<<i<<" ";
      }
      cout<<endl;
  }  
          
          
return 0;
}
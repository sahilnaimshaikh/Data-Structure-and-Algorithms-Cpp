#include<bits/stdc++.h>
using namespace std;

 vector<int> sortedSquares(vector<int>& nums) {

    for (int i = 0; i < nums.size(); i++)
    {
        nums[i] = pow(nums[i],2);
    }
     sort(nums.begin(), nums.end());      

    return nums;
 }               
          
          
int main(){
          
 vector<int> nums = {-7,-3,2,3,11};
          
  for(auto it : sortedSquares(nums))cout<<it<<" ";        
          
return 0;
}
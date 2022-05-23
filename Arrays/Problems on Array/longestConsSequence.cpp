#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
     int longestConsecutive(vector<int>& nums) {
     int  n = nums.size();
     int max = 1;
     int count = 1;
     if(n==0) return 0;
     set<int> s1;
     vector<int> uniqueNum;
     for (int i = 0; i < n; i++)
     {
         s1.insert(nums[i]);
     }
     
     for(auto it : s1){
         uniqueNum.emplace_back(it);
     }
   int m = uniqueNum.size();
     for(int i = 1 ; i< m; i++){
         if(uniqueNum[i]==uniqueNum[i-1]+1) count++;
         else(count = 1);
         if(count>max)max=count;
     }
     return max;
    }      
};
          
int main(){
     vector<int> nums= {1,2,0,1};
     Solution sol;
     cout<<sol.longestConsecutive(nums);     
    
          
          
return 0;
}
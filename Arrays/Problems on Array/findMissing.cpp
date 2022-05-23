#include<bits/stdc++.h>
using namespace std;

 int missingNumber(vector<int>& nums) {
     vector<int> map(nums.size()+1,0);
    int missing;
     for(int i = 0; i<nums.size();i++){
         map[nums[i]]++;
     }  
     for(int i = 0; i<map.size(); i++){
         if(map[i]== 0) missing = i;
     } 
     return missing;
    }              
          
          
int main(){
          
 vector<int> nums = {9,6,4,2,3,5,7,0,1};         
 cout<<missingNumber(nums);         
          
return 0;
}
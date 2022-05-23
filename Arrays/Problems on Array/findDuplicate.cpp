#include<bits/stdc++.h>
using namespace std;
               
   int findDuplicate(vector<int>& nums) {
     vector<int> map(nums.size(),0);
     int duplicate ;
     for (int i = 0; i < nums.size(); i++)
     {
         map[nums[i]]++;
     }
     for(int i = 1; i<map.size(); i++){
         if(map[i]>1)duplicate= i;
     }
    return duplicate;
    }         
          
int main(){
          
 vector<int> nums = {1,3,4,2,2};
 cout<<findDuplicate(nums);         
          
          
return 0;
}
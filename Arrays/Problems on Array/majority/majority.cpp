#include<bits/stdc++.h>
using namespace std;
    // the below algorithm is known as moore voting algorithm            
  int majorityElement(vector<int>& nums) {
     int count = 0;
     int candidate = 0 ;
     for (int  i = 0; i < nums.size(); i++)
     {
         if(count == 0) candidate = nums[i];
         if(nums[i]==candidate)count++;
         else count--;
     }
     return candidate;
    }         
          
int main(){
          
vector<int> nums = {1,1,2,1,2,1,2,1,2,1};
cout<<majorityElement(nums);       
          
          
return 0;
}
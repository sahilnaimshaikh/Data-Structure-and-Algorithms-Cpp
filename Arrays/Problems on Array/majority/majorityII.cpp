#include<bits/stdc++.h>
using namespace std;
               
 vector<int> majorityElement(vector<int>& nums) {
     vector<int> result;
     int num1=-1,num2 =-1;
     int count1=0,count2=0;
     for (int i = 0; i < nums.size(); i++)
     {
         if(nums[i]==num1)count1++;
         else if(nums[i]==num2)count2++;
         else if(count1 == 0){
             num1 = nums[i];
             count1++;
         }
         else if(count2 == 0){
             num2 = nums[i];
             count2++;
         }
         else {
             count1--;
             count2--;
         }
     }
     count1=0, count2= 0;
     for(int i = 0; i<nums.size(); i++){
         if(nums[i] == num1)count1++;
         else if(nums[i] == num2) count2++;

     }
     if(count1>nums.size()/3) result.push_back(num1);
     if(count2>nums.size()/3) result.push_back(num2);
     return result;
    }          
          
int main(){
          
    vector<int> nums= {3,2,3};
    for(auto it: majorityElement(nums)){
        cout<<it<<" ";
    } 
          
return 0;
}
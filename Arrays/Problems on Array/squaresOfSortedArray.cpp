#include<bits/stdc++.h>
using namespace std;
//brute force approach O(n + nlogn)
 vector<int> sortedsSquares(vector<int>& nums) {

    for (int i = 0; i < nums.size(); i++)
    {
        nums[i] = pow(nums[i],2);
    }
     sort(nums.begin(), nums.end());      

    return nums;
 }      

  // optimal approac O(n)
 vector<int> sortedSquares(vector<int>& nums) {

    vector<int> ans;
    int p1, p2;
    for (int i = 0; i < nums.size(); i++)
    {
      if(nums[i]>0){
        p2 = i;
        p1= i-1;
        break;
      }
    }
    while(p2<nums.size() && p1>=0){
      if(pow(nums[p1],2) < pow(nums[p2],2)){
        ans.push_back(pow(nums[p1],2));
        p1--;
      }
      else{
        ans.push_back(pow(nums[p2],2));
        p2++;
      }
    }
    while(p1>=0){
       ans.push_back(pow(nums[p1],2));
        p1--;
    }
    while(p2<nums.size()){
      ans.push_back(pow(nums[p2],2));
        p2++;
    }
    
        

    return ans;
 }               
          
          
          
int main(){
          
 vector<int> nums = {-9,-7,-3,2,3,12};
          
  for(auto it : sortedSquares(nums))cout<<it<<" ";        
          
return 0;
}
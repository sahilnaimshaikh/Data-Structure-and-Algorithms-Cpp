#include<bits/stdc++.h>
using namespace std;

 vector<vector<int>> fourSum(vector<int>& nums, int target) {
     vector<vector<int>> res;
  if(nums.empty())  return res;
  int n = nums.size();
  sort(nums.begin(), nums.end());
  for (int i = 0; i < n; i++)
  {
      for (int j = i+1; j < n; j++)
      {
          int target_2 = target-(nums[i]+nums[j]);
          int front = j+1;
          int back = n-1;
          while(front<back){
              if(nums[front]+nums[back] > target_2){
                  back--;
              }
              else if(nums[front]+nums[back] < target_2){
                  front++;
              }
              else{
                  vector<int> quad(4,0);
                  quad[0]=nums[i];
                  quad[1]=nums[j];
                  quad[2]=nums[front];
                  quad[3]=nums[back];
                  res.emplace_back(quad);
                  front++;
                  back--;
                  while(front<n && nums[front]==quad[2])front++;
                  while(front<n && nums[back]==quad[3])back--;
              }
                
          }
        while(j<n && nums[j+1]== nums[j]) j++;
      }
      while(i<n && nums[i+1]== nums[i]) i++;
  }
  return res;    
 }               
          
          
int main(){

     vector<int> nums = {0,0,0,0};
     int target = 4;
    for(auto it : fourSum(nums,target)){
        for(auto i: it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    
          
          
return 0;
}
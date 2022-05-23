#include<bits/stdc++.h>
using namespace std;
 void nextPermutation(vector<int>& nums) {

     int n = nums.size();
     int k,l;
     for (k = n-2   ; k>=0 ; k--)
     {
         if(nums[k]<nums[k+1]) break;
     }
     if(k<0){
         for(int r = 0; r< n/2; r++){ // reversing the array manually
             swap(nums[r], nums[n-r-1]);
         }
        // reverse(nums.begin(), nums.end());
     }
     else{
         for(l = n-1; l > k; l--){
             if(nums[k]< nums[l])break;
         }
         swap(nums[k], nums[l]);
         reverse(nums.begin()+k+1, nums.end());
         
     }




    }               
          
          
int main(){
          
    vector<int> nums = {1,2,5,6,4,1};
    nextPermutation(nums);
    for(auto it : nums) cout<<it<<" ";
          
          
return 0;
}
#include<bits/stdc++.h>
using namespace std;

  int wiggleMaxLength(vector<int>& nums) {
        
        int inc = 1, dec = 1;
        for(int i=1; i< nums.size(); i++){
            if(nums[i] > nums[i-1]) inc = dec+1;
            // else if(nums[i] < nums[i-1]) dec = inc+1;
        }
        return nums.size()+inc;
    }
         
            
int main(){
            
        // vector<int> nums = {1,17,5,10,13,15,10,5,16,8};
        vector<int> nums = {1,2,3,4,5,6,7,8,9};
        cout<<wiggleMaxLength(nums);
            
return 0;
}
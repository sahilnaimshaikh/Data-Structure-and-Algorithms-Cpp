#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
     int repeatedNTimes(vector<int>& nums) {
        map<int,int> freq;
        int max;
        for (int i = 0; i < nums.size(); i++)
        {
            if(freq.find(nums[i])!=freq.end()){
                freq[nums[i]]++;
            }
            else{
                freq[nums[i]] = 1;
            }
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if(freq[nums[i]]==nums.size()/2) max = nums[i];
        }
        return max;
        
    }      
};
          
int main(){

    vector<int> nums = {5,1,5,2,5,3,5,4};
    Solution sol;
    cout<<sol.repeatedNTimes(nums);      
    
          
          
return 0;
}
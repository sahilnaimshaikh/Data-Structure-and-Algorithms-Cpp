#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxLen(vector<int> nums){
        int n = nums.size();
        int sum = 0;
        int maxx = 0;
        unordered_map<int, int> map;

        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            if(sum==0){
                maxx=i+1;
            }
            else{
                if(map.find(sum) != map.end()){
                    maxx = max(maxx, i-map[sum]);
                }
                else{
                    map.emplace(sum,i);
                }
            }
        }
        return maxx;
    }      
};
          
int main(){

    vector<int> nums = {1,2,3,-1,-2,-3,7,8,9,-9};      
    Solution sol;
    cout<<sol.maxLen(nums);
          
          
return 0;
}
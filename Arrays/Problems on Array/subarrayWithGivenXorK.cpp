#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int totalSubarray(vector<int> nums, int k){
        int Xor= 0;
        int count = 0;
        int y;
        map<int, int> freq;
        for(int i = 0; i<nums.size(); i++){
            Xor = Xor^nums[i];
            if(Xor == k){
                count++;
            }
            y = Xor^k;
            if(freq.find(y) != freq.end()){
                count = count+freq[y];
            }
            freq[Xor]+=1;
            
        }
        return count;
    }      
};
          
int main(){
          
    vector<int> nums = {4,2,2,6,4};
     Solution sol;
     cout<<sol.totalSubarray(nums, 6);     
          
return 0;
}
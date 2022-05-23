#include<bits/stdc++.h>
using namespace std;

int reversePairs(vector<int>& nums) {

int count = 0;
for (int i = 0; i < nums.size(); i++)
{
    for (int j = i+1; j <  nums.size(); j++)
    {
        long long int  x = 2*nums[j];
        if(nums[i]> x) count++;
    }
    
}
return count;


}               
          
          
int main(){
          
vector<int> nums = {2147483647,2147483647,2147483647,2147483647,2147483647,2147483647};
cout<<reversePairs(nums);  
          
          
return 0;
}
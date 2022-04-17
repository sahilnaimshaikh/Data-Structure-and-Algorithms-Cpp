#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int> &nums)
{   sort(nums.begin(),nums.end());
    if(nums.size()==1){
        return nums[0];
    }
    else{
    int i=1;
    while(i<nums.size()){
        if(nums[i-1] == nums[i]){
            if(nums.size()%2==1 && i==(nums.size()-2)){
                return nums[nums.size()-1];
            }
           else i=i+2;
        }
        else{
            return nums[i-1];
        }
    }
}
}

int main()
{

    vector<int> arr = {1};

    cout<<singleNumber(arr);

    return 0;
}
//this program shows error on leetcode.
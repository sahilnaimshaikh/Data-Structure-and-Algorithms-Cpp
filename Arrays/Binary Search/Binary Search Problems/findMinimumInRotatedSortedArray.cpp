#include <bits/stdc++.h>
using namespace std;

int findMinimum(vector<int> &nums)
{
    if (nums.size() == 1)
    {
       
    }
    int minimum = INT_MAX;
    int low = 0;
    int high = nums.size() - 1;
    int mid;
    while (low < high)
    {
        mid = (low + high) / 2;

        if (nums[low] <= nums[mid])
        {
          if(nums[low]<minimum) minimum=nums[low];
          low = mid+1;
        }
        else
        {
          high = mid-1;
        }
    }
    return  minimum;
}

int main()
{

    vector<int> nums = {4, 5, 6, 7, 8, 1, 2};
    
    cout << findMinimum(nums);

    return 0;
}

// this algorithm doesn't work 
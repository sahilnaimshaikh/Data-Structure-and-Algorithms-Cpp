#include <bits/stdc++.h>
using namespace std;
vector<int> find(vector<int> &nums, int target, int index)
{
    if (index == 0)
    {

        if (nums[index + 1])
            return {index, index + 1};
        return {index, index};
    }
    else if (index == nums.size() - 1)
    {
        if (nums[index - 1] == target)
            return {index - 1, index};

        return {index, index};
    }
    if (nums[index - 1] == target)
        return {index - 1, index};
    else if (nums[index + 1])
        return {index, index + 1};
    return {index, index};
}
vector<int> searchRange(vector<int> &nums, int target)
{
    if(nums.size()==1) {
        if(nums[0] == target) return {0,0};
        else return {-1,-1};
    }
    int low = 0;
    int high = nums.size() - 1;
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (nums[mid] == target)
            return find(nums, target, mid);
        if (nums[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return {-1, -1};
}

int main()
{

    vector<int> nums = {1};
    for (auto it : searchRange(nums, 1))
        cout << it << " ";

    return 0;
}
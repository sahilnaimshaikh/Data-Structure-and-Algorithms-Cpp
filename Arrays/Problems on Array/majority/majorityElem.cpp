#include <bits/stdc++.h>
using namespace std;
int majorityElement(vector<int> &nums)
{
    vector<vector<int>> hash;
    vector<int> data;
    int max = INT_MIN;
    int index;
    for (int i = 0; i < nums.size(); i++)
    {
        if (hash.size() == 0)
        {
            data = {nums[i], 1};
            hash.emplace_back(data);
        }
        else
        {
            for (int j = 0; j < hash.size(); j++)
            {
                if (nums[i] == hash[j][0])
                {
                    hash[j][1]++;
                }
                else
                {
                    data = {nums[i], 1};
                    hash.emplace_back(data);
                }
            }
        }
    }
    for (int i = 0; i < hash.size(); i++)
    {
        if (hash[i][1] > max)
            index = hash[i][0];
    }
    return index;
}

int main()
{

    vector<int> nums = {3,3,4};
    cout << majorityElement(nums);

    return 0;
}
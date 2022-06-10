#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int trap(vector<int> &height)
    {   
        int trappedWater = 0;
        int n = height.size();
        vector<int> preMax(n, 0);
        vector<int> sufMax(n, 0);
        int leftMax = height[0];
        for (int i = 0; i < n; i++)
        {
            preMax[i] = max(leftMax, height[i]);
            leftMax = preMax[i];
        }
        int rightMax = height[n - 1];
        for (int i = n - 1; i >= 0; i--)
        {
            sufMax[i] = max(rightMax, height[i]);
            rightMax = sufMax[i];
        }
        for (int i = 0; i < n; i++)
        {
          trappedWater += min(preMax[i], sufMax[i])-height[i];  
        }
        return trappedWater;
    }
};

int main()
{

    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    Solution sol;
    cout << sol.trap(height);

    return 0;
}

// time complexity = 0(N+N+N);
// space complexity = O(n+n);
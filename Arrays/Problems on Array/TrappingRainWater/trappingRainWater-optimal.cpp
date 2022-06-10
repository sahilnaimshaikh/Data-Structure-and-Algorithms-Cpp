#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int trap(vector<int> &h)
    {   
        int n = h.size();
       int leftMax = 0;
       int rightMax = 0;
       int l = 0, r = n-1;
       int trappedWater = 0;
       while(l<=r){
           if(h[l]<=h[r]){
               if(h[l]>=leftMax){
                   leftMax = h[l];
               }
               else{
                   trappedWater += leftMax-h[l];
               }
               l++;
           }
           else{
               if(h[r]>= rightMax){
                   rightMax = h[r];
               }
               else{
                   trappedWater += rightMax-h[r];
               }
               r--;
           }

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


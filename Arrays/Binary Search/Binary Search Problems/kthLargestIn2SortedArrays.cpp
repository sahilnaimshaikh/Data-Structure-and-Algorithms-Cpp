#include <bits/stdc++.h>
using namespace std;
int kthElement(vector<int> &nums1, vector<int> &nums2, int k)
{  
    //  cout<<0.0;
    if (nums2.size() < nums1.size())
        return kthElement(nums2, nums1, k);

    int n = nums1.size();
    int m = nums2.size();
    // int g1 = n+m+1-k;
    int low = max(0,k-m);
    int high = min(k,n);
    int cut1, cut2;
    while (low <= high)
    {   
        //  cout<<0;
        cut1 = (low + high) / 2;
        cut2 = k - cut1;
        int l1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];
        int l2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];
        int r1 = cut1 == n ? INT_MAX : nums1[cut1];
        int r2 = cut2 == n ? INT_MAX : nums2[cut2];
        if (l1 <= r2 && l2 <= r1)
        {
                // cout<<1;
                return (max(l1, l2));
           
        }
        else if (l1 > r2)
        {   
            // cout<<2;
            high = cut1 - 1;
        }
        else
        {  
            //  cout<<3;
            low = cut1 + 1;
        }
    }
    return 0;
}
int main()
{

    vector<int> nums1 = {2, 3, 6, 7, 9};
    vector<int> nums2 = {1, 4, 8, 10};
    int k = 9;
    cout<<kthElement(nums1, nums2,k);
    return 0;
}
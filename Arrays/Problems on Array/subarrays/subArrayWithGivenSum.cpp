#include <bits/stdc++.h>
using namespace std;

vector<int> subarraySum(int arr[], int n, long long s)
{
    vector<int> ans;
    if (s == 0)
    {
        ans.push_back(-1);
        return ans;
    }

    long long sum = arr[0];
    int low = 0;
    int high = 0;
    int m = 0;
    while (m < n)
    {
        m++;
        if (sum == s)
        {
            ans.push_back(low + 1);
            ans.push_back(high + 1);
            break;
        }
        else if (sum > s)
        {
            sum -= arr[low];
            low++;
            m--;
        }
        else
        {
            sum += arr[m];
            high++;
        }
    }
    if (ans.size() == 0)
        ans.push_back(-1);
    return ans;
}

int main()
{

    return 0;
}
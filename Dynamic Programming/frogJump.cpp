#include <bits/stdc++.h>
using namespace std;

// Recursion
/*
int minEnergy(int n, vector<int> &h)
{

    if (n == 0)
        return n;

    int l = minEnergy(n - 1, h) + abs(h[n] - h[n - 1]);
    int r = INT_MAX;
    if (n > 1)
        r = minEnergy(n - 2, h) + abs(h[n] - h[n - 2]);

    return min(l, r);
}
*/

// Memoization
/*
int minEnergy(int n, vector<int> &h, vector<int> & dp)
{

    if (n == 0)
        return dp[n];

    if(dp[n] != -1) return dp[n];

    int l = minEnergy(n - 1, h , dp) + abs(h[n] - h[n - 1]);
    int r = INT_MAX;
    if (n > 1)
        r = minEnergy(n - 2, h, dp) + abs(h[n] - h[n - 2]);

    return  dp[n] = min(l, r);
}
*/

/*
//Tabulation
int minEnergy(int n, vector<int> &h, vector<int> & dp)
{
    for (int i = 1; i <= n; i++)
    {
        int l = dp[i-1]+ abs(h[i]-h[i-1]); 
        int r = INT_MAX;
        if(i>1) r = dp[i-2]+ abs(h[i]-h[i-2]); 

        dp[i] = min(l,r);
    }
    return dp[n];
    
}
*/

// Space Optimization

int minEnergy(int n, vector<int> &h)
{   
   int prev2 = 0;
   int prev1 = 0;
   int curr;
   for (int i = 1; i < n ; i++)
   {
        int l  = prev1 + abs(h[i]-h[i-1]);

        int r = INT_MAX;
        if(i>1) r = prev2 + abs(h[i]-h[i-2]);
         curr = min(l,r);
        prev2 = prev1;
        prev1 = curr;
   }
   return curr;
    
}

int main()
{

    int n = 4;
    vector<int> h = {10, 20, 30, 10};
    // cout << minEnergy(n - 1, h);

    vector<int> dp(4, -1); // use only when memoization is used;
    dp[0] = 0;
    // cout<<minEnergy(n-1, h, dp);


    cout<<minEnergy(n, h);// for space optimization

    return 0;
}
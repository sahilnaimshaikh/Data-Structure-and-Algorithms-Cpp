#include<bits/stdc++.h>
using namespace std;

//Recursion 
// int fibonacci(int n){
//     cout<<"*";
//     if(n<=1)return n;

//     return fibonacci(n-1)+fibonacci(n-2);
// }           

// memoization
//    int fibonacci(int n , vector<int>& dp){
//     cout<<"*";
//     if(n<=1)return n;

//     if(dp[n] != -1) return dp[n];

//     return dp[n] = fibonacci(n-1,dp)+fibonacci(n-2, dp);
//    }    


// tabulation
// int fibonacci(int n, vector<int>& dp){
//     dp[0] = 0;
//     dp[1] = 1;
//     for(int i = 2; i < dp.size(); i++){
//         dp[i] = dp[i-1]+dp[i-2];
//     }
//     return dp[n];
// }   

// space optimization
int fibonacci(int n){
    if(n<=1) return n;
    int prev = 1;
    int prev2 = 0;
    int curr;
    for(int i = 2; i <= n; i++){
        curr = prev+prev2;
        prev2 = prev;
        prev = curr;
    }
   return curr;
}   

// 0 1 1 2 3 5 8 13

int main(){
          
    int n = 44;
    vector<int> dp(n+1, -1);
    // cout<<fibonacci(n, dp);
    cout<<fibonacci(n);
          
          
return 0;
}
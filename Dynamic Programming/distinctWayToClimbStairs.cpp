#include<bits/stdc++.h>
using namespace std;

   //Recursion            
//    void climb(int n, int& count){
//     if(n == 0){
//         count++;
//         return;
//     }
//     if(n < 0)return;
//     climb(n-1, count);
//     climb(n-2, count);
//    }       
//    Recursion            
   int climb(int n){
    if(n == 0){
        
        return 1;
    }
    if(n < 0)return 0;
    return climb(n-1)+climb(n-2);
   }       


 //memoization
      int climb(int n,vector<int>& dp){
        if(n <= 1)return dp[n];
        if(n < 0) return 0;

        if(dp[n] != -1) return dp[n];

        return dp[n] = climb(n-1, dp) + climb(n-2, dp);
        

   } 

  //tabulation

   int climb(int n,vector<int>& dp){
      
      for (int i = 2; i < n; i++)
      {
        dp[i] = dp[i-1] + dp[i-2];
      }
      return dp[n];

        

   }
   //space optimization
   


int main(){
          
    int n = 44;
    vector<int> dp(n+1, -1);
    dp[0] = 1;
    dp[1] = 1;
    int count = 0;


    cout<<climb(n,dp);
    // cout<<climb(n);
    //  cout<<count;     
          
return 0;
}
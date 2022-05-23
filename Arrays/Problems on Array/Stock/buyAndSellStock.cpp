#include<bits/stdc++.h>
using namespace std;

  int maxProfit(vector<int>& prices) {
     int max=0,profit;
     for (int i = 0; i < prices.size(); i++)
     {
         for(int j = i+1; j < prices.size(); j++){
            if(prices[i]<prices[j]){
                profit = prices[j]-prices[i];
                if(profit>max) max = profit;
            }

         }
         
     }
     if(max==0) return 0;
    return max;
    }              
          
          
int main(){

  vector<int> prices = {7,6,5,4};
  cout<<maxProfit(prices);        
          
          
          
return 0;
}
// brute force approach 
// above solution is getting TLE on leetcode although the output generated is correct...therefore heading toward optimal approach.
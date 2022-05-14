#include<bits/stdc++.h>
using namespace std;

  int maxProfit(vector<int>& prices) {
     int trigger = 0, max=0,profit;
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

  vector<int> prices = {7,6,5,4,10};
  cout<<maxProfit(prices);        
          
          
          
return 0;
}
// brute force approach 
// above solution is getting TLE on leetcode although the output generating is correct...therefore heading toward better approach.
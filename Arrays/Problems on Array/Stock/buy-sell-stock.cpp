#include<bits/stdc++.h>
using namespace std;
               
 int maxProfit(vector<int>& prices) {
    
     int minPrice = INT32_MAX;
     int maxProfit = 0;
     for (int i = 0; i < prices.size(); i++)
     {
         if(prices[i]<minPrice) minPrice = prices[i];
         else if(prices[i]-minPrice>maxProfit) maxProfit = prices[i]-minPrice;
     }
     return maxProfit;

    }           
          
int main(){
          
          vector<int> prices = {7,6,5,4,3,2,1};
          reverse(prices.begin(), prices.end());
          cout<<maxProfit(prices);
          
return 0;
}
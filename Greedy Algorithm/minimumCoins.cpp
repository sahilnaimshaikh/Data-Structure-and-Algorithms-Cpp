#include<bits/stdc++.h>
using namespace std;
int findMinimumCoins(int amount) 
{
   int coins[] = {1,2,5,10,20,50,100,500,1000};
   int n = sizeof(coins)/sizeof(coins[0]);
   int count = 0;
   vector<int> change;
   for (int i = n-1 ; i >=0 ; i--)
   {
      while (coins[i] <= amount)
      {
          count++;
          change.push_back(coins[i]);
          amount -= coins[i];
      }
      
   }
   for(auto it: change)cout<<it<<" ";
   cout<<endl;
   return count;
}          
            
int main(){

    int amount =629;
    cout<<findMinimumCoins(amount);

        
            
return 0;
}
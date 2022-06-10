#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
     int findPlatform(int arr[], int dep[], int n)
    {
    	int count = 1;
        int ans = 1;
        for (int  i = 0; i < n; i++)
        {   
            count = 1;
            for (int j = i+1; j < n; j++)
            {   
                if((arr[i]>=arr[j] && arr[i]<= dep[j]) || (arr[i]<=arr[j] && dep[i]>=arr[j])){
                    count++;
                }
            }
            ans = max(ans, count);
            
        }
        return ans;
    }      
};
          
int main(){
          
    int  arr[] = {900, 940, 950, 1100, 1500, 1800};
    int dep[] = {910, 1200, 1120, 1130, 1900, 2000};
    int n = 6;
    Solution sol;
    cout<<sol.findPlatform(arr, dep, n);      
          
return 0;
}
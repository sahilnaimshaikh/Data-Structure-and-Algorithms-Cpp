#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
     int findPlatform(int arr[], int dep[], int n)
    {
    	int count = 1;
        int ans = 1;
        int i = 1;
        int j = 0;
        sort(arr, arr+n);
        sort(dep, dep+n);
        while(i<n && j<n){
            if(arr[i]<=dep[j]){
                i++;
                count++;
            }
            else{
                count--;
                j++;
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
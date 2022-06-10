#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
     int trap(vector<int>& height) {
        int n = height.size();
        int trapped = 0;
        for (int i = 0; i < n; i++)
        {   
            int j = i;
            int maxLeft = 0,maxRight = 0;
            while(j>=0){
                maxLeft = max(maxLeft, height[j]);
                j--;
            }
            j = i;
            while(j<n){
                maxRight = max(maxRight, height[j]);
                j++;
            }
            
            trapped+= min(maxLeft,maxRight)-height[i];
        }
        return trapped;
    }      
};
          
int main(){
          
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
  Solution sol;
  cout<<sol.trap(height); 
          
          
return 0;
}
// time complexity = O(N*N)
// space complexity = O(1)
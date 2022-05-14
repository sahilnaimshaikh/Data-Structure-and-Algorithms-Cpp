#include<bits/stdc++.h>
using namespace std;
               
 int maxSubArray(vector<int>& nums) {

      int n = nums.size(), sum, max = INT8_MIN;
      for (int  i = 0; i <= n-1; i++)
      {
          sum = 0;
          for (int j = i; j <= n-1; j++)     
          { 
              
              sum += nums[j];
               if(max<sum) max = sum;
              cout<<"max is "<<max<<endl;
              
          }
         
      }
      return max;

    }         
          
int main(){
          
          vector<int> nums = {1};

          cout<<maxSubArray(nums);
          
return 0;
}
// TimeComplexity of this algorithm is O(N^2)...
// Time Limit has been exceeded after running this code for hidden testcases on leetcode...Therefore heading towards optimal(O(N)) approach.
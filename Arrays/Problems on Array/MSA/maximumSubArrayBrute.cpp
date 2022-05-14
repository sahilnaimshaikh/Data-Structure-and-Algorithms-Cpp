#include<bits/stdc++.h>
using namespace std;
               
 int maxSubArray(vector<int>& nums) {

      int n = nums.size(), sum, max = INT8_MIN;
      for (int  i = 0; i <= n-1; i++)
      {
          for (int j = i; j <= n-1; j++)     
          { 
              sum = 0;
              for (int k = i; k <= j ; k++)sum += nums[k];
              if(max<sum) max = sum;
              cout<<"max is "<<max<<endl;
              
          }
          
      }
      return max;



    }         
          
int main(){
          
          vector<int> nums = {5,4,-1,7,8};

          cout<<maxSubArray(nums);
          
return 0;
}
// TimeComplexity of this algorithm is O(N^3)...
// Time Limit has been exceeded after running this code for hidden testcases on leetcode...Therefore heading towards better(O(N^2))/optimal(O(N)) approach.
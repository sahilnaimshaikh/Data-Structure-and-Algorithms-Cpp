#include<bits/stdc++.h>
using namespace std;
               
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
      
      for (int i = 0; i < n; i++)
      {
         nums1[m+i] = nums2[i];
      }
      sort(nums1.begin(), nums1.end());


 }          
          
int main(){
          
     vector<int> nums1 = {1,2,3,0,0,0};
     vector<int> nums2 = {2,5,6};
     int n = nums2.size();
     int m = nums1.size()-n;
     merge(nums1, m, nums2, n); 
    for(auto it : nums1)cout<<it<<" ";    
          
return 0;
}
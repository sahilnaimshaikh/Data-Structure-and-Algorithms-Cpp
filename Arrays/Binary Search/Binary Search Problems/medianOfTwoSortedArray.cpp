#include<bits/stdc++.h>
using namespace std;

 double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    
    if(nums2.size()<nums1.size()) return findMedianSortedArrays(nums2,nums1);
    
   int n = nums1.size();
   int m = nums2.size(); 
   int low = 0;
   int high = n;
   int cut1,cut2;
   while(low<=high){
        cut1 = (low+high)/2;
        cut2 = ((n+m+1)/2)-cut1;
        int l1 = cut1==0?INT_MIN:nums1[cut1-1];
        int l2 = cut2==0?INT_MIN:nums2[cut2-1];
        int r1 = cut1==n?INT_MAX:nums1[cut1];
        int r2 = cut2==n?INT_MAX:nums2[cut2];
        if(l1<=r2 && l2<=r1){
            if((n+m)%2 == 0){
                return (max(l1,l2)+min(r1,r2))/2.0;
            }
            else{
                return (max(l1,l2));
            }
        }
        else if(l1>r2){
            high = cut1-1;
        }
        else{
            low = cut1+1;
        }
   }  
   return 0.0;  
}          
            
int main(){

vector<int> num1 = {1,2,5};
vector<int> num2 = {3,4,5,7};
cout<<findMedianSortedArrays(num1,num2);
        
            
return 0;
}

// the algorithm is running absolutely fine for all test cases; but showing some error on leetcode;
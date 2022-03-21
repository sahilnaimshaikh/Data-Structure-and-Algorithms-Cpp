#include<bits/stdc++.h>
using namespace std;
 int searchInsert(vector<int> &nums, int target) {

     int low = 0;
     int high = nums.size()-1;
     int mid;
     while(low <= high){
         mid = (low+high)/2;
    
         if(nums[mid] == target)
         {
              return mid;
         }
         if(nums[mid]>target){
             high = mid-1;
         }
         else{
             low = mid+1;
         }
         
     }
    
     if(target < nums[mid]) return mid;
     else  return mid+1;
     
}           
            
int main(){

    vector<int> arr = {1, 3, 5, 6};
    
    searchInsert(arr, 7);
    
            
return 0;
}
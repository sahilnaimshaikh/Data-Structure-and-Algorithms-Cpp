// // Q. Search Element in the Rotated Sorted Array.
// #include<bits/stdc++.h>
// using namespace std;

//  int search(int * A, int n, int element){
//      int low = 0;
//      int high = n-1;
//      int mid;
//      while(low<=high){
//          mid = (low + high)/2;
//          if(A[mid]==element){
//              return mid;
//          }
//          if(A[low]<=A[mid]){// check if the left portion from the mid is sorted or not.
//              if(A[low]<=element && element<=A[mid]){//if sorted , check if element lies in that sorted part
//                  high = mid-1;
//              }
//              else{
//                  low = mid+1;
//              }
//          }
//          else{// if the left portion from the mid is not sorted , check if element lies in the right portion.
//              if(A[mid]<=element && element <=A[high]){
//                  low = mid+1;

//              }
//              else{
//                  high = mid-1;
//              }
//          }

//      }
//      return -1;//if the element is not found in the array then return -1;
//  }

// int main(){

//       int A[] = { 6,7,8,9,1,2,3,4,5};
//       int n = sizeof(A)/sizeof(int);
//       int element = 5;
//       cout<<"Element found at:"<<search(A,n,element);

// return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &nums, int target)
{
    if (nums.size() == 1)
    {
        if (nums[0] == target)
            return 0;
        else
            return -1;
    }
    int low = 0;
    int high = nums.size() - 1;
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (nums[mid] == target)
            return mid;
        if (nums[low] <= nums[mid])
        {
            if (nums[low] <= target && target <= nums[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            if (nums[mid] <= target && target <= nums[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{

    vector<int> nums = {1,0,1,1,1};
    int target = 0;
    cout << search(nums, target);

    return 0;
}
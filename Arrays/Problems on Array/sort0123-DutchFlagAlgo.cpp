#include<bits/stdc++.h>
using namespace std;
               
void sortColors(vector<int>& nums) {

        int low = 0;
        int mid = 0;
        int high = nums.size()-1;

        while(mid<=high){
        if(nums[mid]==0){
            swap(nums[low],nums[mid]);
            low++;
            mid++;
        }
        else if(nums[mid]==1){
            
            mid++;
        }
        else if(nums[mid]==2){
            swap(nums[mid],nums[high]);
            high--;
        }
        
    } 
    }
          
int main(){
          
          vector<int> nums = {0,2,1,0,1,1};
            for(auto it: nums) cout<<it<<" ";
            cout<<endl;
            sortColors(nums);
            for(auto it: nums) cout<<it<<" ";
            cout<<endl;
          
          
return 0;
}
#include<bits/stdc++.h>
using namespace std;

 void moveZeroes(vector<int>& nums) {

     int count = 0, index = 0;
     for(int i = 0; i< nums.size(); i++){
         if(nums[i] == 0) count++;
     }
    
     for(int j = 0; j < nums.size(); j++){
         if(nums[j] != 0)  {

             nums[index] = nums[j];
             index++;
         } 
     }
   
      if(count != nums.size()) {
          for(int z = nums.size()-1; z >= nums.size()-count; z--){
        nums[z] = 0;
    }
      }
     

}               
          
          
int main(){
          
vector<int> nums = {0};
    for(auto it : nums) cout<<it<<" ";
    cout<<endl;
 moveZeroes(nums);         
    for(auto it : nums) cout<<it<<" ";
    cout<<endl;
return 0;
}
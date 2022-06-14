
    #include<bits/stdc++.h>
    using namespace std;

    void findCombination(int i, vector<int> &candidates, vector<vector<int>> &ans, vector<int> &ds, int target){

        if(i==candidates.size()){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }
         
        if(candidates[i]<= target){
        
        ds.push_back(candidates[i]);
        findCombination(i,candidates,ans,ds,target-candidates[i]);
        ds.pop_back();
        }

        findCombination(i+1,candidates,ans,ds,target);

    }       

     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;
        vector<int> ds;

        findCombination(0,candidates,ans,ds,target);
        return ans;

        

    }           
    int main(){

       vector<int> candidates = {2,3,5,7};
       int target = 7;
       combinationSum(candidates, target);         
            
                
    return 0;
    }

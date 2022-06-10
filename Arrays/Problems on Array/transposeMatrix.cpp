#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
      vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i+1 ; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
            
        }
               
        return matrix;
    }      
};
          
int main(){
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};      
    Solution sol;
   for(auto it : sol.transpose(matrix)){
       for(auto i: it){
           cout<<i<<" ";
       }
       cout<<endl;
   }
          
          
return 0;
}
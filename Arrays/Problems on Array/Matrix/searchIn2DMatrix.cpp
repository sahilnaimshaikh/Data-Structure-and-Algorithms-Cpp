#include<bits/stdc++.h>
using namespace std;

   bool searchMatrix(vector<vector<int>>& matrix, int target) {
      int rowSize = matrix.size();
      int columsSize = matrix[0].size();
      for (int i = 0; i < rowSize; i++)
      {
          for (int j = 0; j < columsSize; j++)
          {
              if(matrix[i][j] == target) return true;
          }
          if(target < matrix[i][columsSize-1]) return false;
      }
        return false;
    }              
          
          
int main(){
          
vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,31,34,60}};
          
cout<<searchMatrix(matrix, 3) ;  
      
return 0;
}

// this is a brute force approach for this problem...interviewer may not be happy with this approach so we will head towards better approach
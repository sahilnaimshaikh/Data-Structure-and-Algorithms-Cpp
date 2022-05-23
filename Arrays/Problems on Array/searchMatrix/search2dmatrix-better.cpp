#include<bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
      int rowSize = matrix.size();
      int columnsize = matrix[0].size();
      int r = 0, c = columnsize-1;
      while(r<rowSize && c >= 0){
          if(matrix[r][c]==target){
              return true;
          }
          else{
              if(target> matrix[r][c]) r++;
              else c--;
          }
      }
      return false;
    }                
          
          
int main(){
          
vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
          
cout<<searchMatrix(matrix, 3) ;  
          
          
return 0;
}
#include<bits/stdc++.h>
using namespace std;
               
 bool searchMatrix(vector<vector<int>>& matrix, int target) {
      int rowSize = matrix.size();
      int colSize = matrix[0].size();
      int low = 0;
      int high = (rowSize*colSize)-1;
      int mid;
      while(low<=high){
          mid = (low+high)/2;
          if(matrix[mid/colSize][mid%colSize] == target) return true;
          if(matrix[mid/colSize][mid%colSize] < target) low = mid+1;
          else high = mid-1;
      }
      return false;
    }         
          
int main(){
          
vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
          
cout<<searchMatrix(matrix, 3) ;
          
          
return 0;
}
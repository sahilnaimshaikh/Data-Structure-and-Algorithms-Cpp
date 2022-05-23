#include<bits/stdc++.h>
using namespace std;

  int   findUniquePaths(int rowSize,int columnSize,int startingRowNo,int startingColumnNo, vector<vector<int>> gridClone ){
      if(startingRowNo>=rowSize || startingColumnNo>= columnSize) return 0;
      if(startingRowNo == rowSize-1 && startingColumnNo == columnSize-1) return 1;

        if(gridClone[startingRowNo][startingColumnNo] != -1) return gridClone[startingRowNo][startingColumnNo];
        
                int left = findUniquePaths(rowSize,columnSize,startingRowNo+1,startingColumnNo, gridClone);
                int right = findUniquePaths(rowSize,columnSize,startingRowNo,startingColumnNo+1, gridClone);
        
      return gridClone[startingRowNo][startingColumnNo] = left+right;
  }    
  int uniquePaths(int rowSize, int columnSize) {
        int startingRowNo=0,startingColumnNo=0;
        vector<vector<int>> gridClone(rowSize, vector<int> (columnSize, -1));
       return findUniquePaths(rowSize,columnSize,startingRowNo,startingColumnNo,gridClone);
    }          
          
int main(){

   int rowSize = 23;
   int columnSize = 12;
   cout<<uniquePaths(rowSize,columnSize);     
    
          
          
return 0;
}

// OUtput is correct for evry testCases but TLE issue with this approach ... 
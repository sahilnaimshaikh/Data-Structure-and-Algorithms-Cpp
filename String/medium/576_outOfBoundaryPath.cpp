/*
576. Out of Boundary Paths
There is an m x n grid with a ball. The ball is initially at the position [startRow, startColumn]. You are allowed to move the ball to one of the four adjacent cells in the grid (possibly out of the grid crossing the grid boundary). You can apply at most maxMove moves to the ball.

Given the five integers m, n, maxMove, startRow, startColumn, return the number of paths to move the ball out of the grid boundary. Since the answer can be very large, return it modulo 109 + 7.

 

Example 1:


Input: m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0
Output: 6
Example 2:


Input: m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1
Output: 12
 

Constraints:

1 <= m, n <= 50
0 <= maxMove <= 50
0 <= startRow < m
0 <= startColumn < n

*/

#include<bits/stdc++.h>
using namespace std;

    bool outSide(int m, int n, int startRow, int startColumn){
        if((startRow>=m || startRow < 0 || startColumn <0 || startColumn >=n))return true;
        return false;
    }

 void findPaths(int m, int n, int maxMove, int  startRow, int  startColumn, int & count) {
        if(outSide(m, n, startRow, startColumn)){
                count++;
                return;
        }
        if(maxMove == 0){
            return;
        }
        findPaths(m,n,maxMove-1,startRow, startColumn+1, count);
        findPaths(m,n,maxMove-1,startRow, startColumn-1, count);
        findPaths(m,n,maxMove-1,startRow+1, startColumn, count);
        findPaths(m,n,maxMove-1,startRow-1, startColumn, count);
    }            
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn){
        int count= 0 ;
        findPaths(m,n,maxMove,startRow, startColumn, count);
        int a =  pow(10,9)+7;
        return count % a;
            }

int main(){
            
      int m = 1, n= 3, maxMove = 3, startRow = 0, startColumn = 1;
      cout<<findPaths(m, n, maxMove, startRow, startColumn);  
            
return 0;
}


// This solution has got TLE on Leetcode;
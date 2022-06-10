#include<bits/stdc++.h>
using namespace std;
class NumMatrix {
    private:
    vector<vector<int>> res;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        res  = matrix;
      
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for (int i = row1; i <= row2 ; i++)
        {
            for (int j = col1; j <= col2; j++)
            {
                sum += res[i][j];
            }
            
        }
        return sum;
        
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
          
int main(){
       vector<vector<int>> matrix = {{3, 0, 1, 4, 2}, {5, 6, 3, 2, 1}, {1, 2, 0, 1, 5}, {4, 1, 0, 1, 7}, {1, 0, 3, 0, 5}};
       
    NumMatrix* obj = new NumMatrix(matrix);
     cout<<obj->sumRegion(0,1,2,3);
          
          
return 0;
}
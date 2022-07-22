#include<bits/stdc++.h>
using namespace std;
void solve(int col,int n, vector<string> &board, vector<vector<string>> &ans, vector<int> &left, vector<int> &upperDiag, vector<int> &lowerDiag){

        if(col == n){
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if(left[row] == 0 && upperDiag[n-1 + col-row]==0 && lowerDiag[row+col]==0){
                board[row][col] = 'Q';
                left[row] = 1;
                upperDiag[n-1 + col-row]=1;
                lowerDiag[row+col]=1;
                solve(col+1, n, board, ans , left, upperDiag, lowerDiag);
                board[row][col] = '.';
                left[row] = 0;
                upperDiag[n-1 + col-row]=0;
                lowerDiag[row+col]=0;
            }
        }
        
}

vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for (int i = 0; i < n; i++)
        {
            board[i] = s;
        }
        vector<int> upperDiag(2*n-1, 0);
        vector<int> lowerDiag(2*n-1, 0);
        vector<int> left(n,0);
        solve(0, n, board, ans, left, upperDiag, lowerDiag);
        return ans;
}            
            
int main(){
            
        int n = 4;
        for(auto it: solveNQueens(n)){
            for(auto i : it){
                for(auto e : i)cout<<e<<" ";
                cout<<endl;
            }
            cout<<endl;
        }
            
return 0;
}
#include<bits/stdc++.h>
using namespace std;
bool isSafe(int row, int col,vector<string> board, int n){
    int dupRow = row;
    int dupCol = col;

    while(row>-1 && col>-1){
        if(board[row][col] == 'Q') return false;
        row--;
        col--;
    }
    row = dupRow;
    col = dupCol;
    while(col>-1){
        if(board[row][col] == 'Q') return false;
        col--;
    }
    row = dupRow;
    col = dupCol;
    while(row<n && col>-1){
        if(board[row][col] == 'Q') return false;
        row++;
        col--;
    }
    return true;
}

void solve(int col,int n, vector<string> &board, vector<vector<string>> &ans){

        if(col == n){
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if(isSafe(row, col,board, n)){
                board[row][col] = 'Q';
                solve(col+1, n, board, ans);
                board[row][col] = '.';
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
        solve(0,n,  board, ans);
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
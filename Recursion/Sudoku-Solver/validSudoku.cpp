#include<bits/stdc++.h>
using namespace std;

    bool isValid(int row, int col, vector<vector<char>> board, char c){
        board[row][col] = '.';
    for (int  i = 0; i < 9; i++)
    {
        if(board[row][i] == c && i!=col)return false;

        if(board[i][col] == c && i!= row)return false;
        if(board[3*(row/3) + i/3][3*(col/3) + i%3] == c)return false;
        
    }
    return true;
}
   bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if(board[i][j] != '.'){
                    if(!isValid(i, j, board, board[i][j])) return false;
                }
            }
            
        }
        return true;
        
    }           
            
int main(){
 vector<vector<char>>board{
        {'9', '5', '7', '.', '1', '3', '.', '8', '4'},
        {'4', '8', '3', '.', '5', '7', '1', '.', '6'},
        {'.', '1', '2', '.', '4', '9', '5', '3', '7'},
        {'1', '7', '.', '3', '.', '4', '9', '.', '2'},
        {'5', '.', '4', '9', '7', '.', '3', '6', '.'},
        {'3', '.', '9', '5', '.', '8', '7', '.', '1'},
        {'8', '4', '5', '7', '9', '.', '6', '1', '3'},
        {'.', '9', '1', '.', '3', '6', '.', '7', '5'},
        {'7', '.', '6', '1', '8', '5', '4', '.', '9'}
    };
    cout<<isValidSudoku(board);
               
        
            
return 0;
}
#include<bits/stdc++.h>
using namespace std;

void solve(int i, int j, int n,string move,vector<vector<int>> &m, vector<string> &ans, vector<vector<int>> &visited){
    //base case
    if(i==n-1 && j==n-1){
        ans.push_back(move);
        return;
    }
    
    //downwards
    if(i+1<n && m[i+1][j]!=0 && visited[i+1][j]!=1){    
        visited[i][j] = 1;
        solve(i+1,j,n,move+'D',m,ans,visited);
        visited[i][j] = 0;
    }   
    //leftwards
    if(j-1>=0 && m[i][j-1]!=0 && visited[i][j-1]!=1){
          visited[i][j] = 1;
        solve(i,j-1,n,move+'L',m,ans,visited);
        visited[i][j] = 0;
    }  
    //rightwards  
    if(j+1<n && m[i][j+1]!=0 && visited[i][j+1]!=1){
          visited[i][j] = 1;
        solve(i,j+1,n,move+'R',m,ans,visited);
        visited[i][j] = 0;
    }   
    //upwards 
    if(i-1>=0 && m[i-1][j]!=0 && visited[i-1][j]!=1){
          visited[i][j] = 1;
        solve(i-1,j,n,move+'U',m,ans,visited);
       visited[i][j] = 0;
    }    

}

vector<string> findPath(vector<vector<int>> &m, int n) {

    vector<string> ans;
    vector<vector<int>> visited(n,vector<int>(n,0));
    
    string move = "";
    solve(0,0,n,move,m,ans,visited);
    return ans;

    }         
            
int main(){

int n = 2;
vector<vector<int>> m = {{1,1},{1,1}};
for(auto it:findPath(m, n)){
    cout<<it;
    cout<<endl;
}
            
return 0;
}
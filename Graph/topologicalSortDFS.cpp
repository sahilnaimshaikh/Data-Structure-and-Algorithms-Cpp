
// quikly do the dry run if not able to understand the code in one go
#include<bits/stdc++.h>
using namespace std;

void goDeep(int i , vector<int>& dfs, vector<int> &visited , vector<int> adj[]){
    dfs.push_back(i);
    visited[i] =1;
    for(auto it : adj[i]){
        if(!visited[it] ) goDeep(it, dfs, visited, adj);
    }
}

 vector<int> dfsInGraph(int v, vector<int> adj[]){
    vector<int> dfs;
    vector<int> visited(v+1, 0);

    for( int i = 1; i<= v; i++){
        if(visited[i] == 0){
            goDeep(i, dfs, visited, adj);
        }
    }
    return dfs;
 }             
          
          
int main(){
    int v = 6;      
   vector<int> adj[v+1];

   adj[1] = {2};
   adj[2] = {1,4,5};
   adj[3] = {6}; 
   adj[4] = {2,5}; 
   adj[5] = {2,4}; 
   adj[6] = {3}; 

   for(auto it : dfsInGraph(v, adj))cout<<it<<" ";

          
          
return 0;
}
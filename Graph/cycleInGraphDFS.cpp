
// quikly do the dry run if not able to understand the code in one go
#include<bits/stdc++.h>
using namespace std;

bool goDeep(int i ,int previous, vector<int>& dfs, vector<int> &visited , vector<int> adj[]){
    dfs.push_back(i);
    visited[i] =1;
    for(auto it : adj[i]){
        if(!visited[it] ) goDeep(it,i, dfs, visited, adj);
        else if(it!= previous) return true;
    }
    return false;
}

 bool dfsInGraph(int v, vector<int> adj[]){
    vector<int> dfs;
    vector<int> visited(v+1, 0);

    for( int i = 1; i<= v; i++){
        if(visited[i] == 0){
            if(goDeep(i,-1, dfs, visited, adj))return true;
        }
    }
    return false;
 }             
          
          
int main(){
    int v = 6;      
   vector<int> adj[v+1];

   adj[1] = {5,2};
   adj[2] = {1,4,5};
   adj[3] = {6}; 
   adj[4] = {2}; 
   adj[5] = {2,1}; 
   adj[6] = {3}; 

   cout<<dfsInGraph(v, adj);

          
          
return 0;
}
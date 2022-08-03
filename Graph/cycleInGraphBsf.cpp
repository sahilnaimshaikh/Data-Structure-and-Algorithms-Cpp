#include<bits/stdc++.h>
using namespace std;

    bool hasCycle(int i, vector<int> visited, vector<int> adj[]){
        queue<pair<int, int>> q;
        q.push({i,-1});
        visited[i] = 1;
        while(!q.empty()){
            int node = q.front().first;
            int previous = q.front().second;
            q.pop();
            for(auto it: adj[node]){
                if(!visited[it]){
                    q.push({it , node});
                    visited[it] = 1;
                }
                else{
                    if(it != previous) return true;
                    
                }
            }
        }
        return false;
    }

  bool bsfInGraph(int v, vector<int> adj[]){
    vector<int> visited(v+1, 0);
    for(int i = 1; i<= v; i++){
        if(!visited[i]){
            if(hasCycle(i, visited, adj)) return true;
        }
    }
    return false;
  }
          
int main(){
          
      int v = 6;      
   vector<int> adj[v+1];

   adj[1] = {5,2};
   adj[2] = {1,4};
   adj[3] = {6}; 
   adj[4] = {2,5}; 
   adj[5] = {1,4}; 
   adj[6] = {3}; 

    cout<<bsfInGraph(v, adj);
          
          
return 0;
}
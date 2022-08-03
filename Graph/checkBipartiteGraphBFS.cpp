#include<bits/stdc++.h>
using namespace std;
    bool checkBipartite(int i, vector<int> & color, vector<int> adj[]){

        queue<int> q;
        q.push(i);
        color[i] = 1;

        while(q.empty() == 0){
             int  node = q.front();
             q.pop();

             for(auto it : adj[node]){
                if(color[it] == -1){
                    q.push(it);
                    color[it] = 1-color[node];
                }
                else{
                    if(color[it] == color[node]){
                        return false;
                    }
                }
             }
        }
        return true;
    }
   bool bsfInGraph(int v, vector<int> adj[]){
    vector<int> color(v+1, -1);

    for (int i = 1; i <= v; i++)
    {
        if(color[i] == -1){
            if(checkBipartite(i, color, adj))return true;
        }
    }
    return false;
   }
          
          
int main(){
          
        int v = 6;      
   vector<int> adj[v+1];

   adj[1] = {2};
   adj[2] = {1,4,5};
   adj[3] = {6}; 
   adj[4] = {2}; 
   adj[5] = {2}; 
   adj[6] = {3}; 

   cout<<bsfInGraph(v , adj);
          
          
return 0;
}
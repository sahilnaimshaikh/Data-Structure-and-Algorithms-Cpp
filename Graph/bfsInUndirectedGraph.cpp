
// quikly do the dry run if not able to understand the code in one go
#include<bits/stdc++.h>
using namespace std;

 vector<int> bfsInGraph(int v, vector<int> adj[]){
    vector<int> bfs;// creating the bfs vector to store the answer
    vector<int> visited(v+1, 0); // creating the visited vector to check if the element is visited or not

    for(int i = 1; i <= v; i++){ // this for loop is for accessing the different components of the graph
        if(!visited[i]){  // if that vertice has not been visited previously then will visit that
            queue<int> q;
            q.push(i);
            visited[i] = 1;

            while(!q.empty()){
                int node = q.front();
                q.pop();
                bfs.push_back(node);

                for(auto it : adj[node]){
                    if(!visited[it]){
                        q.push(it);
                        visited[it] = 1;
                    }
                }
            }
        }
    }
    return bfs;
 }              
          
          
int main(){
    int v = 6;      
   vector<int> adj[v+1];

   adj[1] = {2};
   adj[2] = {1,5,4};
   adj[3] = {6}; 
   adj[4] = {2}; 
   adj[5] = {2}; 
   adj[6] = {3}; 

   for(auto it : bfsInGraph(v, adj))cout<<it<<" ";

          
          
return 0;
}

// quikly do the dry run if not able to understand the code in one go
#include<bits/stdc++.h>
using namespace std;

void getDeep(int i, vector<int> & visited, vector<int> adj[], stack<int>& st){
    visited[i] = 1;
    for(auto it : adj[i]){
        if(visited[it] == 0){
            getDeep(it, visited, adj, st);
        }
    }
    st.push(i);
}


 vector<int> toposort(int v, vector<int> adj[]){
    stack<int> st;
    vector<int> visited(v+1, 0);
    for (int i = 1; i <= v; i++)
    {
        if(!visited[i]){
            getDeep(i, visited, adj, st);
        }
    }
    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
 }             
          
          
int main(){
    int v , e;
    cout<<"Enter the no. of nodes and edges";
    cin>>v>>e;      
   vector<int> adj[v+1];
    
   for (int i = 1; i <= e; i++)
   {    
        cout<<"Enter adjacent node";
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
   }
   

   for(auto it : toposort(v, adj)){
    cout<<it<<" ";
   }

          
          
return 0;
}
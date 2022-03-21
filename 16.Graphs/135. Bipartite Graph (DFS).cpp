#include <bits/stdc++.h>
using namespace std;
//time=O(N+E) n nodes,e e through traversing through adj nodes overall
//space=O(N+E) adj list + O(n) color array + O(N) auxilary space
bool bipartiteDfs(int node, vector<int> adj[], int color[]) {
    for(auto it : adj[node]) { //traverse to all its adjaacent
        if(color[it] == -1) { //if adjacent not colored
            color[it] = 1 - color[node];//colcor it with exact opposite color,1-0=1,1-1=0
            if(!bipartiteDfs(it, adj, color)) {//call the dfs 
                return false; //graph not bipartitie
            }
        } else if(color[it] == color[node]) return false; 
    }
    return true; 
}
bool checkBipartite(vector<int> adj[], int n) {//list,no. of nodes
    int color[n];
    memset(color, -1, sizeof color); //color array init to -1 completely,stl function which will do that
    for(int i = 0;i<n;i++){ //mcheck for multiple component
        if(color[i] == -1){ //if not colored or not visited
            color[i] = 1; //make colored
            if(!bipartiteDfs(i, adj, color)) {
                return false;
            }
        } 
    }
    return true; //if all follows property of bipartite
}
void addedge(vector<int> adj[],int u,int v)
{
        adj[u].push_back(v); 
        adj[v].push_back(u);
}
int main() {
    
    vector<int> adj[6];
    addedge(adj,0,1);
    addedge(adj,1,2);
    addedge(adj,1,4);
    addedge(adj,1,5);
    addedge(adj,2,3);
    addedge(adj,3,4);
    addedge(adj,3,5);

    if(checkBipartite(adj, 6)) {
        cout << "It is a Bipartite Graph"; 
    } else {
        cout << "It is not a Bipartite Graph"; 
    }
    return 0;
}
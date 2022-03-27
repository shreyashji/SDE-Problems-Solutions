#include <bits/stdc++.h>
using namespace std;
//time= O(N+e) dfs
//space= O(2N) two array + auxilary space O(N) ~~O(N)

void dfs(int node, int parent, vector<int> &vis, vector<int> &tin, vector<int> &low, int &timer, vector<int> adj[]) {
    vis[node] = 1; //mark it as vsited
    tin[node] = low[node] = timer++; //time of insertion
    for(auto it: adj[node]) {//traverse for all its adjacent
        if(it == parent) continue; //if parent dont do a dfs call or neither did update low,parent node its going backward,and it never went back
         //or else if its unvisited,call a dfs & increase time of insertion
        if(!vis[it]) {
            dfs(it, node, vis, tin, low, timer, adj); 
            low[node] = min(low[node], low[it]); //after dfs,dfs over came back,always update low->whatever adjacent called for dfs
            ///took its low of it ans assign it to low of node comparing with crnt lowof node,if it is smaller once it is updated
            if(low[it] > tin[node]) {//while we come back we check we can reach back low[it] > tin[node] means cannot reach back
                cout << node << " " << it << endl;
            }
        } else {
            low[node] = min(low[node], tin[it]); 
        }
    }
}
int main() {
    int n, m; //nodes& edges
    cin >> n >> m; 
	vector<int> adj[n]; 
	for(int i = 0;i<m;i++) {//taken graph input in adjacency list
	    int u, v;
	    cin >> u >> v; 
	    adj[u].push_back(v);
	    adj[v].push_back(u); 
	}
	
	vector<int> tin(n, -1); //time of insertion
	vector<int> low(n, -1); //low with size n
	vector<int> vis(n, 0);  //for dfs
	int timer = 0; //initial timer fo starting 
	for(int i = 0;i<n;i++) { //for multiple components dfs
	    if(!vis[i]) {
	        dfs(i, -1, vis, tin, low, timer, adj); //node i having parent of -1
	    }
	}
	
	return 0;
}
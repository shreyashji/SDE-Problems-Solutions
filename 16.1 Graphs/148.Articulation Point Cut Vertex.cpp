#include <bits/stdc++.h>
using namespace std;
//time= O(N+e) dfs
//space= O(2N) two array + auxilary space O(N) ~~O(N) overall
void dfs(int node, int parent, vector<int> &vis, vector<int> &tin, vector<int> &low, int &timer, vector<int> adj[], vector<int> &isArticulation) {
    vis[node] = 1; //crnt node marked as visited
    tin[node] = low[node] = timer++;//time of insertion
    int child = 0; //just to count individual child,only be used for 1 time,if it is starting point
    for(auto it: adj[node]) {//traverse for all its adjacent nodes
        if(it == parent) continue;//if its parent dont do anythiing continue
        
        if(!vis[it]) {//if adj is unvisited call dfs
            dfs(it, node, vis, tin, low, timer, adj, isArticulation); 
            low[node] = min(low[node], low[it]); //when we come back update the low
	    child++; 
            if(low[it] >= tin[node] && parent != -1) { //check for condition
                isArticulation[node] = 1; //dont print the node just marking it
            }
        } else {//if already visited,it cannot be articulation point,just borrow the minimal time of insertio tin ,borrow it comapre it and update it if smaller
            low[node] = min(low[node], tin[it]); 
        }
        
    }
    //once dfs has been traversal over for all nodees
    if(parent == -1 && child > 1) {//if its the first node & individual child>1 ,mark its as articulation point
        isArticulation[node] = 1; 
    }
}
int main() {
    int n, m;
    cin >> n >> m; 
	vector<int> adj[n]; 
	for(int i = 0;i<m;i++) {
	    int u, v;
	    cin >> u >> v; 
	    adj[u].push_back(v);
	    adj[v].push_back(u); 
	}
	
	vector<int> tin(n, -1);
	vector<int> low(n, -1); 
	vector<int> vis(n, 0);
	vector<int> isArticulation(n, 0); //hash for multiple time node as articulation point fro marking
	int timer = 0; 
	for(int i = 0;i<n;i++) {//for multiple components dfs
	    if(!vis[i]) {
	        dfs(i, -1, vis, tin, low, timer, adj, isArticulation); 
	    }
	}
	
	for(int i = 0;i<n;i++) {
	    if(isArticulation[i] == 1) cout << i << endl; //print i that will print all my articulation point
	}
	
	return 0;
}
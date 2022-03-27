#include <bits/stdc++.h>
using namespace std;
//step 1: O(N+E) toposort
//step 2: O(N+E) transpose the graph
//step 3: O(N+E) dfs according to finishing time
//over all time(c)= O(N+E)
//space (c) = O(N+E) fro transpose graph + O(n) visited array for dfs + O(N) stack
void dfs(int node, stack<int> &st, vector<int> &vis, vector<int> adj[]) { //tosort dfs
    vis[node] = 1; 
    for(auto it: adj[node]) {
        if(!vis[it]) {
            dfs(it, st, vis, adj); 
        }
    }
    st.push(node); //whenever come back from dfs insert node  into stack
}
void revDfs(int node, vector<int> &vis, vector<int> transpose[]) {
    cout << node << " "; //all nodes part of sccc got printed
    vis[node] = 1; 
    for(auto it: transpose[node]) {
        if(!vis[it]) {
            revDfs(it, vis, transpose); 
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m; //taking input
	vector<int> adj[n]; 
	for(int i = 0;i<m;i++) {
	    int u, v;
	    cin >> u >> v; 
	    adj[u].push_back(v);
	}
	
	stack<int> st; //step 1 : topo sort ,sort all nodes according to finish time
	vector<int> vis(n, 0); 
	for(int i = 0;i<n;i++) {
	    if(!vis[i]) {
	        dfs(i, st, vis, adj); 
	    }
	} 
	
	vector<int> transpose[n]; //step 2 :transpose,declaring 1 more adjecency matrix to do the transpose
	
	for(int i = 0;i<n;i++) {
	    vis[i] = 0; //remarked the visited as 0,coz while doing topologicla sort dfs it's marked as 1 in visited
	    for(auto it: adj[i]) { //prevously there is an edge from i to it
	        transpose[it].push_back(i); //now there is an edge from it to i
	    }
	}
	//step3: dfs according to finishing time
	while(!st.empty()) {
	    int node = st.top();//got ot the nodes according to their finishing time
	    st.pop(); //and popout
	    if(!vis[node]) { 
	        cout << "SCC: "; 
	        revDfs(node, vis, transpose); //if unvisited call reverse dfs(which works for transpose graph)
	        cout << endl; 
	    }
	}
	
	
	return 0;
}

/*
5 5 
0 1 
1 2 
2 0 
1 3 
3 4 
*/
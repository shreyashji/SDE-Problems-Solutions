#include<bits/stdc++.h>
using namespace std;
 // o- based indexing code
//time=O(N+E) n nodes,e e through traversing through adj nodes overall
//space=O(N+E) adj list + O(n) visited array + O(N) queue 
class Solution {
public:
    bool checkForCycle(int node, int parent, vector<int> &vis, vector<int> adj[]) {
        vis[node] = 1; 
        for(auto it: adj[node]) { //traverse for its adjacent nodes
            if(!vis[it]) { //if unvisisted
                if(checkForCycle(it, node, vis, adj)) //call dfs traversal
                    return true; //if cycle true
            }
            else if(it!=parent) //if not visited,if previouslt visited node it not equal to parent
                return true; 
        }
        return false; //dfs call done entirely  ,false if no cycle
    }
public:
	bool isCycle(int V, vector<int>adj[]){
	    vector<int> vis(V+1, 0); 
	    for(int i = 0;i<V;i++) { //traverse from 1 to no. of nodes
	        if(!vis[i]) { //traverse for all adjacent components ,if unvisisted
	            if(checkForCycle(i, -1, vis, adj)) 
                return true; 
	        }
	    }    
	    return false; 
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isCycle(V, adj);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends
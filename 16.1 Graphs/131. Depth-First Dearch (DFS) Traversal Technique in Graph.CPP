#include<bits/stdc++.h>
using namespace std;
//TIME = O(n) ntraversing  n nodes + O(n) ,not n*n coz only calling for components
//SPACE=  O(N)visited arry + adj list
class Solution {
    void dfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &storeDfs) {
        storeDfs.push_back(node); 
        vis[node] = 1; //mark them as visited
        for(auto it : adj[node]) {//trverse to all its adj nodes
            if(!vis[it]) {//for every node check if not visited then i only call  recursive dfs traversal
                dfs(it, vis, adj, storeDfs); //once it complt one recursion then go to nxt it
            }
        }
    }
public:
	vector<int>dfsOfGraph(int V, vector<int> adj[]){
	    vector<int> storeDfs; //store dfs traversal
	    vector<int> vis(V+1, 0); //created visited array of size n,everthing initilized to zero
        for(int i = 1;i<=V;i++) { //for loop for every component
        if(!vis[i]) dfs(i, vis, adj, storeDfs);  //if unvisited call dfs traversal
      }
	    return storeDfs; 
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int>ans=obj.dfsOfGraph(V, adj);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
	}
	return 0;
}  // } Driver Code Ends
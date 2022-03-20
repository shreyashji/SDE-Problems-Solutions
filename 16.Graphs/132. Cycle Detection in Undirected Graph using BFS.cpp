#include<bits/stdc++.h>
using namespace std;
// } Driver Code Ends
class Solution {
public:
//time=O(N+E) n nodes,e e through traversing through adj nodes overall
//space=O(N+E) adj list + O(n) visited array + O(N) queue 
    bool checkForCycle(int s, int V, vector<int> adj[], vector<int>& visited){//s=starting node,no of nodes V,list ,visited arry
        vector<int> parent(V, -1);
        // Create a queue for BFS
        queue<pair<int,int>> q;//store node & previous node
        visited[s] = true;//starting node visited
        q.push({s, -1});//inserting starting node with previous as -1 initialy
        while (!q.empty()) {
            int node = q.front().first;//take topmost elemnt in queue node & previous
            int par = q.front().second;
            q.pop();
     
            for (auto it : adj[node]) { //traverse for all its adjacent nodes
                if (!visited[it]) { //if adjacent node is not visited yet
                    visited[it] = true; //mark it visited
                    q.push({it, node});//& put it into queue
                }
                else if (par != it) //if viisted & adj node is not among the previous one,means someone else has visited that
                    return true;//if adj node is visited that not equal to parent or previous means there is a cycle return a true
            }
        }
        return false;//if queue becomes empty,doesnt have a cycle return false
    }
public:
	bool isCycle(int V, vector<int>adj[]){ // v is nodes, strring in adj list
	    vector<int> vis(V, 0); //visited array initlized as zero
	    for(int i = 0;i<V;i++) {//for every componenent
	        if(!vis[i]) { //for every unvisited node
	            if(checkForCycle(i, V, adj, vis)) //starting node,no of nodes,graph,visisted array
                 return true; //return true if cycle
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
#include <bits/stdc++.h>
using namespace std;
//time=O(N+E) n nodes,e e through traversing through adj nodes overall
//space= O(N+E) adj list + O(n) for stack + o(n) for visited array
//auxilary space= O(N) auxilary space
class Solution{
    void findTopoSort(int node, vector<int> &vis, stack<int> &st, vector<int> adj[]) {
        vis[node] = 1; //mark visited
        for(auto it : adj[node]) { //traverse to all aadjacent nodes
            if(!vis[it]) { //if not visited
                findTopoSort(it, vis, st, adj);  //again call dfs function
            }
        }//simple dfs till here
        st.push(node); //whenever dfs call over push it to stack,simple change to dfs this only
    }
public:
	vector<int> topoSort(int N, vector<int> adj[]) { //vector return any toposort
	    stack<int> st; //stack for topo
	    vector<int> vis(N, 0);  //visited array marked as 0
	    for(int i = 0;i<N;i++) {//start from 0 to n
	        if(vis[i] == 0) { //not viisted ,call dfs
	            findTopoSort(i, vis, st, adj); 
	        }
	    }//once done all the traversal
	    vector<int> topo;
	    while(!st.empty()) { //take stack element put it into vector
	        topo.push_back(st.top()); 
	        st.pop(); 
	    }
	    return topo;    //return that vector
	}
};
// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;
        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }   
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);
        cout << check(N, res, adj) << endl;
    }
    return 0;
}  // } Driver Code Ends
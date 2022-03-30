// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{//dfs lamba tak jaega jab tak usko aisi node na mile jiske pass koi adjacent na ho
	public:
	//Function to return list containing vertices in Topological order. 
	void DFSRec(int s, stack<int>&st, vector<bool>&visited, vector<int> adj[]){//s means source,stack
	    visited[s] = true;
	    vector<int>data = adj[s];//
	    for(auto v: data){///pick every adjacent vertex
	        if(!visited[v]){
	            DFSRec(v, st, visited, adj);//if not visited again call dfs
	        }
	    }
	    st.push(s);//agar adjacent nahi milta h to push kar denge stack me,
	    //then function call return,if didnt find  any adjacnt push the node into stack till it reaches from where it get called
	//there is a highly chance it get discontinuous use for loop,if already visisted we will not call dfs 
	//vector me store karke bhi reverse kar sakte the
	    
	}
	vector<int> topoSort(int V, vector<int> adj[]) {
	    stack<int>st;
	    vector<bool>visited(V, false);
	    
	    for(int i=0; i<V; i++){
	        if(!visited[i]){
	            DFSRec(i, st, visited, adj);
	        }
	    }
	    
	    vector<int>ans;
	    while(!st.empty()){
	        int x = st.top();
	        st.pop();
	        ans.push_back(x);
	    }
	    return ans;
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
    
    if(V!=res.size())
    return 0;
    
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
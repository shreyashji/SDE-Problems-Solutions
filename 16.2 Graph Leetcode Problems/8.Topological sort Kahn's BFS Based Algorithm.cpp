/*
less dependent ->indefgree of vertex ->write first
multiple solution can exist 

vertex par jane ke lia jo jo vertex required h usko pehle likh chuke ha
1. store indegree of each vertex
2.create a queue data structure
3. store 0 indegree vertex in queue
4.  BFS 
WHILE(Q IS NOT EMPTY){
    INT U = Q.POP()
    print u
    for every adjacent v of u
        1.reduce indegree of v (after printing reduce indegree of its adjacent nodes or vertex, jab wo hat raha h to uska indegree bhi kam hoga)
        2. if indegree of v is 0 add it to queue
}
how to calculate indegree
adj[] list
0=1->2
1=2
2=3->0
4=null

indegree[1]++
indegree[2]++
indegree[2]++
*/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> ans;
	    queue<int>q;
	    
	    vector<int> indegree(V, 0);//size v ,intiled from 0
	    for(int i=0; i<V; i++){
	        vector<int> data = adj[i];//in  data we have 0 vertex ka kaunsa adjacent h
	        for(auto x: data){
	            indegree[x]++;//jisme arrow ja raha usme ++
	        }
	    }
	    
	    for(int i=0; i<V; i++){
	        if(indegree[i] == 0)
	            q.push(i);
	    }
	    
	    while(! q.empty()){
	        int u = q.front();
	        q.pop();
	        ans.push_back(u);
	        
	        for(auto v: adj[u]){ //for adjacent, adj[u] ko v kka nam diya
	            indegree[v]--;
	            if(indegree[v] == 0)
	                q.push(v);
	        }
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
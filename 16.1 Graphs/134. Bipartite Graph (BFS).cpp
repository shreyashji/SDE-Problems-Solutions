#include <bits/stdc++.h>
using namespace std;
//time=O(N+E) n nodes,e e through traversing through adj nodes overall
//space=O(N+E) adj list + O(n) visited array + O(N) queue
bool bipartiteBfs(int src, vector<int> adj[], int color[]) {//src=starting node
    queue<int>q;
    q.push(src); 
    color[src] = 1; 
    while(!q.empty()) { //strt bfs traversal
        int node = q.front(); //which ever at top get it
        q.pop();
        
        for(auto it : adj[node]) {//traverse for all its adjacent nodes
            if(color[it] == -1) {//if not been colored 
                color[it] = 1 - color[node]; //subtract 1 and get opoosite color & color it 1-0=1,1-1=0
                q.push(it); //once it is colored push it into queue ds
            } 
            else if(color[it] == color[node]) {//it has been already colored & just check if adjacent node have same color
                return false; //cannot be bipartite
            }
        }
    }
    //if every comp returns true ,return true
    return true; //if becomes empty,component definately bipartite
}
bool checkBipartite(vector<int> adj[], int n) {
    int color[n]; //color arr
    memset(color, -1, sizeof color);  //init with -1
    for(int i = 0;i<n;i++) {//for multiple components
        if(color[i] == -1) { //color acts as visited arr
            if(!bipartiteBfs(i, adj, color)) {
                return false;
            }
        }
    }
    return true; 
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
	
	if(checkBipartite(adj, n)) {
	    cout << "yes"; 
	} else {
	    cout << "No"; 
	}
	return 0;
}

/*
8 7 
0 1 
1 2 
2 3 
3 4 
4 6 
6 7 
1 7
4 5 

// bipartite graph example 
*/ 

/*
7 7 
0 1 
1 2 
2 3 
3 4 
4 6 
6 1
4 5 
// not bipartite example
*/
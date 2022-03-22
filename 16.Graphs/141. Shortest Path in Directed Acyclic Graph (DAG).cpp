#include <bits/stdc++.h> 
#define INF INT_MAX 
using namespace std; 
 //time = O(N+E)DFS * 2  BFS TO FIND DISTANCE
 //space= O(2n) stack space & dist array 
 //auxilary space = aux space of toposort
void findTopoSort(int node, int vis[], stack<int> &st, vector<pair<int,int>> adj[]) {
    vis[node] = 1; 
    for(auto it : adj[node]) {
        if(!vis[it.first]) { //mark all its adjacent node
            findTopoSort(it.first, vis, st, adj); 
        }
    }
    st.push(node); //dfs get oer put into stack
}
void shortestPath(int src, int N, vector<pair<int,int>> adj[]) 
{ 
	int vis[N] = {0};
	stack<int> st; 
	for (int i = 0; i < N; i++) 
		if (!vis[i]) 
			findTopoSort(i, vis, st, adj); 
			
	int dist[N];  //after finding toposort take dist array 
	for (int i = 0; i < N; i++) 
		dist[i] = 1e9; //mark everything in array as infinity or larger value
	dist[src] = 0; //to reach src dist will always be 0

	while(!st.empty())  //keep iterate on stack(store toposort) till its not empty
	{  
		int node = st.top(); //get the first element
		st.pop(); 
 
		if (dist[node] != INF) { //if node has been reached previously the value will never be infinty
		    for(auto it : adj[node]) { //if reached then only can reached adjacent node,travers for adhacent nodes 
		        if(dist[node] + it.second < dist[it.first]) {//inorder to get adj node check crnt node dist edge weight is it.second if bboth adds up and give smaller dist then the dist of adj node it.first
		            dist[it.first] = dist[node] + it.second; //simly replace
		        }
		    }
		}
	} 

	for (int i = 0; i < N; i++) //simplly print this ,if 1e9 means unreachable print infinity,if not print dist btw via this much dist
		(dist[i] == 1e9)? cout << "INF ": cout << dist[i] << " "; 
} 

int main() { 
	int n, m;
	cin >> n >> m;
	vector<pair<int,int>> adj[n]; // vector<pair<int,int>>adj[V] store adjacent node and edge weight
	for(int i = 0;i<m;i++) {
	    int u, v, wt;
	    cin >> u >> v >> wt; 
	    adj[u].push_back({v, wt}); 
	}	
	shortestPath(0, n, adj); 
	return 0; 
} 
#include<bits/stdc++.h>
using namespace std;
//time=O(N+E) n nodes,e e through traversing through adj nodes overall
//space= O(N+E) adj list + O(n) for queue + o(n) for indegree array
class Solution {
public:
	vector<int> topo(int N, vector<int> adj[]) {//taking nodes & graph
        queue<int> q; //defining queue
	    vector<int> indegree(N, 0);  //indegree array,everything marked as 0
	    for(int i = 0;i<N;i++) { //0 to n 
	        for(auto it: adj[i]) {//for every adjacent node it,there is a node incoming to that adjacent node
	            indegree[it]++; 
	        }
	    }
	    for(int i = 0;i<N;i++) { //added to queue which has indegree 0
	        if(indegree[i] == 0) {
	            q.push(i); 
	        }
	    }
	    vector<int> topo //store topo sort
	    while(!q.empty()) { //run bfs algo,run till not empty
	        int node = q.front(); //take it assign it to node & then delet that elemnt out
	        q.pop(); 
	        topo.push_back(node); //add that into topo sort
	        for(auto it : adj[node]) { //traverse to all its adjacent nodes
	            indegree[it]--;//subtract indegree by 1
	            if(indegree[it] == 0) { //just check if indegree =0 & add it to queue if
	                q.push(it); 
	            }
	        }//repeat this process for every node in the queue
	    }
	    return topo;
	}
};
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;
    	vector<int> adj[V];
    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}
    	Solution obj;
    	cout << obj.isCyclic(V, adj) << "\n";
    }
    return 0;
}
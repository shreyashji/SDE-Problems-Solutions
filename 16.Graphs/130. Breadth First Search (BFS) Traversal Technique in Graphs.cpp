class Solution {
public:
//time=O(N+E) n nodes,e e through traversing through adj nodes overall
//space=O(N+E) adj list + O(n) visited array + O(N) queue
	vector<int>bfsOfGraph(int V, vector<int> adj[]){//v nodes,storing graph in adjcency list
	    vector<int> bfs; //vector of integers,this will store traversal nodes
	    vector<int> vis(V, 0); //created visited array of size n
	    
        for(int i=0; i<=V ; i++){
            if(!vis[i]) { 

        queue<int> q;  //declared a queue
	    q.push(0); //push starting node of component
	    vis[0] = 1; //and mark as visisted

	    while(!q.empty()) { //we iterate till queue not becomes empty
	        int node = q.front();//took out first element & make sure it got deleted from queue
	        q.pop(); //for that element we can say that e have traversed that node
	        bfs.push_back(node); //so add that in bfs traversal vector
	        
	        for(auto it : adj[node]) { //all the adjacent node,put it into queue,traversing vector with forach llop
	            if(!vis[it]) { //if not visisted ,
	                q.push(it); //take that node push it into queue
	                vis[it] = 1; //also make sure to mark this node as visited
	            }
	        }
	    }
    }
}
	    
	    return bfs; 
	}

};
int main(){
	int tc;
	cin >> tc;
	// for multiple graphs
	while(tc--){
		int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    // 		adj[v].push_back(u); // uncomment this for undirected graoh 
    	}
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int>ans=obj.bfsOfGraph(V, adj);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
	}
	return 0;
}  
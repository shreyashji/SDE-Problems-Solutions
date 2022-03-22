
//time=O(N+E) n nodes,e e through traversing through adj nodes overall
//space= O(N+E) adj list + O(n) for queue + o(n) for distance array
void BFS(vector<int> adj[], int N, int src) {  //list,no. of nodes,source
	int dist[N]; ///dist array
	for(int i = 0;i<N;i++) dist[i] = INT_MAX; //everything marked as infinity or big no.
	queue<int>  q; //taken a queue
	
	dist[src] = 0; //take source & add to queue
	q.push(src);  

	while(q.empty()==false)  //bfs algo till queue become empty
	{ 
		int node = q.front(); //get the node from queue & take it out
		q.pop();
		 
		for(auto it:adj[node]){ //traverse for all its adjacent node
		    if(dist[node] + 1 < dist[it]){ //crnt node +1 taken dist there is an edge that is smaller than dist of it we got better path
		        dist[it]=dist[node]+1;//so replace it by new distance
		        q.push(it);//take that into queue
		    }
		} 
	} //queue will be empty
	for(int i = 0;i<N;i++) cout << dist[i] << " ";  //print all the distances ,that will be shortest dist from source
} 
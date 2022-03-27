#include<bits/stdc++.h>
using namespace std;
 //time = O(N+E) n nodes ,e edges + o(log n) for priority queue ~~O(n log n)
 //space= O(n) dist array + O(n) pq + O(n+e) adj list

int main(){
	int n,m,source;
	cin >> n >> m;
	vector<pair<int,int> > g[n+1]; 	// 1-indexed adjacency list for of graph

	int a,b,wt;
	for(int i = 0; i<m ; i++){
		cin >> a >> b >> wt; //edge btwnn a & b and weight wt
		g[a].push_back(make_pair(b,wt)); //stored that in a graph
		g[b].push_back(make_pair(a,wt));
	}	
	
	cin >> source;
	
	// Dijkstra's algorithm begins from here
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;//Priority Queue min-heap ; In pair => (dist,from)
	vector<int> distTo(n+1,INT_MAX); 	// 1-indexed array for calculating shortest paths; ,distance array
	
	distTo[source] = 0;
	pq.push(make_pair(0,source));	// (dist,from) dist 0 & source
	
	while( !pq.empty() ){ //bfs
		int dist = pq.top().first; //& dist from pq whichever is min
		int prev = pq.top().second; //get node
		pq.pop();//though it from  priority queue
		
		vector<pair<int,int> >::iterator it; //below iterate on adjecency list
		for( it = g[prev].begin() ; it != g[prev].end() ; it++){ //traverse in the graph for(auto it:g[prev]) 
			int next = it->first;  //for each loop way to get
			int nextDist = it->second;
			if( distTo[next] > distTo[prev] + nextDist){ // distTo[prev] or dist both are same,distTo[prev] this + nextDist distance between edge is smaller than required to reach next adjacent node
				distTo[next] = distTo[prev] + nextDist;//so update the next adjacent node dist to previous dist + edge ka weight which is nextdist
				pq.push(make_pair(distTo[next], next));//once updated put it into pq (firstdist,node)
			}
		}
		
	}
	
	cout << "The distances from source, " << source << ", are : \n";
	for(int i = 1 ; i<=n ; i++)	cout << distTo[i] << " ";//traverl from 1 to n and print all answer dist from src to every node i
	cout << "\n";
	
	return 0;
}
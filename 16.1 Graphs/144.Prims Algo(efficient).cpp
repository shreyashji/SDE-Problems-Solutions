#include<bits/stdc++.h>
using namespace std;
//heap ds to find minimal or priority queue in c++
//time=  O(n+e) + O(n log n) ~~O(n log n) 
//space = adj list+ 3 arrray + pq
int main(){
	int N,m;
	cin >> N >> m;
	vector<pair<int,int> > adj[N]; 

	int a,b,wt;
	for(int i = 0; i<m ; i++){ 
		cin >> a >> b >> wt;
		adj[a].push_back(make_pair(b,wt));
		adj[b].push_back(make_pair(a,wt));
	}	
	int parent[N]; 
    int key[N];     
    bool mstSet[N]; 
    for (int i = 0; i < N; i++)  //O(n)
        key[i] = INT_MAX, mstSet[i] = false; 
    priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq;

    key[0] = 0; 
    parent[0] = -1; 
    pq.push({0, 0});
    // Run the loop till all the nodes have been visited
    // because in the brute code we checked for mstSet[node] == false while computing the minimum
    // but here we simply take the minimal from the priority queue, so a lot of times a node might be taken twice
    // hence its better to keep running till all the nodes have been taken. 
    // try the following case: 
    // Credits: Srejan Bera
    // 6 7 
    // 0 1 5 
    // 0 2 10 
    // 0 3 100 
    // 1 3 50 
    // 1 4 200
    // 3 4 250
    // 4 5 50 
    while(!pq.empty()) //O(n)
    { 
        int u = pq.top().second; //take out minimal from pq // O(log n)  so=  O(n log n)
        pq.pop(); 
        
        mstSet[u] = true;  //mark in mst //this is not O(n)
        
        for (auto it : adj[u]) { //travers ein adj nodes   O(e) = O(n) * O(e)
            int v = it.first;
            int weight = it.second;
            if (mstSet[v] == false && weight < key[v]) {
                parent[v] = u; //init
		        key[v] = weight; 
                pq.push({key[v], v}); //inserted in pq where we marking key[v],
                //so the next time we iterate we try to find minimal,so pq will simply give an answer
            }
        }
            
    } 
    
    for (int i = 1; i < N; i++) 
        cout << parent[i] << " - " << i <<" \n"; 
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
//time = greater than O(N^2) 
//space= adj list,parent ,key,mst array
int main(){
	int N,m;
	cin >> N >> m; //n nodes ,m edges
	vector<pair<int,int> > adj[N]; 

	int a,b,wt;  //taking graph input in adjacency list
	for(int i = 0; i<m ; i++){ 
		cin >> a >> b >> wt;
		adj[a].push_back(make_pair(b,wt));
		adj[b].push_back(make_pair(a,wt));
	}	
	//required 3 different array
	int parent[N]; 
      
    int key[N]; 
      
    bool mstSet[N]; 
  
    for (int i = 0; i < N; i++) 
        key[i] = INT_MAX, mstSet[i] = false; 
  
    key[0] = 0; 
    parent[0] = -1; 
    int ansWeight = 0; //find minimal in the key array fro that iterate through adjacent keep on updating key as weel as parent
     
    for (int count = 0; count < N - 1; count++) //O(n)
    { 
        
        int mini = INT_MAX, u; 
  
        for (int v = 0; v < N; v++)  //O(n)
            if (mstSet[v] == false && key[v] < mini) //not part od mst 7 value is lesser than min
                mini = key[v], u = v; 
                
        mstSet[u] = true;  //once find out mark as true in mst
        
        for (auto it : adj[u]) { //iterate for all its adjacent nodes
            int v = it.first; //node v
            int weight = it.second; //edge weight
            if (mstSet[v] == false && weight < key[v]) //not part of mst so compare that weight with that key value,if prev key has been there then  compare  it
                parent[v] = u, key[v] = weight; //if not replace  it key,& mark that node as parent,coz we are coming from that node
        }      
    }  
    for (int i = 1; i < N; i++) 
        cout << parent[i] << " - " << i <<" \n"; 
	return 0;
}
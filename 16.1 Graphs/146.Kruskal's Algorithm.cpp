#include<bits/stdc++.h>
using namespace std;
struct node {
    int u;
    int v;
    int wt; 
    node(int first, int second, int weight) {
        u = first;
        v = second;
        wt = weight;
    }
};

bool comp(node a, node b) {//comparator sort according to weight
    return a.wt < b.wt; 
}

int findPar(int u, vector<int> &parent) {
    if(u == parent[u]) return u; 
    return parent[u] = findPar(parent[u], parent); 
}

void unionn(int u, int v, vector<int> &parent, vector<int> &rank) {
    u = findPar(u, parent);
    v = findPar(v, parent);
    if(rank[u] < rank[v]) {
    	parent[u] = v;
    }
    else if(rank[v] < rank[u]) {
    	parent[v] = u; 
    }
    else {
    	parent[v] = u;
    	rank[u]++; 
    }
}
int main(){
	int N,m;
	cin >> N >> m;
	vector<node> edges; 
	for(int i = 0;i<m;i++) {
	    int u, v, wt;
	    cin >> u >> v >> wt; 
	    edges.push_back(node(u, v, wt));  //store it into linear data structure
	}
	sort(edges.begin(), edges.end(), comp); //sort all the edges using comparator sort according to weight
	
	vector<int> parent(N); //parent for disjoint set ds
	for(int i = 0;i<N;i++) 
	    parent[i] = i; //parent init with i itself
	vector<int> rank(N, 0);  //init rank with 0 initially
	
	int cost = 0; //it will store mst cost
	vector<pair<int,int>> mst; //storing all the edges of mst
	for(auto it : edges) {//linearly iteraring over the edges coz those are sorted
	    if(findPar(it.v, parent) != findPar(it.u, parent)) {//connecting u and v when belong to different component
	        cost += it.wt; //donot belong to same component  take it into mst,add edge weight to cost & put it inot linear data structure
	        mst.push_back({it.u, it.v}); 
	        unionn(it.u, it.v, parent, rank); //belonging to two diff components,we are gona attach an edge & telling them you are prt of spanning tree
	    }
	}
	cout << cost << endl; //print out the cost of mst
	for(auto it : mst) cout << it.first << " - " << it.second << endl; //and all the edges involved in mst
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    bool checkCycle(int node, vector < int > adj[], int vis[], int dfsVis[]) {
      vis[node] = 1; //initilaly marked as 1 in botharray
      dfsVis[node] = 1;
      for (auto it: adj[node]) { //look for adjacent nodes
        if (!vis[it]) {//if adjacent nodes has not been visited
          if (checkCycle(it, adj, vis, dfsVis)) //not vissited call the recursion again
            return true; //if apparently gets a cycle in recurion call return true 
        } //if comes as false the other guy has to be visited,visted as weel as dfs visited return true
        else if (dfsVis[it]) { //if node has been visited ,return true cycle exist
          return true;
        }
      }
      dfsVis[node] = 0;//did not find a cycle return ,made it 0 dfs visit
      return false;//did not find a cycle
    }
public:
    bool isCyclic(int N, vector < int > adj[]) {//n = no. of nodes, adj list
      int vis[N], dfsVis[N];//two arrays
      memset(vis, 0, sizeof vis); //assign 0 to both arrays
      memset(dfsVis, 0, sizeof dfsVis);

      for (int i = 0; i < N; i++) { //traverse 0 to n nodes
        if (!vis[i]) { //if not visited
          // cout << i << endl; 
          if (checkCycle(i, adj, vis, dfsVis)) {
            return true;
          }
        }
      }
      return false;
    }
};

void addEdge(vector < int > adj[], int u, int v) {
  adj[u].push_back(v);
  adj[v].push_back(u);
}

int main() {

  int V = 6;

  vector < int > adj[V];
  addEdge(adj, 0, 1);
  addEdge(adj, 1, 2);
  addEdge(adj, 1, 5);
  addEdge(adj, 2, 3);
  addEdge(adj, 3, 4);
  addEdge(adj, 4, 0);
  addEdge(adj, 4, 1);

  Solution obj;
  if (obj.isCyclic(V, adj))
    cout << "Cycle Detected" << "\n";
  else
    cout << "No Cycle Detected";

  return 0;
}
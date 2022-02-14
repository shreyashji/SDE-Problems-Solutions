#include<bits/stdc++.h>
using namespace std;
//time= N nodes , m color O(N^m)
//space= color array to color it O(N)+O(N) auxilary space ,depth of recr tree
bool isSafe(int node, int color[], bool graph[101][101], int n, int col) {
    //int col=takes the color trying to do that with that node
  for (int k = 0; k < n; k++) {//traverse to all of its adjacent
  //if its an adjacent node,and color is equivalent to color that i am trying to do,means its not possible
    if (k != node && graph[k][node] == 1 && color[k] == col) {
      return false;
    }
  }
  return true;//none of the adjacent node was having the same color col
}
bool solve(int node, int color[], int m, int N, bool graph[101][101]) { //recursive function
  if (node == N) { //if colored n nodes return true
    return true;
  }

  for (int i = 1; i <= m; i++) {//try every color from 1 to m
    if (isSafe(node, color, graph, N, i)) {
      color[node] = i;
      if (solve(node + 1, color, m, N, graph)) return true;
      color[node] = 0;//if not return true, take off that color,thats backtracking
    }

  }
  return false;//if not possible to color with m colors,return false
}

//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.
bool graphColoring(bool graph[101][101], int m, int N) {
  int color[N] = {0}; //none  of the nodes are colored
  if (solve(0, color, m, N, graph)) return true;
  return false;
}

int main() {
  int N = 4;
  int m = 3;

  bool graph[101][101] = {
    (0, 1),
    (1, 2),
    (2, 3),
    (3, 0),
    (0, 2)
  };
  cout << graphColoring(graph, m, N);

}
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
//time= O(n-1)relaxation * O(E)
//space = O(n)dist array & storing edges 
int main(){
    int N,m;
    cin >> N >> m;
    vector<node> edges; 
    for(int i = 0;i<m;i++) {
        int u, v, wt;
        cin >> u >> v >> wt; 
        edges.push_back(node(u, v, wt)); 
    }

    int src;//taken src
    cin >> src; 


    int inf = 10000000; 
    vector<int> dist(N, inf); //dist array with infinite

    dist[src] = 0; //dist to src always 0

    for(int i = 1;i<=N-1;i++) {//1 to n-1 relaxation edges
        for(auto it: edges) {//iterate for every edge
            if(dist[it.u] + it.wt < dist[it.v]) { //if lesser update the distance
                dist[it.v] = dist[it.u] + it.wt; 
            }
        }
    }
//one more relaxation i all the edges
    int fl = 0; 
    for(auto it: edges) {
        if(dist[it.u] + it.wt < dist[it.v]) {//if dist is still still reducing,there is definately a -ive cycle,
            cout << "Negative Cycle"; 
            fl = 1; //have a counter and breakout
            break; 
        }
    }

    if(!fl) {//if the counter has not been set i can say i have shortest distance,print all the shortest distance
        for(int i = 0;i<N;i++) {
            cout << i << " " << dist[i] << endl;
        }
    }


    return 0;
}

/* 
6 7 
3 2 6 
5 3 1 
0 1 5 
1 5 -3 
1 2 -2 
3 4 -2 
2 4 3 
0
*/
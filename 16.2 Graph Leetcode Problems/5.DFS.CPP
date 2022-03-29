//https://www.youtube.com/watch?v=7jDCxMQW1GA&list=PLzjZaW71kMwSrxEtvK5uQnfNQ9UjGGzA-&index=8
/*
dfs->recursive in nature
PICK ONE VERTEX ,then call adjacent of that vertex,then again call dfs of that adjacent vertex


*/

void DFS(vector<int> adj[] ,int v,int s){
    vector<bool> visited(v,false);
    for(int i=0; i<v ; i++){
        if(visited==false){
            DFSRec(adj,i,visited);///is is src
        }
    }
 }

void DFSRec(vector<int> adj[],int s,  vector<bool> visited){
    visited[s]=true;//jo mila true kar do
    cout<<s<<endl;
    for(int u:adj[s] ) {//ab vertex mil gaya uske dosto ko find karo
        if(visited[u]==false) //if not visuted then cal dfs rec function again
            DFSRec(adj,u,visisted);//u as src
    }
}
/*
0->1,2
1->0,3,4
2->0,3
3->2,1,4
4->1,3
 
*/
//https://www.youtube.com/watch?v=pQTbrRhuWXI&list=PLzjZaW71kMwSrxEtvK5uQnfNQ9UjGGzA-&index=5
//THEIR IMMEDIATE FRIENDS THEN THEIR IMMEDIATE FRIENDS
//  1<-0->2->4&3 ,BFS= 0,1,2,3,4 
//IF VISITED ,WILLNOT VIST NEXT TIME

//count connected componenet  in undirected graph

void bfs(vector<int> adj[],int v){
    vector<bool> visited(v+1,false);
    count=0;
    for(int i=0; i<v ; i++){
        count++;//if call is happening again & again means discontinuos graph
        if(visited[i]==false)
        bfs(adj,i,visited)
    }
}
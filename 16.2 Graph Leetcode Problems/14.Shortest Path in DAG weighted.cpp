//https://www.youtube.com/watch?v=-Oe4PWZ6G6k&list=PLzjZaW71kMwSrxEtvK5uQnfNQ9UjGGzA-&index=18
/*
dist[v]= [infinity............]
dist[s]=0
find a topological sort of graph
for every vertex u in topological sort 
for(every adjacent v of u){
    if(dist[v]> dist[u]+weight(u,v))
    dist[v]  = dist[v] + weight(u,v)
}

*/
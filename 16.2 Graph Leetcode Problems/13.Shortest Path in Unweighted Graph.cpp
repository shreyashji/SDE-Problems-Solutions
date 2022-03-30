//bfs shortest path 1 edge away
//https://www.youtube.com/watch?v=yysA7ZM2jjA&list=PLzjZaW71kMwSrxEtvK5uQnfNQ9UjGGzA-&index=17
/*
1.initilize dist[v]:[infinity..................]
2. dist[s]=0;
3. init visited[]= [f,f,f,f,f]
4. create queue q
5. q.push;visited[s]=T
while(!q.empty()){
    int u= q.pop();
    for(every adjacent  v of u){
        if(!visited[v]){
            dist[v] = dist[u]+1//new u->v pop u and travers eon its adjacent v
            visited[v]=T ; q.push(v);
        }

    }
}
7. print dist[]

*/

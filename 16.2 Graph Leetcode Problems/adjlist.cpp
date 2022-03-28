/*
u(vertex)  v(edges)
0-1->2
1-2
2-3->1
3-1
space = O(V+E) =for undirected v+2e , directed v+e
=check if there is an edge from 'u' to 'v'=traverse in u O(V),go in 2 vector
=find all adjacent of 'u' =O(V)
=find degree of 'u'=how many edges are conn adj[2].size  O(1)
=add an edge =O(1) adj[2].push_back 2-3->1->5
=remove an edge =O(V)  
*/
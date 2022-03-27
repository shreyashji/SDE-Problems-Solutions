int parent[100000]
int rank [100000]

makeset(){
    for(int i =0; i<=n ; i++){
        parent[i]=i;
        rank[i]=0;
    }
}
//7->6->4->3
//if not using path compression working in logrithimic
findparent(int node){ //O(4 alpha)
    if (node==parent[node]){
        return node;
    }
    //else
    return parent[node]= findparent(parent[node]); //path compress by parent[node]=
}

void union(int u ,int v){
    u= findPar(u);
    v= findPar(v);
    if (rank[u] < rank[v]){
        parent[u] = v;
    }
    else if(ank[v] < rank[u]){
        parent[v]= u;
    }
    else { //if equal 
        parent[v]= u;
        rank[u]++;
    }


}

void main (){
    makeset();
    int m;
    cin>>m;
    while(m--){
        int u,v;
        union(u,v);

    }
    //if 2 & 3 belong to the same componenet or not
    if(findparent(2) != findparent(3)){
        cout<<"different componenet";
    }
    else {
         cout<<"same componenet";
    }
}
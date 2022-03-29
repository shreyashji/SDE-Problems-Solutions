//https://leetcode.com/problems/find-if-path-exists-in-graph/
//https://www.youtube.com/watch?v=QC4bDHEnmLM&list=PLzjZaW71kMwSrxEtvK5uQnfNQ9UjGGzA-&index=6
/*
Input: n = 3, edges = [[0,1],[1,2],[2,0]], start = 0, end = 2
Output: true
Explanation: There are two paths from vertex 0 to vertex 2:
- 0 → 1 → 2
- 0 → 2
*/
/*
umap.size() will give vertex which will be unique ,vector<vector<int>> will store connected vertex
*/
//if end vertex is true or visited return true
//fill the visted array,if discconected component then ther eis no path,if end one is visted then true not vissite means false
lass Solution {
public:
    //umap.size will give vertex --unique keys
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {  //n umap size
        
        unordered_map<int, vector<int>> umap;
        for(auto x: edges){
            vector<int>temp = x;  
            int u = temp[0];
            int v = temp[1];
            
            umap[u].push_back(v);//u to v  also v to u
            umap[v].push_back(u);
        }  //stored adjacent of 0 ,1,2 here 
        //the above part can be optimized
        
        vector<bool>visited(n+1, false);
        
        queue<int>q;
        q.push(start);
        visited[start] = true; 
        
        while(!q.empty()){
            int v = q.front();//take first element 0
            q.pop();
            
            vector<int>temp = umap[v]; //store v data
            
            for(int i=0; i<temp.size(); i++){
                int vertex = temp[i]; //stored vector in temp
                
                if(visited[vertex] == false){ ///now we wil access every elemnt of temp,or check every vertex 
                    q.push(vertex);
                    visited[vertex] = true;
                }
            }          
            if(visited[end]) //if true rturn,
                return visited[end];
        }
        return visited[end];      
    }
};
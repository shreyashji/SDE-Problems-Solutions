class Solution {
public:
 /*
 least dependency comes first,iske bad jispar zyada h wo,iske bad aur zyada h wo ayega
 loop is a trap
 topological sort ho sakta h ya nahi->graph me cycle h ya nahi ,detect sycle
 given edges are  ai,bi ,convert he eges in adjecncy list
 */   
    bool DFSRec(int s, vector<bool>&visited, vector<bool>&currVisited, vector<int>adj[]){
        visited[s] = true;
        currVisited[s] = true;
        vector<int>data = adj[s];
        
        for(auto x: data){
            if(!visited[x]){
                if(DFSRec(x, visited, currVisited, adj)){
                    return true;
                }
            }
            else if(visited[x] && currVisited[x]){//agar dodno true mens cycle
                return true;
            }
        }
        currVisited[s] = false;//trace back 
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        int n = numCourses;
        vector<bool>visited(n, false), currVisited(n, false);
        
        vector<int>adj[n];// making adj list 
        for(auto x: prerequisites){
            vector<int>data = x;
            int a = data[0];
            int b = data[1];
            adj[a].push_back(b);
        }
        
        for(int i=0; i<n; i++){
            if(!visited[i]){
                if(DFSRec(i, visited, currVisited, adj)){
                    return false;//if cycle
                }
            }
        }
        return true;
    }
};
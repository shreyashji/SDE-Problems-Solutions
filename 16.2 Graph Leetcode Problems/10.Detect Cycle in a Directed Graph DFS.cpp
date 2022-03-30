// https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool cycle(int s, vector<bool>&visited, vector<bool>&currVisited, vector<int> adj[]){
        visited[s] = true;
        currVisited[s] = true;
        for(auto x: adj[s]){//check for adjacent of src
            if(!visited[x]){
                if(cycle(x, visited, currVisited, adj))
                    return true;
            }
            else if(visited[x] == true && currVisited[x] == true){//if both are true then cycle detected
                return true;
            }
        }
        currVisited[s] = false;//when we callback to parent make it false
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool>visited(V, false), currVisited(V, false);
        for(int i=0; i<V; i++){
            if(!visited[i]){
                if(cycle(i, visited, currVisited, adj))
                    return true;
            }
        } 
        return false;
    }
};
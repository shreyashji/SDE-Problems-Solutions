//https://leetcode.com/problems/find-eventual-safe-states/submissions/
//https://www.youtube.com/watch?v=4ymVOCiQBtw&list=PLzjZaW71kMwSrxEtvK5uQnfNQ9UjGGzA-&index=15

class Solution {
public:
/*
terminal nodes : aisa vertex jiske bahar koi arrow na ja raha ho
,terminal node par pahucane wali node answers h ,terminal node itself an answer
if there is a loop we will not include it in answer loop/cycle me prent vertex ko chodkar rest wale ans
if 5 & 6 dont have any out going node thy are terminal now we have to find vertex which are ending at either of these terminals 2,4,5,6
*/
    //simple cycle detection code dfs
bool DFSRec(int s, vector<bool>&visited, vector<bool>&dfsVisited, vector<vector<int>>& graph, vector<bool> &present_cycle){
        visited[s] = true;
        dfsVisited[s] = true;
        
        vector<int>data = graph[s]; //find src adjacent
        for(auto x: data){
            if(!visited[x]){
                if(DFSRec(x, visited, dfsVisited, graph, present_cycle)){
                    return present_cycle[s] = true;//jo bhisrc se call kiye the usko true mark kar diya,its part of cycle,return true,that src is part of cycle
                }
            }
            else if(visited[x] && dfsVisited[x]){
                return present_cycle[s] = true;
            }
        }
        
        dfsVisited[s] = false;//retrace
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        
        int n = graph.size();
        vector<bool>visited(n, false), dfsVisited(n, false);
        vector<bool> present_cycle(n, false);
        
        for(int i=0; i<n; i++){
            if(!visited[i]){
                DFSRec(i, visited, dfsVisited,graph, present_cycle);
            }
        }
        
        for(int i=0; i<n; i++){
            if(!present_cycle[i]){//jo bhi agar false ata h 
                ans.push_back(i);//usko ans me push back karenge 
            }
        }
        return ans;
    }
};
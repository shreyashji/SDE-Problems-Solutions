class Solution {
public:
/*
1->110
2->110
3->001
find total no. of groups which is disconnected
*/    
    void dfs(int s, int n, vector<vector<int>>& isConnected, vector<bool>&visited){
        visited[s] = true;
        // s = 1
        // 0 1 2 3 4  -- index
        // 1 2 3 4 5  -- city name
        // 1 1 0 1 0  -- connection
        vector<int>adj;
        for(int i=0; i<n; i++ ){//src se adjacent kitne conected h
            int x =  isConnected[s][i];  // x = connection
            if(x == 1) //1 means connection is there
                adj.push_back(i);
        }
        
        for(auto x: adj){
            if(!visited[x]){
                dfs(x, n, isConnected, visited);
            }
        } 
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool>visited(n, false);
        int count = 0;
        
        for(int i=0; i<n; i++){
            if(!visited[i]){
                count++;
                dfs(i, n, isConnected, visited);
            }
        }
        return count;
    }
};
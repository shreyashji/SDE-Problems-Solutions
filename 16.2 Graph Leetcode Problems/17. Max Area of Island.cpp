class Solution {
public:
    /*
    1 KA GROUP IS ISLAND only 4 direction ,no diagonal
    biiger area means toal no. of 1 in an island is biigest or max area
    DFS,WHENEVER FOUND 1 INCREASE AREA VAR VALUE and change the 1 to 0 
    
    */
    bool isValid(int i, int j, int n, int m, vector<vector<int>>& grid){
        if(i>=0 && i<n && j>=0 && j<m && grid[i][j] == 1){
            return true;
        }
        return false;
    }
    
    void dfs(vector<vector<int>>& grid, int i, int j, int n, int m, int &area){
        area++;
        grid[i][j] = 0;
        
        if(isValid(i+1, j, n, m, grid)){//adhjacent 1 ko utaenge
            dfs(grid, i+1, j, n, m, area);
        }
        if(isValid(i-1, j, n, m, grid)){
            dfs(grid, i-1, j, n, m, area);
        }
        if(isValid(i, j+1, n, m, grid)){
            dfs(grid, i, j+1, n, m, area);
        }
        if(isValid(i, j-1, n, m, grid)){
            dfs(grid, i, j-1, n, m, area);
        }
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        
        for(int i=0; i<n;i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    int area = 0;
                    dfs(grid, i, j, n, m, area);
                    ans = max(ans, area);
                }
            }
        }
        
        return ans;
    }
};
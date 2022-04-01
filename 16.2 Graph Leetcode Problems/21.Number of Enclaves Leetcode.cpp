class Solution {
public:
/*  m row ,n coln in question in our solution its opposite
0->sea cell
1->land cell
4 direction 
group of 1 which is covered with water(0) ,find no. of cells 
1. traverse from boundry
2. call dfs where 1 convert it to 0
3.  count 1 in grid
*/
    int count(vector<vector<int>>& grid){//kitne 1 bache
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1)
                    ans++;
            }
        }
        
        return ans;
    }
    
    bool isValid(int i, int j, int n, int m, vector<vector<int>>& grid){
        if(i>=0 && i<n && j>=0 && j<m && grid[i][j] == 1 ){
            return true;
        }
        return false;
    }
    
    void dfs(int i, int j, int n, int m, vector<vector<int>>& grid){
        grid[i][j] = 0;//1 mila to 0 mark kardo boundry me
        
        int ax[4] = {1, -1, 0, 0};
        int ay[4] = {0, 0, 1, -1};
        
        for(int k=0; k<4; k++){
            int nx = i + ax[k];
            int ny = j + ay[k];
            
            if(isValid(nx,ny, n, m, grid)){
                dfs(nx, ny, n, m, grid);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(); //row
        int m = grid[0].size(); //coln ,to traverse dimension
        
        // boundary travers,top to bottom
        for(int i=0; i<n; i++){//for i
            int j = 0;
            if(grid[i][j] == 1){
                dfs(i, j, n, m, grid);
            }

            j = m-1; //making it 0
            if(grid[i][j] == 1){ //for j
                dfs(i, j, n, m, grid);
            }
        }
        //left to right
        for(int j=0; j<m; j++){
            int i = 0;
            if(grid[i][j] == 1){
                dfs(i, j, n, m, grid);
            }
            
            i = n-1;
            if(grid[i][j] == 1){
                dfs(i, j, n, m, grid);
            } 
        }
        return count(grid);  
    }
};
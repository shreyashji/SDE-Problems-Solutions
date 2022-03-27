//https://leetcode.com/problems/number-of-islands/
//time = 
//space= 
class Solution {
public:
    //to check index is valid or not
    bool isValid(int i, int j, int n , int m, vector<vector<char>>& grid){
        if(i>=0 && i<n && j>=0 && j<m && grid[i][j] == '1') //i=row,j
            return true;
        return false;
    }
    void numIslandsRec(int i, int j, int n , int m, vector<vector<char>>& grid){
        
        grid[i][j] = '0';
        
        if(isValid(i+1, j, n, m , grid)) //for right side 
            numIslandsRec(i+1, j, n, m, grid);
        
        if(isValid(i-1, j, n, m , grid)) //for left
            numIslandsRec(i-1, j, n, m, grid);
        
        if(isValid(i, j+1, n, m , grid)) //for upper
            numIslandsRec(i, j+1, n, m, grid);
        
        if(isValid(i, j-1, n, m , grid)) //for lower
            numIslandsRec(i, j-1, n, m, grid);     
    }
    
    int numIslands(vector<vector<char>>& grid) { 
        int n = grid.size(); //rows
        int m = grid[0].size();
        int ans = 0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1'){
                    ans++;
                    numIslandsRec(i, j, n, m, grid);
                }
            }
        }
        
        return ans;
    }
};
//https://leetcode.com/problems/number-of-islands/
//time = 
//space= 
/*
1 means island 0 means water
an island cover by water in all 4 sides horizontal & vertical no corener edges
dfs ,if all conncected(adjacent) 1 then count 1 island
if found 1 incr count n and mark its adjacent 0,n is no. of island
*/
class Solution {
public:
    //to check index is valid or not
    bool isValid(int i, int j, int n , int m, vector<vector<char>>& grid){//check index is valid or not,if goes out of scope
        if(i>=0 && i<n && j>=0 && j<m && grid[i][j] == '1') //i=row,j
            return true;
        return false;
    }
                 
    void numIslandsRec(int i, int j, int n , int m, vector<vector<char>>& grid){      
        grid[i][j] = '0';//mark 0,uske bad call karnge uske bagal wale,,upar wale,niche wale,agar 1 milta h to dfsrec function call kar denge
        
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
        int n = grid.size(); //rows ,length
        int m = grid[0].size();//col,breadth
        int ans = 0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1'){
                    ans++;//incr count
                    numIslandsRec(i, j, n, m, grid);//i,j,length,breadth,
                }
            }
        }   
    return ans;
    }
};
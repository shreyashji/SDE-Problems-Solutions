//https://leetcode.com/problems/surrounded-regions/
//https://www.youtube.com/watch?v=k08ZeUHjl9A&list=PLzjZaW71kMwSrxEtvK5uQnfNQ9UjGGzA-&index=22

class Solution {
public:
    /*
    aregion surrounded by x from all 4 sides if found then convert o to x
    exclude boundry from traversing
    jo 0 boundry par end ho raha h usko B se replace kar do ,AUR USKE ADJACENT KO BHI
    ,convert remaing to O to X
    */
    void convert(vector<vector<char>>& board){
        int n = board.size();
        int m = board[0].size();
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == 'B'){
                    board[i][j] = 'O';
                }
                else if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }    

    bool isValid(int i , int j, int n, int m, vector<vector<char>>& board){
        if(i>=0 && i<n && j>=0 && j<m && board[i][j] == 'O'){
            return true;
        }
        return false;
    }
    
    void dfs(vector<vector<char>>& board, int i , int j, int n, int m){
        board[i][j] = 'B';  //BOUNDT WALE 0 KO B SE MATK
        //MOVING IN 4 DIRECTION
        if(isValid(i+1, j, n, m, board)){
            dfs(board, i+1, j, n, m);
        }
        if(isValid(i-1, j, n, m, board)){
            dfs(board, i-1, j, n, m);
        }
        if(isValid(i, j+1, n, m, board)){
            dfs(board, i, j+1, n, m);
        }
        if(isValid(i, j-1, n, m, board)){
            dfs(board, i, j-1, n, m);
        }
    }
    
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        
        for(int i=0; i<n; i++){
            // left -> top TO bottom
            int j =0;
            if(board[i][j] == 'O'){
                dfs(board, i, j, n, m);
            }
            
            j = m-1;
            // right -> top TO bootm 
            if(board[i][j] == 'O'){
                dfs(board, i, j, n, m);
            }
        }
        
        for(int j=0; j<m; j++){
            
            // top -> left right
            int i =0;
            if(board[i][j] == 'O'){
                dfs(board, i, j, n, m);
            }
            
            i = n-1;
            // bottom -> left right
            if(board[i][j] == 'O'){
                dfs(board, i, j, n, m);
            }
        }
        convert(board);
    }
};
class Solution {
public:
//not efficient
//time = O( N^3 ) 
//space = O( N^3 ) 
    bool isSafe1(int row, int col, vector<string> board, int n) {
        // check upper diagonal ,upwards  \
        int duprow = row;
        int dupcol = col; 
        
        while(row >= 0 && col >= 0) {
            if(board[row][col] == 'Q') return false; //if there is q queen
            row--;
            col--;
        }
        
        
        col = dupcol; 
        row = duprow;
        while(col>=0) { //for midde <-- row will not change
            if(board[row][col] == 'Q') return false;
            col--; 
        }
    
        row = duprow;
        col = dupcol; 
        while(row<n && col>=0) {
            if(board[row][col] == 'Q') return false;
            row++;//col is going lef but row is increasing
            col--; 
        }
        
        //if do not find a queen ,safe to place a queen
        return true; 
    }
public: 
    void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n) {
        if(col == n) { //if reach nth index ,stor answer
            ans.push_back(board); 
            return; 
        }
    
        for(int row = 0;row<n;row++) { //tryin every row
            if(isSafe1(row, col, board, n)) { //is it safe to place a queenn there
                board[row][col] = 'Q'; 
                solve(col+1, board, ans, n); 
                board[row][col] = '.'; 
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans; 
        vector<string> board(n);
        string s(n, '.'); 
        for(int i = 0;i<n;i++) {
            board[i] = s; 
        }
         
        solve(0,board, ans, n); 
        return ans; 
    }
    
};
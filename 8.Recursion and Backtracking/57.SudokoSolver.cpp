class Solution {
    //Time Complexity: O(9(n ^ 2)), in the worst case, for each cell in the n2 board, we have 9 possible numbers.
    //Space Complexity: O(1), since we are refilling the given board itself, there is no extra space required, so constant space complexity.
public:
    void solveSudoku(vector<vector<char>>& board) {
         solve(board);
    }
    bool solve(vector<vector<char>>& board){
           for(int i = 0; i < board.size(); i++){ //traverse in the matrix
            for(int j = 0; j < board[0].size(); j++){ //traverse in the matrix
                 if(board[i][j] == '.'){ //check if it is empty
                     for(char c = '1'; c <= '9'; c++){ //try 1-9 characters
                            if(isValid(board, i, j, c)){ //check the 3 condition,we can place a char if condition true
                            board[i][j] = c; //if true filled character
                                  if(solve(board)) //again recursion,next possible no tobe filled
                                return true; 
                                  else
                                board[i][j] = '.'; //removed which we filled,we come back to an empty position
                                  }
                    }
                    
                    return false;
                }
            }
        }
        return true; //no empty place in matrix,we filled up everything,can return true
    }
    //think of indexing in matrix
    bool isValid(vector<vector<char>>& board, int row, int col, char c){
        for(int i = 0; i < 9; i++) {
            if(board[i][col] == c) //row increasing ,col is constant,to get col
                return false; 
            if(board[row][i] == c) //check for ith row and col,row is constant i is changing, to get row
                return false; 
            //to get box
            if(board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) //to check for submatrix
//3 * (row / 3) to get first block,+ i / 3 to get changing row no.,+ i % 3 to get changing col no
                return false; 
          }
        return true;
    }
};
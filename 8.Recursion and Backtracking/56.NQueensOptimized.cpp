#include <bits/stdc++.h
using namespace std;
class Solution {
    //time= O( N^2 )
    //space=  O( N^2 )
public: 
    void solve(int col, vector<string> &board, vector<vector<string>> &ans, 
               vector<int> &leftRow, 
               vector<int> &upperDiagonal, vector<int> &lowerDiagonal, int n) {
        if(col == n) {
            ans.push_back(board); 
            return; 
        }  
        for(int row = 0;row<n;row++) {
            if(leftRow[row]==0 && lowerDiagonal[row + col] == 0 
               && upperDiagonal[n-1 + col - row] == 0) {
                
                board[row][col] = 'Q'; //fill up the queen
                leftRow[row] = 1;  //mark them as 1
                lowerDiagonal[row+col] = 1; //mark them as 1
                upperDiagonal[n-1 + col - row] = 1;//mark them as 1
                solve(col+1, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);  //call recursion
                board[row][col] = '.'; //unmark remove the q 
                leftRow[row] = 0; //also unmark hashes
                lowerDiagonal[row+col] = 0; //also unmark hashes
                upperDiagonal[n-1 + col - row] = 0; //also unmark hashes
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
        vector<int> leftRow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0); 
        solve(0,board, ans, leftRow, upperDiagonal, lowerDiagonal, n); 
        return ans; 
    }
};

int main() {
  int n = 4; // we are taking 4*4 grid and 4 queens
  Solution obj;
  vector < vector < string >> ans = obj.solveNQueens(n);
  for (int i = 0; i < ans.size(); i++) {
    cout << "Arrangement " << i + 1 << "\n";
    for (int j = 0; j < ans[0].size(); j++) {
      cout << ans[i][j];
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}
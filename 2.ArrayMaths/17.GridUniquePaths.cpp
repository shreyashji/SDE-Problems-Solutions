
//recursive  brute force
/*
int countPaths (int i,int j,int n, int  m) {
    if(i==(n-1)&& j==(m-1)) return 1;
    if(i>=n || j>=m) return 0;
    //for bottom ad right 
    else return countPaths(i+1,j) + countPaths(i,j+1);
}
*/
//convert this to dynamic programming solution

/* optimized
int countPaths(int i,int j,int n, int  m, vector<vector<int>> &dp){
    if(i==(n-1)&& j==(m-1)) return 1;
    if(i>=n || j>=m) return 0;

    //if new recursion call is made simply check if that state previously visited or not
    if(dp[i][j]!==-1) return dp[i][j]; 
    //what ever answer returning storing in dp tables before returning
    else return dp[i][j]= countPaths(i+1,j) + countPaths(i,j+1);
}
//time = O(n*m)  no further recr calls,if there is ,our hash table will return the ans
//space = O(n*M) =hash table and recursive space of O(n*m) approximate to O(n*m)

*/

//most optimal solution
class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = n + m - 2;  //Nc base r combination (maths)
        int r = m-1;
        double res = 1; //init res as 1
        //iterate for r
        for(int i=1; i<=r ; i++)
            res = res * (N-r+i)/i; // this is ncr which is combination here i=1*2*3,numerator wwill be
        // 10-3+1=8, 10-3+2=9, 10-3+3=10
        return (int) res;
    }
}; 
//time = O(m-1) or  (n-1)
//space= o(1)

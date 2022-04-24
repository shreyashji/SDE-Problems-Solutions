


//recurence
//time = O(exponential) ~~ 2^N , 2^M
//space = O(n+M) auxuialry stack space
class Solution {
private:
    int f(int i,int j,string s, string t){
        if(j < 0) return 1; //all amtch
        if(i < 0) return 0; //still some char left on s2 to match s1 exhausted
        
        if(s[i] == t[j]){
            return f(i-1,j-1,s,t) + f(i-1,j,s,t);
        }
        return f(i-1,j,s,t);
    }
public:
    
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
       return f(n-1,m-1,s,t);
    }
};

//memoization
//time = O(N*M) 
//space = O(N*M) + O(N+M) auxuialry stack space
class Solution {
private:
    int f(int i,int j,string &s, string &t,vector<vector<int>> &dp){
        if(j < 0) return 1; //all amtch
        if(i < 0) return 0; //still some char left on s2 to match s1 exhausted
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == t[j]){
            return dp[i][j] = f(i-1,j-1,s,t,dp) + f(i-1,j,s,t,dp);
        }
        return dp[i][j] = f(i-1,j,s,t,dp);
    }
public:
    
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n,vector<int> (m,-1));
       return f(n-1,m-1,s,t,dp);
    }
};

//tabulation
// 1 based indexing in lcs
//add a +1 everything we are doing,when comparing compare as 0 based,string  is 0 based
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<double>> dp(n+1,vector<double> (m+1,0));
        for( int i =0 ; i<=n; i++ ) dp[i][0] = 1; //base case 
        //for( int j =1 ; j<=m; j++ ) dp[0][j] = 0; //base case,coz already m+1 ,initlized to 0
        
        for(int i = 1; i<=n ; i++ ) {
            for(int j = 1; j<=m ; j++ ){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }
                else 
                {
                    dp[i][j] = dp[i-1][j];    
                }
            }
        }
       return (int)dp[n][m];
    }
};


// 2 arry space optimization
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<double> prev(m+1, 0) , curr(m+1,0);
        prev[0] = curr[0] = 1;
        
        for(int i = 1; i<=n ; i++ ) {
            for(int j = 1; j<=m ; j++ ){
                if(s[i-1] == t[j-1]){
                    curr[j] = prev[j-1] + prev[j];
                }
                else 
                {
                    curr[j] = prev[j];    
                }
            }
            prev= curr;
        }
       return (int)prev[m];
    }
};

//1 array space optimized
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<double> dp(m+1, 0);
        dp[0] = 1;
        
        for(int i = 1; i<=n ; i++ ) {
            for(int j = m; j>=1 ; j-- ){
                if(s[i-1] == t[j-1]){
                    dp[j] = dp[j-1] + dp[j];
                }
                /*else 
                {
                    prev[j] = prev[j];    
                } */
            }
        }
       return (int)dp[m]; 
    }
};
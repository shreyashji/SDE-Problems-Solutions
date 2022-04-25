//recurrence 
//time = O(exponential)
//space = O(N+M)
class Solution {
private:
    int f(int i, int j, string &s1, string &s2) {
        if(i < 0) return j+1 ;
        if(j < 0) return i+1 ;

        if(s1[i] == s2[j]) return f(i-1, j-1 , s1,s2);
        return 1 + min( f(i-1, j,s1,s2,dp) ,
                       min(f(i, j-1,s1,s2), 
                       f(i-1, j-1,s1,s2))); // insert,delete,replace
    }
public:
    int minDistance(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        return f(n-1,m-1, str1,str2);
    }
};


//memoization
//time =O(N*M)
//space =O(N*M) + O(N+M) stack space auxilary
class Solution {
private:
    int f(int i, int j, string &s1, string &s2,vector<vector<int>> &dp) {
        if(i < 0) return j+1 ;
        if(j < 0) return i+1 ;
        if( dp[i][j] != -1) return  dp[i][j];
        if(s1[i] == s2[j]) return dp[i][j] = f(i-1, j-1 , s1,s2,dp);
        return dp[i][j] = 1 + min( f(i-1, j,s1,s2,dp) ,
                       min(f(i, j-1,s1,s2,dp), 
                       f(i-1, j-1,s1,s2,dp))); // insert,delete,replace
        
    }
public:
    int minDistance(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1) );
        return f(n-1,m-1, str1,str2,dp);
    }
};

//1 based indexing,so -ive indexes dont get involved
class Solution {
private:
    int f(int i, int j, string &s1, string &s2,vector<vector<int>> &dp) {
        if(i == 0) return j ;
        if(j == 0) return i ;
        if( dp[i][j] != -1) return  dp[i][j];
        if(s1[i-1] == s2[j-1]) return dp[i][j] = f(i-1, j-1 , s1,s2,dp);
        return dp[i][j] = 1 + min( f(i-1, j,s1,s2,dp) ,
                       min(f(i, j-1,s1,s2,dp), 
                       f(i-1, j-1,s1,s2,dp))); // insert,delete,replace
        
    }
public:
    int minDistance(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1) );
        return f(n,m, str1,str2,dp);
    }
};

//tabulation
class Solution {
public:
    int minDistance(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0) );
        
        for(int i=0 ; i<=n ; i++) return dp[i][0] = i;
        for(int j=0 ; j<=m ; j++) return dp[0][j] = j;

        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<=m ; j++){
                if(str1[i-1] == str2[j-1]) 
                    dp[i][j] = dp[i-1][j-1];
                   else
                    dp[i][j] = 1 + min(dp[i-1][j] ,
                                min(dp[i][j-1], 
                                dp[i-1][j-1])); // insert,delete,replace   
                }
            }
        return dp[n][m];
    }
};

//2 array space optimization
int editDistance(string str1, string str2)
{
	int n = str1.size();
    int m = str2.size();
	vector<int> prev(m+1,0), curr(m+1,0);
	for(int j=0 ; j<=m ; j++) prev[j] = j;
	
	for(int i=1 ; i<=n ; i++){
		curr[0] =i; //for everytime using curr ,always have i, or sswe have to update its 0 th guy
		for(int j=1 ; j<=m ; j++){
			if(str1[i-1] == str2[j-1]) 
				curr[j] = prev[j-1];
       		else
				curr[j] = 1 + min(prev[j] ,
								min(curr[j-1], 
								prev[j-1])); // insert,delete,replace   
		}
		prev = curr;
	}
    return prev[m];
}

//cant optimized to 1 array,we need to store both rows
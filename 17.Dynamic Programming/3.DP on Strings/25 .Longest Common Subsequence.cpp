//recursion 
//time = O(2^N) ~~exponential
//space = exponential
int f(int i,int j,string &s, string &t){
	if(i<0 || j<0) return 0; //base case
	
	if(s[i]==t[j]) return 1 + f(i-1,j-1,s,t);//matching
	return max(f(i-1,j,s,t),f(i,j-1,s,t)); //not matching
	
}

int lcs(string s, string t)
{
	int n= s.size();
	int m= t.size();
	return f(n-1,m-1,s,t);
}

//memoization
/*
Time Complexity: O(N*M) Reason: There are N*M states therefore at max ‘N*M’ new problems will be solved.
Space Complexity: O(N*M) + O(N+M)
Reason: We are using an auxiliary recursion stack space(O(N+M)) (see the recursive tree, in the worst case, we will go till N+M calls at a time) and a 2D array ( O(N*M)).
*/
#include<bits/stdc++.h> 
int f(int i,int j,string &s, string &t,vector<vector<int>> &dp){
	if(i<0 || j<0) return 0; //base case
	
	if(dp[i][j] != -1) return dp[i][j];
	
	if(s[i]==t[j]) return dp[i][j] = 1 + f(i-1,j-1,s,t,dp);//matching
	return dp[i][j] = max(f(i-1,j,s,t,dp),f(i,j-1,s,t,dp)); //not matching
}

int lcs(string s, string t){
	int n= s.size();
	int m= t.size();
	vector<vector<int>> dp(n,vector<int>(m,-1));
	return f(n-1,m-1,s,t,dp);
}

//tabulation :bottom uup
/*
Time Complexity: O(N*M) ,Reason: There are two nested loops
Space Complexity: O(N*M), Reason: We are using an external array of size ‘N*M)’. Stack Space is eliminated.
*/
#include<bits/stdc++.h> 
int lcs(string s, string t){
	int n= s.size();
	int m= t.size();
	vector<vector<int>> dp(n+1,vector<int>(m+1,0));
	for(int j=0; j<=m; j++) dp[0][j]=0;
	for(int i=0; i<=n; i++) dp[i][0]=0;
	
	for(int i=1 ; i<=n ; i++){
		for(int j=1 ; j<=m ; j++){
			if(s[i-1]==t[j-1]) dp[i][j] = 1 + dp[i-1][j-1];//matching
			else dp[i][j] = max(dp[i-1][j],dp[i][j-1]); //not matching
		}
	}
	return dp[n][m];
}

//space optimized
/*
Time Complexity: O(N*M) ,Reason: There are two nested loops.
Space Complexity: O(M) ,Reason: We are using an external array of size ‘M+1’ to store only two rows.
*/
#include<bits/stdc++.h> 
int lcs(string s, string t){
	int n= s.size();
	int m= t.size();
	vector<int> prev(m+1,0) ,curr(m+1,0);
	for(int j=0; j<=m; j++) prev[j]=0; //for 1st row every one is 0
	//for(int i=0; i<=n; i++) dp[i][0]=0;
	
	for(int i=1 ; i<=n ; i++){
		for(int j=1 ; j<=m ; j++){
			if(s[i-1]==t[j-1]) curr[j] = 1 + prev[j-1];//matching
			else curr[j] = max(prev[j],curr[j-1]); //not matching
		}
		prev= curr ;
	}
	return prev[m];
}
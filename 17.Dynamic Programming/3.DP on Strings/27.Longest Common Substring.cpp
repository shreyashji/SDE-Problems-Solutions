
//tabulation
//time=O(N*M)
//space = O(N*M)
int lcs(string &s, string &t){
	int n= s.size();
	int m= t.size();
	vector<vector<int>> dp(n+1,vector<int>(m+1,0));
	for(int j=0; j<=m; j++) dp[0][j]=0;
	for(int i=0; i<=n; i++) dp[i][0]=0;
	int ans=0;
	for(int i=1 ; i<=n ; i++){
		for(int j=1 ; j<=m ; j++){
			if(s[i-1]==t[j-1]) {
				dp[i][j] = 1 + dp[i-1][j-1];
				ans = max(ans,dp[i][j]);
			}//matching
			else dp[i][j] = 0;//not matching
		}
	}
	return ans;
}

//space optimization

//time=O(N*M) ,here are two nested loops.
//Space Complexity: O(M) , Reason: We are using an external array of size ‘M+1’ to store only two rows.
int lcs(string &s, string &t){
	int n= s.size();
	int m= t.size();
	vector<int> prev(m+1,0),curr(m+1,0);
	//for(int j=0; j<=m; j++) curr[j]=0;
	//for(int i=0; i<=n; i++) dp[i][0]=0;
	//coz everything init to 0
	int ans=0;
	for(int i=1 ; i<=n ; i++){
		for(int j=1 ; j<=m ; j++){
			if(s[i-1]==t[j-1]) {
				curr[j] = 1 + prev[j-1];
				ans = max(ans,curr[j]);
			}//matching
			else curr[j] = 0;//not matching
		}
		prev = curr;
	}
	return ans;
}
//need to know lcs and longest palindromic subsequence problem we will use it
//https://www.codingninjas.com/codestudio/problems/minimum-insertions-to-make-palindrome_985293?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos


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
/*	for(int i=0; i<=n ;i++){ //i rows,j cols
		for(int j=0; j<=m ;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
*/
	return dp[n][m];
}
//lcs code above taulation,just reverse the string and pass
int longestPalindromeSubsequence(string s)
{
    string t=s;
	reverse(t.begin(),t.end());
	return lcs(s,t);
}

int minInsertion(string &str)
{
	return str.size() - longestPalindromeSubsequence(str);
}
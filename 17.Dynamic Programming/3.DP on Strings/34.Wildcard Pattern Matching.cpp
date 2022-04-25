//https://www.codingninjas.com/codestudio/problems/wildcard-pattern-matching_701650?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

//recurrence
//time = exponential
//space = O(N+M) auxilary stack space
bool f(int i,int j,string &pattern, string &text ){
	if(i<0 && j<0) return true; //both exhausted
	if(i<0 && j>=0) return false; //s2 have some strings for comparison,not possible
	if(j<0 && i>=0) {
		for(int ii=0; ii<=i; ii++){
			if(pattern[ii] != '*') return false;
		}
		return true;
	}
	if(pattern[i] == text[j] || pattern[i] == '?'){
		return f(i-1,j-1,pattern,text);
	}
	if(pattern[i] == '*'){
		return f(i-1,j,pattern,text) | f(i,j-1,pattern,text);
	}
	return false;
}

bool wildcardMatching(string pattern, string text)
{
	int n = pattern.size();
	int m = text.size();
	return f(n-1,m-1,pattern, text);
}

//memoization
//time= O(N*M) 
//space = O(N*M) + O(N+M) aux stack space
#include<bits/stdc++.h>
bool f(int i,int j,string &pattern, string &text,vector<vector<int>> &dp){
	if(i<0 && j<0) return true; //both exhausted
	if(i<0 && j>=0) return false; //s2 have some strings for comparison,not possible
	if(j<0 && i>=0) {
		for(int ii=0; ii<=i; ii++){
			if(pattern[ii] != '*') return false;
		}
		return true;
	}
	if(dp[i][j] !=-1) return dp[i][j];
	if(pattern[i] == text[j] || pattern[i] == '?'){
		return dp[i][j] = f(i-1,j-1,pattern,text,dp);
	}
	if(pattern[i] == '*'){
		return dp[i][j] = f(i-1,j,pattern,text,dp) | f(i,j-1,pattern,text,dp);
	}
	return dp[i][j]= false;
}

bool wildcardMatching(string pattern, string text)
{
	int n = pattern.size();
	int m = text.size();
	vector<vector<int>> dp(n,vector<int>(m,-1));
	return f(n-1,m-1,pattern, text,dp);
}
//1 based indexing fro tabulation
#include<bits/stdc++.h>
bool f(int i,int j,string &pattern, string &text,vector<vector<int>> &dp){
	if(i==0 && j==0) return true; //both exhausted
	if(i==0 && j>0) return false; //s2 have some strings for comparison,not possible
	if(j==0 && i>0) {
		for(int ii=1; ii<=i; ii++){
			if(pattern[ii-1] != '*') return false;//looking for 1 lesser 1 based indexing
		}
		return true;
	}
	if(dp[i][j] !=-1) return dp[i][j];
	if(pattern[i-1] == text[j-1] || pattern[i-1] == '?'){
		return dp[i][j] = f(i-1,j-1,pattern,text,dp);
	}
	if(pattern[i-1] == '*'){
		return dp[i][j] = f(i-1,j,pattern,text,dp) | f(i,j-1,pattern,text,dp);
	}
	return dp[i][j]= false;
}

bool wildcardMatching(string pattern, string text)
{
	int n = pattern.size();
	int m = text.size();
	vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
	return f(n,m,pattern, text,dp);
}

//tabulation
//time= O(N*M) 
//space = O(N*M) 
#include<bits/stdc++.h>
bool wildcardMatching(string pattern, string text)
{
	int n = pattern.size();
	int m = text.size();
	vector<vector<bool>> dp(n+1,vector<bool>(m+1,false)); 
	dp[0][0] == true; //if(i==0 && j==0) return true
	for(int j = 1 ; j<=m ;j++){ //if(i==0 && j>0) return false; 
		dp[0][j] = false;
	}
	for(int i=1 ; i<=n ; i++){ //if(j==0 && i>0)
		int flag = true;
		for(int ii=1; ii<=i; ii++){
			if(pattern[ii-1] != '*') {//looking for 1 lesser 1 based indexing
				flag = false; 
				break;
			}
		}
		dp[i][0] = flag; //if flase nver appear storew true,or appear the false 
	}
	//changing parameters
	for(int i=1; i<=n ;i++){
		for(int j=1 ; j<=m ; j++){ //copy the recursion
			if(pattern[i-1] == text[j-1] || pattern[i-1] == '?'){
				dp[i][j] = dp[i-1][j-1];
			}
			else if(pattern[i-1] == '*'){
				dp[i][j] = dp[i-1][j] | dp[i][j-1];
			}
			else dp[i][j] = false;
		}
	}
	return dp[n][m];
}
//space optimization
#include<bits/stdc++.h>
bool wildcardMatching(string pattern, string text)
{
	int n = pattern.size();
	int m = text.size();
	vector<bool> prev(m+1,false),curr(m+1,false); 
	prev[0] == true; //if(i==0 && j==0) return true
	for(int j = 1 ; j<=m ;j++){ //if(i==0 && j>0) return false; 
		prev[j] = false;
	}
	for(int i=1 ; i<=n ; i++){ //if(j==0 && i>0)

	}
	//changing parameters
	for(int i=1; i<=n ;i++){//before sstarting off asign the curr everytime 
		//curr is the curnt row coln & that curr  0th row has to be assigned everytime
		int flag = true;
		for(int ii=1; ii<=i; ii++){
			if(pattern[ii-1] != '*') {//looking for 1 lesser 1 based indexing
				flag = false; 
				break;
			}
		}
		//for every row you are assigning th 0th coln's value
		curr[0] = flag; //if flase nver appear storew true,or appear the false 
		
		for(int j=1 ; j<=m ; j++){ //copy the recursion
			if(pattern[i-1] == text[j-1] || pattern[i-1] == '?'){
				curr[j] = prev[j-1];
			}
			else if(pattern[i-1] == '*'){
				curr[j] = prev[j] | curr[j-1];
			}
			else curr[j] = false;
		}
		prev = curr;
	}
	return prev[m];
}



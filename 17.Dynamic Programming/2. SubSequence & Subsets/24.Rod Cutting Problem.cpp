//recurrence
//time = O(exponential)
//space = O(target)
int f(int ind, int N,vector<int> &price){
	if(ind==0){
		return N * price[0];
	}
	int nottake = 0 + f(ind-1,N,price);
	int take = INT_MIN;
	int rodLength = ind+1;
	if(rodLength <= N) {
		take = price[ind] + f(ind,N -rodLength,price);
	}
	return max(take,nottake);
}

int cutRod(vector<int> &price, int n)
{
	return f(n-1,n,price);
}

//memoization
//time = O(N*N)
//space = O(N*N) +O(target) auxilary sapce
#include<bits/stdc++.h>
int f(int ind, int N,vector<int> &price,vector<vector<int>> &dp){
	if(ind==0){
		return N * price[0];
	}
	if(dp[ind][N] != -1) return dp[ind][N];
	int nottake = 0 + f(ind-1,N,price,dp);
	int take = INT_MIN;
	int rodLength = ind+1;
	if(rodLength <= N) {
		take = price[ind] + f(ind,N -rodLength,price,dp);
	}
	return dp[ind][N] = max(take,nottake);
}

int cutRod(vector<int> &price, int n)
{
	vector<vector<int>> dp(n,vector<int> (n+1,-1));
	return f(n-1,n,price,dp);
}

//tabulation
//time = O(N*N)
//space = O(N*N) 
int cutRod(vector<int> &price, int n)
{
	vector<vector<int>> dp(n,vector<int> (n+1,0));
	for(int N=0; N<=n; N++ ){
		dp[0][N] =  N * price[0];
	}
	for(int ind=1; ind<n ;ind++){
		for(int N=0 ; N<=n ; N++){
			int nottake = 0 + dp[ind-1][N];
			int take = INT_MIN;
			int rodLength = ind+1;
			if(rodLength <= N) {
				take = price[ind] + dp[ind][N - rodLength];
			}
			dp[ind][N] = max(take,nottake);
		}
	}
	return dp[n-1][n];
}

//space optimized
// 2 array space optimization
//time = O(N*N)
//space = O(N*N) 
#include<bits/stdc++.h>
int cutRod(vector<int> &price, int n)
{
	//vector<vector<int>> dp(n,vector<int> (n+1,0));
	vector<int> prev(n+1,0),curr(n+1,0);
	for(int N=0; N<=n; N++ ){
		prev[N] =  N * price[0];
	}
	for(int ind=1; ind<n ;ind++){
		for(int N=0 ; N<=n ; N++){
			int nottake = 0 + prev[N];
			int take = INT_MIN;
			int rodLength = ind+1;
			if(rodLength <= N) {
				take = price[ind] + curr[N - rodLength];
			}
			curr[N] = max(take,nottake);
		}
		prev = curr;
	}
	return prev[n];
}

//space optimized 1 array
//time = O(N*N)
//space = O(N) We are using an external array of size ‘N+1’ to store only one row.
#include<bits/stdc++.h>
int cutRod(vector<int> &price, int n)
{
	//vector<vector<int>> dp(n,vector<int> (n+1,0));
	vector<int> prev(n+1,0);
	for(int N=0; N<=n; N++ ){
		prev[N] =  N * price[0];
	}
	for(int ind=1; ind<n ;ind++){
		for(int N=0 ; N<=n ; N++){
			int nottake = 0 + prev[N];
			int take = INT_MIN;
			int rodLength = ind+1;
			if(rodLength <= N) {
				take = price[ind] + prev[N - rodLength];
			}
			prev[N] = max(take,nottake);
		}
	}
	return prev[n];
}

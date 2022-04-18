
//recursion
//time= exponential greater than 2^n
//space= O(target)
nt f(int ind,int T,int *a){
	if(ind == 0 ){
		return (T % a[0] ==0 );
	}
	
	long nottake=  f(ind-1,T,a);
	long take=0;
	if(a[ind] <= T) take = f(ind,T-a[ind],a);
	
	return take+nottake;
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    return f(n-1,value,denominations);
}

//memoization
//time= O(N*T)
//space= O(N*T) + O(Target) auxilary space
#include<bits/stdc++.h>
int f(int ind,int T,int *a, vector<vector<long>> &dp){
	if(ind == 0 ){
		return (T % a[0] ==0 );
	}
	if(dp[ind][T] != -1) return dp[ind][T];
	long nottake =  f(ind-1,T,a,dp);
	long take=0;
	if(a[ind] <= T) take = f(ind,T-a[ind],a,dp);
	
	return dp[ind][T] = take+nottake;
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
	vector<vector<long>> dp(n,vector<long>(value + 1,-1));
    return f(n-1,value,denominations,dp);
}

//tabulation
//time= O(N*T)
//space= O(N*T) 
long countWaysToMakeChange(int *a, int n, int value)
{
	vector<vector<long>> dp(n,vector<long>(value + 1,0));
	for(int T=0; T<=value ; T++){
		dp[0][T] == (T % a[0] ==0 ); 
	}
	
	for(int ind= 1 ; ind<n ; ind++){
		for(int T= 0; T<=value; T++){
			long nottake =  dp[ind-1][T];
			long take=0;
			if(a[ind] <= T) take = dp[ind][T-a[ind]];

			dp[ind][T] = take+nottake;
		}
	}
    return dp[n-1][value];
}

//space optimized
//time= O(N*T)
//space= O(T) 
#include<bits/stdc++.h>
long countWaysToMakeChange(int *a, int n, int value)
{
	vector<long> prev(value+1,0),curr(value+1,0);
	for(int T=0; T<=value ; T++){
		prev[T] == (T % a[0] ==0 ); 
	}
	
	for(int ind= 1 ; ind<n ; ind++){
		for(int T= 0; T<=value; T++){
			long nottake =  prev[T];
			long take=0;
			if(a[ind] <= T) take = curr[T-a[ind]];

			curr[T] = take+nottake;
		}
		prev= curr;
	}
    return prev[value];
}
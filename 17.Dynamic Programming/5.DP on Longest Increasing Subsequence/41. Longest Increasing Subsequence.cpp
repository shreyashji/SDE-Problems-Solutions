



//recurrence
//time = O(2^n) ~~ exponential
//space =  O(N)
int f(int ind, int prev_ind,int arr[], int n){
	if(ind == n) return 0;
	
	int len = 0 + f(ind+1,prev_ind,arr,n); //not take case
	if(prev_ind == -1 || arr[ind] > arr[prev_ind]){ //take case
		len = max(len, 1 + f(ind+1,ind,arr,n));
	}
	return len;
}

int longestIncreasingSubsequence(int arr[], int n)
{
	return f(0,-1,arr,n);
}


//memoization
#include<bits/stdc++.h>
int f(int ind, int prev_ind,int arr[], int n,vector<vector<int>> &dp){
	if(ind == n) return 0;
	if(dp[ind][prev_ind+1] != -1) return dp[ind][prev_ind+1];
	
	int len = 0 + f(ind+1,prev_ind,arr,n,dp); //not take case
	if(prev_ind == -1 || arr[ind] > arr[prev_ind]){ //take case
		len = max(len, 1 + f(ind+1,ind,arr,n,dp));
	}
	return dp[ind][prev_ind+1] = len;
}

int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
	vector<vector<int>> dp(n,vector<int>(n+1,-1)); //trying to create 10^5 * 10^5  = 10^10 array constrainst give runtime error

	return f(0,-1,arr,n,dp);
}



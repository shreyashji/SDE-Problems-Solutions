



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
//coordinate change in memoization -1->0,0->1,1->2,2->3
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


//tabulation for  Longest Increasing Subsequence not optimized
int longestIncreasingSubsequence(int arr[], int n)
{
    //1. We are declaring dp[n][n+1]=0, so we dont need to wite specifically for base case
	vector<vector<int>> dp(n+1,vector<int>(n+1,0));
	for(int ind = n-1 ; ind >= 0; ind-- ){ //2 .chnanging parameter in opposite direction ind & prev_ind
	//defination of prev_ind is previous index, prev_ind cannot be n-1 always no, a prev_ind  start from ind-1 
	//it cannot be beyond index or index itself
		for(int prev_ind = ind -1; prev_ind>=-1 ; prev_ind--){ // 3 .copy the recurrence & make sure follow the cordinate shift
		//
				int len = 0 + dp[ind+1][prev_ind+1]; //not take case
				if(prev_ind == -1 || arr[ind] > arr[prev_ind]){ //take case
					len = max(len, 1 + dp[ind+1][ind+1]);
				}
				dp[ind][prev_ind+1] = len;
		}
	}
	return dp[0][-1+1];
}

//space optimization technique
//ind+1 means sppace optimization
//time = O(N^2)
//space = O(N) * 2
int longestIncreasingSubsequence(int arr[], int n)
{
    //1. We are declaring dp[n][n+1]=0, so we dont need to wite specifically for base case
	vector<int> next_row(n+1,0),curr(n+1,0); //inorder to compute index we are just requiring next row dp[ind+1]
	for(int ind = n-1 ; ind >= 0; ind-- ){ //2 .chnanging parameter in opposite direction ind & prev_ind
	//defination of prev_ind is previous index, prev_ind cannot be n-1 always no, a prev_ind  start from ind-1 
	//it cannot be beyond index or index itself
		for(int prev_ind = ind -1; prev_ind>=-1 ; prev_ind--){ // 3 .copy the recurrence
				int len = 0 + next_row[prev_ind+1]; //not take case
				if(prev_ind == -1 || arr[ind] > arr[prev_ind]){ //take case
					len = max(len, 1 + next_row[ind+1]);
				}
				curr[prev_ind+1] = len;
			}
		next_row = curr;
	}
	return next_row[-1+1];
}


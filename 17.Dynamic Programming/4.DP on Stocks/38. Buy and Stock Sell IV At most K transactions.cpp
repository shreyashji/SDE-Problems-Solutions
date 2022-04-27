
// recursion
int f(int ind, int transNo,vector<int> &prices, int n, int k){
	if(ind==n || transNo==2*k) return 0; //atmost 2 
	if(transNo%2 == 0) /*buy*/ {
		return max(-prices[ind] + f(ind+1,transNo+1,prices,n,k),
		/*dont buy take 0 move to next*/0 + f(ind+1,transNo,prices,n,k));
	}
	return max(prices[ind] + f(ind+1,transNo+1,prices,n,k),
			0 + f(ind+1,transNo,prices,n,k));
}


int maximumProfit(vector<int> &prices, int n, int k)
{
	return f(0,0,prices,n,k);
}

//memoized
#include<bits/stdc++.h>
int f(int ind, int transNo,vector<int> &prices, int n, int k,vector<vector<int>> &dp){
	if(ind==n || transNo==2*k) return 0; //atmost 2 
	if(dp[ind][transNo] != -1) return dp[ind][transNo];
	if(transNo%2 == 0) /*buy*/ {
		return dp[ind][transNo] = max(-prices[ind] + f(ind+1,transNo+1,prices,n,k,dp),
		/*dont buy take 0 move to next*/0 + f(ind+1,transNo,prices,n,k,dp));
	}
	return dp[ind][transNo] = max(prices[ind] + f(ind+1,transNo+1,prices,n,k,dp),
			0 + f(ind+1,transNo,prices,n,k,dp));
}

int maximumProfit(vector<int> &prices, int n, int k)
{
	vector<vector<int>> dp(n,vector<int>(2*k,-1));
	return f(0,0,prices,n,k,dp);
}

//tabualtion
#include<bits/stdc++.h>
int maximumProfit(vector<int> &prices, int n, int k)
{
	vector<vector<int>> dp(n+1,vector<int>(2*k+1,0));
	for(int ind= n-1; ind>=0 ;ind--){
		for(int transNo = 2*k-1; transNo>=0; transNo--){
			if(transNo%2 == 0) /*buy*/ {
				dp[ind][transNo] = max(-prices[ind] + dp[ind+1][transNo+1],
				/*dont buy take 0 move to next*/0 + dp[ind+1][transNo]);
			}
			else dp[ind][transNo] = max(prices[ind] + dp[ind+1][transNo+1],
					0 + dp[ind+1][transNo]);
			
		}
	}
	return dp[0][0];
}


//space optimization
//time = N*2k
//space = 2k
//will work on cases like if array is size of 3 and k is 100 
//in base case we are saying stop whenever it reaches n
#include<bits/stdc++.h>
int maximumProfit(vector<int> &prices, int n, int k)
{
	vector<int>after (2*k+1,0);
	vector<int>curr(2*k+1,0);
	for(int ind= n-1; ind>=0 ;ind--){
		for(int transNo = 2*k-1; transNo>=0; transNo--){
			if(transNo%2 == 0) /*buy*/ {
				curr[transNo] = max(-prices[ind] + after[transNo+1],
				/*dont buy take 0 move to next*/0 + after[transNo]);
			}
			else curr[transNo] = max(prices[ind] + after[transNo+1],
					0 + after[transNo]);
			
		}
		after =curr;
	}
	return after[0];
}


//this is copy pasted solution of previous problem
//space optimized
//time = O(N*2*3) 
//space = constant
int maximumProfit(vector<int> &prices, int n, int k)
{
	vector<vector<int>> after(2,vector<int> (k+1,0));
	vector<vector<int>> curr(2,vector<int> (k+1,0)); //6 size array consatnant array
	for(int ind = n-1 ;ind>=0 ; ind--){ //starting from opposite
		for(int buy=0; buy<=1; buy++){
			for(int cap = 1; cap<=k; cap++){
				if(buy == 1){
					curr[buy][cap] = max(-prices[ind] + 
													after[0][cap], 
													0 + after[1][cap]);
					}
					//sell if buy not happen
					else{
						curr[buy][cap] = max(prices[ind] + 
												   after[1][cap-1],
												   0 + after[0][cap]);
					}
			}
			after = curr;
		}
	}
    return after[1][k];
}
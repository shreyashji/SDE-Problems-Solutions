

//recurrence
//time = exponential
//space = O(N) aux stack space
int f(int ind,int buy,int cap,vector<int>& prices,int n){
        if(ind == n || cap == 0) return 0;        
        if(buy == 1){
            return max(-prices[ind] + f(ind+1,0,cap,prices,n) , 
					   0 + f(ind+1,1,cap,prices,n));
        }
        //sell if buy not happen
		return max(prices[ind] + f(ind+1,1,cap-1,prices,n) ,0 + f(ind+1,0,cap,prices,n));
 }

int maxProfit(vector<int>& prices, int n)
{
    return f(0,1,2,prices,n);
}

//memoized
//time = O(N*2*3) 
//space = O(N*2*3) +O(N) aux stack space
#include<bits/stdc++.h>
int f(int ind,int buy,int cap,vector<int>& prices,int n,vector<vector<vector<int>>> &dp){
        if(ind == n || cap == 0) return 0;
		if (dp[ind][buy][cap] != -1) return dp[ind][buy][cap];
        if(buy == 1){
            return dp[ind][buy][cap] = max(-prices[ind] + f(ind+1,0,cap,prices,n,dp) , 
					   0 + f(ind+1,1,cap,prices,n,dp));
        }
        //sell if buy not happen
		return dp[ind][buy][cap] = max(prices[ind] + f(ind+1,1,cap-1,prices,n,dp) ,0 + f(ind+1,0,cap,prices,n,dp));
 }

int maxProfit(vector<int>& prices, int n)
{
	vector<vector<vector<int>>> dp(n,
								vector<vector<int>> (2,vector<int> (3,-1)) );
    return f(0,1,2,prices,n,dp);
}

//tabulation
//time = O(N*2*3) 
//space = O(N*2*3) 
int maxProfit(vector<int>& prices, int n)
{
	vector<vector<vector<int>>> dp(n+1,
								vector<vector<int>> (2,vector<int> (3,0)) );
	for(int ind = n-1 ;ind>=0 ; ind--){ //starting from opposite
		for(int buy=0; buy<=1; buy++){
			for(int cap = 1; cap<=2; cap++){
				if(buy == 1){
					dp[ind][buy][cap] = max(-prices[ind] + 
													dp[ind+1][0][cap], 
													0 + dp[ind+1][1][cap]);
					}
					//sell if buy not happen
					else{
						dp[ind][buy][cap] = max(prices[ind] + 
												   dp[ind+1][1][cap-1],
												   0 + dp[ind+1][0][cap]);
					}
			}
		}
	}
    return dp[0][1][2];
}

//space optimized
//time = O(N*2*3) 
//space = constant
int maxProfit(vector<int>& prices, int n)
{
	vector<vector<int>> after(2,vector<int> (3,0));
	vector<vector<int>> curr(2,vector<int> (3,0)); //6 size array consatnant array
	for(int ind = n-1 ;ind>=0 ; ind--){ //starting from opposite
		for(int buy=0; buy<=1; buy++){
			for(int cap = 1; cap<=2; cap++){
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
    return after[1][2];
}
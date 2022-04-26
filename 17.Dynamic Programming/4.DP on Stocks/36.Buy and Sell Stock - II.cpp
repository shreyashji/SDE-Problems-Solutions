
//recurrence
//time =  O(2^N)
//space = O(N)
#include<bits/stdc++.h>
long f(int ind, int buy,long *values,int n){
	//0 means cannot buy,1 means can buy
	if(ind == n) return 0;//no more profit can be made once array is over
	long profit = 0;	
	if(buy){
		profit = max(-values[ind] - f(ind+1,0,values,n)
					, 0+ f(ind+1,1,values,n));
	}
	else{
		profit = max(values[ind]+ f(ind+1,1,values,n)
					,0+ f(ind+1,0,values,n)); 
	}
	return profit;
}
long getMaximumProfit(long *values, int n)
{
    return f(0,1,values,n,dp);
}


//memoization
//time = O(N*2)
//space = O(N*2) + O(N)stack space
#include<bits/stdc++.h>
long f(int ind, int buy,long *values,int n,vector<vector<long>> &dp){
	//0 means cannot buy,1 means can buy
	if(ind == n) return 0;//no more profit can be made once array is over
	if(dp[ind][buy] != -1) return dp[ind][buy];
	long profit = 0;	
	if(buy){
		profit = max(-values[ind] - f(ind+1,0,values,n,dp)
					, 0+ f(ind+1,1,values,n,dp));
	}
	else{
		profit = max(values[ind]+ f(ind+1,1,values,n,dp)
					,0+ f(ind+1,0,values,n,dp)); 
	}
	return dp[ind][buy] = profit;
}
long getMaximumProfit(long *values, int n)
{
	vector<vector<long>> dp(n,vector<long>(2,-1));
    return f(0,1,values,n,dp);
}

//tabulation
//time = O(N*2)
//space = O(N*2) 
long getMaximumProfit(long *values, int n)
{
	vector<vector<long>> dp(n+1,vector<long>(2,0));
	dp[n][0] = dp[n][1] =0; //coz ind == n buy can be anything
	for(int ind= n-1 ; ind>=0 ; ind--){
		for(int buy=0 ; buy<=1; buy++){
			long profit = 0;	
			if(buy){
				profit = max(-values[ind] - dp[ind+1][0]
							, 0+ dp[ind+1][1]);
			}
			else{
				profit = max(values[ind]+ dp[ind+1][1]
							,0+ dp[ind+1][0]); 
			}
			dp[ind][buy] = profit;
		}
	}
	return dp[0][1];
}


//most optimized can do,there is also 4 variable solution work like this ,no change in space,time complexity
long getMaximumProfit(long *values, int n)
{
	vector<long> ahead(2,0),curr(2,0);
	ahead[0] = ahead[1] =0; //coz ind == n buy can be anything
	for(long ind= n-1 ; ind>=0 ; ind--){
		for(long buy=0 ; buy<=1; buy++){
			long profit = 0;	
			if(buy){
				profit = max(-values[ind] - ahead[0]
							, 0+ ahead[1]);
			}
			else{
				profit = max(values[ind]+ ahead[1]
							,0+ ahead[0]); 
			}
			curr[buy] = profit;
		}
		ahead = curr;
	}
	return ahead[1];
}
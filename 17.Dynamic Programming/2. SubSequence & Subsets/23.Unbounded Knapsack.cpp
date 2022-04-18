//infinite supply
//recursion
//time = exponential coz unbounded not 2^n
//space = O(bag weight) or(W)
int f(int ind, int W, vector<int> &val, vector<int> &wt){
	if(ind==0) {
		return ((int)(W/wt[0])) * val[0] ;
	}
	
	int nottake = 0 + f(ind-1,W,val,wt);
	int take = 0;
	if(wt[ind] <=W){
		take = val[ind] + f(ind,W -  wt[ind],val,wt);
	}
	return max(nottake,take);
}

int unboundedKnapsack(int n, int w, vector<int> &val, vector<int> &wt)
{
	return f(n-1,w,val,wt);
}

//memoization
//time = O(N*W)
//space = O(bag weight) or(W) +O(W)  auxilary
int f(int ind, int W, vector<int> &val, vector<int> &wt,vector<vector<int>> &dp){
	if(ind==0) {
		return ((int)(W/wt[0])) * val[0] ;
	}
	if(dp[ind][W] != -1) return -1;
	int nottake = 0 + f(ind-1,W,val,wt,dp);
	int take = 0;
	if(wt[ind] <=W){
		take = val[ind] + f(ind,W -  wt[ind],val,wt,dp);
	}
	return dp[ind][W] = max(nottake,take);
}

int unboundedKnapsack(int n, int w, vector<int> &val, vector<int> &wt)
{
	vector<vector<int>> dp(n,vector<int> (w+1,-1));
	return f(n-1,w,val,wt,dp);
}

//tabulation

int unboundedKnapsack(int n, int w, vector<int> &val, vector<int> &wt)
{
    // Write Your Code Here.
	vector<vector<int>> dp(n,vector<int> (w+1,0));
	for(int W=0 ; W<=w ; W++){
		dp[0][W] = ((int)(W/wt[0])) * val[0] ;
	}
	for(int ind=1; ind<n ; ind++){
		for(int W=0 ; W<=w ; W++){
			int nottake = 0 + dp[ind-1][W];
			int take = 0;
			if(wt[ind] <=W){
				take = val[ind] + dp[ind][W -  wt[ind]];
			}
			dp[ind][W] = max(nottake,take);
		}
	}
	return dp[n-1][w];
}

//space optimized 2 array
int unboundedKnapsack(int n, int w, vector<int> &val, vector<int> &wt)
{
    // Write Your Code Here.
	//vector<vector<int>> dp(n,vector<int> (w+1,0));
	vector<int> prev(w+1,0),curr(w+1,0);
	for(int W=0 ; W<=w ; W++){
		prev[W] = ((int)(W/wt[0])) * val[0] ;
	}
	for(int ind=1; ind<n ; ind++){
		for(int W=0 ; W<=w ; W++){
			int nottake = 0 + prev[W];
			int take = 0;
			if(wt[ind] <=W){
				take = val[ind] + curr[W -  wt[ind]];
			}
			curr[W] = max(nottake,take);
		}
		prev=curr;
	}
	return prev[w];
}

//space optimized to 1 array
int unboundedKnapsack(int n, int w, vector<int> &val, vector<int> &wt)
{
	//vector<vector<int>> dp(n,vector<int> (w+1,0));
	vector<int> prev(w+1,0)
	for(int W=0 ; W<=w ; W++){
		prev[W] = ((int)(W/wt[0])) * val[0] ;
	}
	for(int ind=1; ind<n ; ind++){
		for(int W=0 ; W<=w ; W++){
			int nottake = 0 + prev[W];
			int take = 0;
			if(wt[ind] <=W){
				take = val[ind] + prev[W -  wt[ind]];
			}
			prev[W] = max(nottake,take);
		}
	}
	return prev[w];
}

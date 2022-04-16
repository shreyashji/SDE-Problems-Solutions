//recursion

int f(int ind,int W,vector<int> &wt,vector<int> val){
	if(ind==0) {
		if(wt[0]<=W) return val[0];
		return 0;
	}
	int nottake = 0 + f(ind-1,W,wt,val);
	int take = INT_MIN;
	if(wt[ind] <=W){
		take = val[ind] + f(ind-1,W -  wt[ind],wt,val);
	}
	return max(nottake,take);
	
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	return f(n-1,maxWeight,weight,value);
}

//memoization
int f(int ind,int W,vector<int> &wt,vector<int> val,vector<vector<int>> &dp){
	if(ind==0) {
		if(wt[0]<=W) return val[0];
		return 0;
	}
	if(dp[ind][W] != -1) return dp[ind][W];
	int nottake = 0 + f(ind-1,W,wt,val,dp);
	int take = INT_MIN;
	if(wt[ind] <=W){
		take = val[ind] + f(ind-1,W -  wt[ind],wt,val,dp);
	}
	return dp[ind][W] = max(nottake,take);
	
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>> dp(n,vector<int> (maxWeight+1,-1));
	return f(n-1,maxWeight,weight,value,dp);
}

//tabulation
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>> dp(n,vector<int> (maxWeight+1,0));
	for(int W = weight[0]; W<=maxWeight ; W++) dp[0][W]= value[0];
	for(int ind=1; ind<n ; ind++){
		for(int W=0; W<=maxWeight;W++){
			//COPY RECURRENCE
			int nottake = 0 + dp[ind-1][W];
			int take = INT_MIN;
			if(weight[ind] <=W){
				take = value[ind] + dp[ind-1][W - weight[ind]];
			}
			dp[ind][W] = max(nottake,take);
		}
	}
	return dp[n-1][maxWeight];
}

//space optimized
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<int> prev(maxWeight+1,0),curr(maxWeight+1,0);
	for(int W = weight[0]; W<=maxWeight ; W++) prev[W]= value[0];
	for(int ind=1; ind<n ; ind++){
		for(int W=0; W<=maxWeight;W++){
			//COPY RECURRENCE
			int nottake = 0 + prev[W];
			int take = INT_MIN;
			if(weight[ind] <=W){
				take = value[ind] + prev[W - weight[ind]];
			}
			curr[W] = max(nottake,take);
		}
		prev=curr;
	}
	return prev[maxWeight];
}
//we can also do this
/*
[W - weight[ind]] means no need of right elements ,right elements of previous not required any further
will use same previous row to fill it up

*/
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<int> prev(maxWeight+1,0),curr(maxWeight+1,0);
	for(int W = weight[0]; W<=maxWeight ; W++) prev[W]= value[0];
	for(int ind=1; ind<n ; ind++){
		for(int W=maxWeight; W>=0;W--){ //from right to left
			//COPY RECURRENCE
			int nottake = 0 + prev[W];
			int take = INT_MIN;
			if(weight[ind] <=W){
				take = value[ind] + prev[W - weight[ind]];
			}
			curr[W] = max(nottake,take);
		}
		prev=curr;
	}
	return prev[maxWeight];
} 
//single array optimization,not two rows
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<int> prev(maxWeight+1,0);
	for(int W = weight[0]; W<=maxWeight ; W++) prev[W]= value[0];
	for(int ind=1; ind<n ; ind++){
		for(int W=maxWeight; W>=0;W--){
			//COPY RECURRENCE
			int nottake = 0 + prev[W];
			int take = INT_MIN;
			if(weight[ind] <=W){
				take = value[ind] + prev[W - weight[ind]];
			}
			prev[W] = max(nottake,take);
		} 
	}
	return prev[maxWeight];
}
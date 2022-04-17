
//recurrence
//time = exponential
//space = exponential
int f(int ind,int T,vector<int> &num){
	if(ind == 0 ){
		if(T%num[0]==0) return T/num[0];
		return 1e9;
	}
	int nottake=  0+ f(ind-1,T, num);
	int take=INT_MAX;
	if(num[ind] <= T) take = 1 + f(ind,T-num[ind],num);
	
	return min(take,nottake);
}
int minimumElements(vector<int> &num, int Target)
{
	int n=num.size();
	int ans = f(n-1,Target,num);
	if(ans >= 1e9) return -1;
	return ans;
    // Write your code here.
}

//mmemoization
//time = O(N*T)
//space = O(N*T)dp array + O(N) auxilary sapce
int f(int ind,int T,vector<int> &num,vector<vector<int>> &dp){
	if(ind == 0 ){
		if(T%num[0]==0) return T/num[0];
		return 1e9;
	}
	if(dp[ind][T] != -1) return dp[ind][T];
	int nottake=  0+ f(ind-1,T, num,dp);
	int take=INT_MAX;
	if(num[ind] <= T) take = 1 + f(ind,T-num[ind],num,dp);
	
	return dp[ind][T] = min(take,nottake);
}
int minimumElements(vector<int> &num, int Target)
{
	int n = num.size();
	vector<vector<int>> dp(n,vector<int>(Target+1,-1));
	int ans = f(n-1,Target,num,dp);
	if(ans >= 1e9) return -1;
	return ans;
}

//tabulation
//time = O(N*T)
//space = O(N*T)dp array 
int minimumElements(vector<int> &num, int Target)
{
	int n = num.size();
	vector<vector<int>> dp(n,vector<int>(Target+1,0));
	for(int T=0; T<=Target ; T++){
		if(T%num[0]==0) dp[0][T] = T/num[0];
		else dp[0][T] = 1e9;
	}
	for(int ind=1; ind<n ; ind++){
		for(int T=0 ;T<=Target ; T++){
			int nottake=  0+ dp[ind-1][T];
			int take=INT_MAX;
			if(num[ind] <= T) take = 1 + dp[ind][T-num[ind]];

			dp[ind][T] = min(take,nottake);
		}
	}
	
	int ans = dp[n-1][Target];
	if(ans >= 1e9) return -1;
	return ans;
}

//space optimized
//time = O(N*T)
//space = O(T)
int minimumElements(vector<int> &num, int Target)
{
	int n = num.size();
	vector<int> prev(Target+1,0),curr(Target+1,0);
	for(int T=0; T<=Target ; T++){
		if(T%num[0]==0) prev[T] = T/num[0];
		else prev[T] = 1e9;
	}
	for(int ind=1; ind<n ; ind++){
		for(int T=0 ;T<=Target ; T++){
			int nottake=  0 + prev[T];
			int take=INT_MAX;
			if(num[ind] <= T){
				take = 1 + curr[T-num[ind]];
			}
			curr[T] = min(take,nottake);
		}
		prev=curr;
	}
	
	int ans = prev[Target];
	if(ans >= 1e9) return -1;
	return ans;
}
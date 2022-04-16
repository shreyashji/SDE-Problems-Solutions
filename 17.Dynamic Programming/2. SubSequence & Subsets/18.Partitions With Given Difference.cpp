
//memoization
int mod = (int)(1e9+7);
int f(int ind, int sum,vector<int> &num,vector<vector<int>> &dp){
	if(ind==0) {
		if(sum==0 && num[0]==0) return 2; //two options tkae 0 or not take 0,2 possible wasy
		if(sum ==0 || sum == num[0]) return 1;
		return 0;
	}
	if(dp[ind][sum] != -1) return dp[ind][sum];
	
	int nottake = f(ind-1,sum,num,dp);
	int take=0;
	if(num[ind]<=sum) take = f(ind-1,sum-num[ind],num,dp);
	
	return dp[ind][sum] = (take+nottake)%mod;
}

int findWays(vector<int> &num, int tar)
{
	int n = num.size();
	vector<vector<int>> dp(n,vector<int>(tar+1,-1));
	return f(n-1,tar,num,dp); 
}
int countPartitions(int n, int d, vector<int> &arr) {
    int totalsum=0;
	for(auto &it:arr) totalsum += it;
	if(totalsum-d <0 || (totalsum-d)%2) return false; //has to be greater than 0 & should be even
	return findWays(arr,(totalsum-d)/2);
}


//tabulation
int mod = (int)(1e9+7);
int findWays(vector<int> &num, int tar)
{
	int n = num.size();
	vector<vector<int>> dp(n,vector<int>(tar+1,0));
	if(num[0]==0) dp[0][0] = 2;
		else dp[0][0] =1;
	//mum[0] =0 fail
	if(num[0] !=0 & num[0] <= tar) dp[0][num[0]] =1; //base case
	//chnaging parameter index & dum
	for(int ind=1; ind<n ; ind++) {
		for(int sum=0; sum<=tar ; sum++){
			//copy paste recursion
			int nottake = dp[ind-1][sum];
			int take=0;
			if(num[ind]<=sum) take = dp[ind-1][sum-num[ind]];

			dp[ind][sum] = (take+nottake)%mod;
		}
	}
	return dp[n-1][tar]; 
}
int countPartitions(int n, int d, vector<int> &arr) {
    int totalsum=0;
	for(auto &it:arr) totalsum += it;
	if(totalsum-d <0 || (totalsum-d)%2) return false; //has to be greater than 0 & should be even
	return findWays(arr,(totalsum-d)/2);
}

//space optimization

int mod = (int)(1e9+7);
int findWays(vector<int> &num, int tar)
{
	int n = num.size();
	vector<int> prev(tar+1,0), curr(tar+1);
	if(num[0]==0) prev[0] = 2;
		else prev[0] =1;
	//mum[0] =0 fail
	if(num[0] !=0 & num[0] <= tar) prev[num[0]] =1; //base case
	//chnaging parameter index & dum
	for(int ind=1; ind<n ; ind++) {
		for(int sum=0; sum<=tar ; sum++){
			//copy paste recursion
			int nottake = prev[sum];
			int take=0;
			if(num[ind]<=sum) take = prev[sum-num[ind]];

			curr[sum] = (take+nottake)%mod;
		}
		prev =curr;
	}
	return prev[tar]; 
}
int countPartitions(int n, int d, vector<int> &arr) {
    int totalsum=0;
	for(auto &it:arr) totalsum += it;
	if(totalsum-d <0 || (totalsum-d)%2) return false; //has to be greater than 0 & should be even
	return findWays(arr,(totalsum-d)/2);
}





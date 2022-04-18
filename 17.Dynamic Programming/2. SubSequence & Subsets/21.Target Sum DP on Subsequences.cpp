//tabulation
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

			dp[ind][sum] = (take+nottake);
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

int targetSum(int n, int target, vector<int>& arr) {
    // Write your code here.
	return countPartitions(n,target,arr);
}

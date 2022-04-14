//https://www.codingninjas.com/codestudio/problems/subset-sum-equal-to-k_1550954?leftPanelTab=0

//recursion
//time =O(2^N) for every elmnt in arry we have couple ofconsideration
//space = O(N) auxilary space
bool f(int ind, int target,vector<int> &arr){
	if (target==0) return true;
	if (ind==0) return (arr[0]==target);
	
	bool nottake = f(ind-1,target,arr);
	bool take =false;
	if(arr[ind] <= target) take = f(ind -1,target-arr[ind],arr); 
	return take | nottake;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
	return f(n-1,k,arr);
}

//memoization
//time = O(N*Target)
//space = O(N*Target)dp array + O(N)auxilary space
bool f(int ind, int target,vector<int> &arr,vector<vector<int>> &dp){
	if (target==0) return true;
	if (ind==0) return (arr[0]==target);
	if(dp[ind][target] != -1) return dp[ind][target];
		
	bool nottake = f(ind-1,target,arr,dp );
	bool take =false;
	if(arr[ind] <= target) take = f(ind -1,target-arr[ind],arr,dp); 
	return dp[ind][target]= take | nottake;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n ,vector<int>(k+1,-1));
	return f(n-1,k,arr,dp);
}

//tabulation
//time = O(N*Target)
//space = O(N*Target) no auxilary space
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n ,vector<bool>(k+1,0));
	for(int i=0 ; i<n ; i++) dp[i][0] = true; //base case
	if(arr[0] <= k) dp[0][arr[0]] = true; //base case
	
	for(int ind =1; ind<n ; ind++){
		for(int target=1; target<=k; target++){
			bool nottake = dp[ind-1][target];
			bool take =false;
			if(arr[ind] <= target) take = dp[ind -1][target-arr[ind]]; 
			dp[ind][target]= take | nottake;
		}
	}
	return dp[n-1][k];
}

//space optimization : if ind-1 its possible coz 1st time we always write indx 0
//time = O(N*Target)
//space = O(Target or K) 
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<bool> prev(k+1,0),curr(k+1,0);
	prev[0]=curr[0] =true;
	prev[arr[0]] = true; //base case
	
	for(int ind =1; ind<n ; ind++){
		for(int target=1; target<=k; target++){
			bool nottake = prev[target];
			bool take =false;
			if(arr[ind] <= target) take = prev[target-arr[ind]]; 
			curr[target]= take | nottake;
		}
		prev = curr;
	}
	return prev[k];
}
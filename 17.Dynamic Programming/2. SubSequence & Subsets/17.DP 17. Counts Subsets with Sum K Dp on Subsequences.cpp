
//recurrence 
//time = O(2^n)
//space= O(N)
int f(int ind, int sum,vector<int> &num){
	if(sum==0) return 1;
	if(ind==0) return num[0] == sum;
	
	int nottake = f(ind-1,sum,num);
	int take=0;
	if(num[ind]<=sum) take = f(ind-1,sum-num[ind],num);
	
	return take+nottake;
}

int findWays(vector<int> &num, int tar)
{
    int n = num.size();
	return f(n-1,tar,num); 
}


//memoization
//time = O(N*sum)
//space= O(N*sum) dp matrix + O(N) for auxilary space
int f(int ind, int sum,vector<int> &num,vector<vector<int>> &dp){
	if(sum==0) return 1;
	if(ind==0) return num[0] == sum;
	if(dp[ind][sum] != -1) return dp[ind][sum];
	
	int nottake = f(ind-1,sum,num,dp);
	int take=0;
	if(num[ind]<=sum) take = f(ind-1,sum-num[ind],num,dp);
	
	return dp[ind][sum] = take+nottake;
}

int findWays(vector<int> &num, int tar)
{
	int n = num.size();
	vector<vector<int>> dp(n,vector<int>(tar+1,-1));
	return f(n-1,tar,num,dp); 
}

//what if there are negative integers,which data structure to use
//If there are non-negative integers and sum can also be non-negative then we can use map data structure


//tabulation ,to remove auxilary space
//time = O(N*sum)
//space= O(N*sum) dp matrix
int findWays(vector<int> &num, int tar)
{
	int n = num.size();
	vector<vector<int>> dp(n,vector<int>(tar+1,0));
	for(int i=0; i<n ; i++) dp[i][0]=1; //base case
	if(num[0] <= tar) dp[0][num[0]] =1; //base case
	//chnaging parameter index & dum
	for(int ind=1; ind<n ; ind++) {
		for(int sum=0; sum<=tar ; sum++){
			//copy paste recursion
			int nottake = dp[ind-1][sum];
			int take=0;
			if(num[ind]<=sum) take = dp[ind-1][sum-num[ind]];

			dp[ind][sum] = take+nottake;
		}
	}
	return dp[n-1][tar]; 
}


//space optimization ,dp[ind-1] replace this by prev
//using 1 d array
//
int findWays(vector<int> &num, int tar)
{
	int n = num.size();
	vector<int> prev(tar+1,0), curr(tar+1);
	prev[0]=curr[0]=1; //base case
	if(num[0] <= tar) prev[num[0]] =1; //base case
	//chnaging parameter index & dum
	for(int ind=1; ind<n ; ind++) {
		for(int sum=0; sum<=tar ; sum++){
			//copy paste recursion
			int nottake = prev[sum];
			int take=0;
			if(num[ind]<=sum) take = prev[sum-num[ind]];

			curr[sum] = take+nottake;
		}
		prev = curr;
	}
	return prev[tar]; 
}



//what if array is [0,0,1] and sum=1 ,so there should be 4 subsets ideally

int f(int ind, int sum,vector<int> &num){
	
	if(ind==0) {
		if(sum==0 && num[0]==0) return 2; //two options tkae 0 or not take 0,2 possible wasy
		if(sum ==0 || sum == num[0]) return 1;
		return 0;
	}
	
	int nottake = f(ind-1,sum,num);
	int take=0;
	if(num[ind]<=sum) take = f(ind-1,sum-num[ind],num);
	
	return take+nottake;
}

int findWays(vector<int> &num, int tar)
{
    int n = num.size();
	return f(n-1,tar,num); 
}



//recurrence
//tc = exponential
//space= O()
int f(int i,int j, vector<int> &arr){
	if(i==j) return 0;
	int mini = 1e9;
	for(int k=i; k<j ;k++){
		int steps = arr[i-1] * arr[k] * arr[j]  + f(i,k,arr) +f(k+1,j,arr);
		if(steps < mini) mini = steps;
	}
	return mini; 
}
int matrixMultiplication(vector<int> &arr, int N)
{
    return f(1,N-1,arr);
}


//memoization
//time = n*n states near about = O(N*N) * N~~ O(N^3)
//sapce = O(N^2) + O(n) stack space
int f(int i,int j, vector<int> &arr,vector<vector<int>> &dp){
	if(i==j) return 0;
	if(dp[i][j] !=-1 ) return dp[i][j];
	int mini = 1e9;
	for(int k=i; k<j ;k++){
		int steps = arr[i-1] * arr[k] * arr[j]  + f(i,k,arr,dp) +f(k+1,j,arr,dp);
		if(steps < mini) mini = steps;
	}
	return dp[i][j] = mini; 
}
int matrixMultiplication(vector<int> &arr, int N)
{
	vector<vector<int>> dp(N,vector<int>(N,-1));
    return f(1,N-1,arr,dp);
}
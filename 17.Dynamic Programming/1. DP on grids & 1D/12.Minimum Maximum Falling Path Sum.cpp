//https://www.codingninjas.com/codestudio/problems/maximum-path-sum-in-the-matrix_797998?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1
//recurrence
int f(int i,int j , vector<vector<int>> &matrix){
	if(j<0 || j>=matrix[0].size()) return -1e8;
    if(i==0) return matrix[0][j];
	
	int up = matrix[i][j] + f(i-1,j,matrix);
    int leftDiagonal = matrix[i][j] + f(i-1,j-1,matrix);
    int rightDiagonal = matrix[i][j] + f(i-1,j+1,matrix);
	
	return max(up,max(leftDiagonal,rightDiagonal));
    
}
int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
	int n = matrix.size();
    int m = matrix[0].size();
	int maxi = -1e8;
	  for(int j=0; j<m;j++){
        maxi = max(maxi,f(n-1,j,matrix));
	}
    return maxi;
}



//memoization  n-1 to 0
//time = O(N*M) for states
//space=  O(N*M) matrix +  O(N) for recr stack space
int f(int i, int j, vector<vector<int>> &matrix,vector<vector<int>> &dp){
	// Base Conditions
    if(j<0 || j>=matrix[0].size()) return -1e8;
    if(i==0) return matrix[0][j];
    
    if(dp[i][j]!=-1) return dp[i][j];
    
    int up = matrix[i][j] + f(i-1,j,matrix,dp);
    int leftDiagonal = matrix[i][j] + f(i-1,j-1,matrix,dp);
    int rightDiagonal = matrix[i][j] + f(i-1,j+1,matrix,dp);
    
    return dp[i][j]= max(up,max(leftDiagonal,rightDiagonal));
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
	int n = matrix.size();
    int m = matrix[0].size();
	vector<vector<int>> dp(n,vector<int>(m,-1));
    int maxi = -1e8;
	  for(int j=0; j<m;j++){
        maxi = max(maxi,f(n-1,j,matrix,dp));
	}
    return maxi;
}

//tabulation bottom  up  0  to n-1
// 1. int dp[n][m] ; declare dp
//2 . base case 
//3 . observe the states  i,j & convert to loops
// i to n-1
// for every i j=0 to m-1 
//just copy paste the recurrence
//wrote out of bound cases for ld,rd
//time = O(N*M) for states + O(m)
//space=  O(N*M) matrix ,no stack space

int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
	int n = matrix.size();
    int m = matrix[0].size();
	vector<vector<int>> dp(n,vector<int>(m,0)); //1.dp initi
	
	for(int j=0; j<m; j++) dp[0][j] = matrix[0][j]; //base case 
	for(int i=1; i<n ; i++){
		 for(int j=0; j<m;j++){
			int up = matrix[i][j] + dp[i-1][j];
			 
    		int leftDiagonal = matrix[i][j];
			if(j-1>=0) leftDiagonal += dp[i-1][j-1];
				else leftDiagonal += -1e8;
			 
    		int rightDiagonal = matrix[i][j];
			if(j+1 < m)	rightDiagonal += dp[i-1][j+1];
			 	else rightDiagonal += -1e8;
			 
			dp[i][j] = max(up,max(leftDiagonal,rightDiagonal));
		 }
	}
	
    int maxi = -1e8; //1st coln   
	  for(int j=0; j<m;j++){  //start dfrom next coln till the end ///O(M)
        maxi = max(maxi,dp[n-1][j]); //last row,jth col
	}
    return maxi;
}
//space optimized
//time = O(N*M) for states + O(m)
//space=  O(N)
int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
	int n = matrix.size();
    int m = matrix[0].size();
	vector<int> prev(m,0),curr(m,0);
	
	for(int j=0; j<m; j++) prev[j] = matrix[0][j];
	for(int i=1; i<n ; i++){
		 for(int j=0; j<m;j++){
			int up = matrix[i][j] + prev[j];
			 
    		int leftDiagonal = matrix[i][j];
			if(j-1>=0) leftDiagonal += prev[j-1];
				else leftDiagonal += -1e8;
			 
    		int rightDiagonal = matrix[i][j];
			if(j+1 < m)	rightDiagonal += prev[j+1];
			 	else rightDiagonal += -1e8;
			 
			curr[j] = max(up,max(leftDiagonal,rightDiagonal));
		 }
		prev = curr;
	}
	
    int maxi = -1e8;
	  for(int j=0; j<m;j++){
        maxi = max(maxi,prev[j]);
	}
    return maxi;
}
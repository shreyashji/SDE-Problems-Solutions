///https://www.codingninjas.com/codestudio/problems/minimum-path-sum_985349?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

//memoization
int f(int i, int j, vector<vector<int>> &grid,vector<vector<int>>&dp){
	if(i==0 && j == 0)
    	return grid[i][j];
  	if(i<0 || j<0)
		 return 1e9;
	
 	if(dp[i][j]!=-1) return dp[i][j];//memoization same state called return
	
	int up = grid[i][j] + f(i-1,j,grid,dp);
  	int left = grid[i][j] + f(i,j-1,grid,dp);
  
  	return dp[i][j] = min(up,left);
}

int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
	int n = grid.size();
 	int m = grid[0].size();
	vector<vector<int>>dp(n,vector<int>(m,-1));
	return f(n-1,m-1,grid,dp);
}

//tabulation
int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
	int n = grid.size();
 	int m = grid[0].size();
	vector<vector<int>>dp(n,vector<int>(m,-1));
	
	  for(int i=0; i<n ; i++){
        for(int j=0; j<m; j++){
			if(i==0 && j==0) dp[i][j] = grid[i][j];
			 else{
                
                int up = grid[i][j];
                if(i>0) up += dp[i-1][j];
                else up += 1e9;//max so it get neglected
                
                int left = grid[i][j];
                if(j>0) left+=dp[i][j-1];
                else left += 1e9;
                
                dp[i][j] = min(up,left);
			 }
		}
	 }
	return dp[n-1][m-1];
}

//space optimization
int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
	int n = grid.size();
 	int m = grid[0].size();
	vector<vector<int>>dp(n,vector<int>(m,-1));
	vector<int> prev(m,0);
	  for(int i=0; i<n ; i++){ //end at i=n  , i means crnt row previous coln
		  vector<int> curr(m,0);
        for(int j=0; j<m; j++){
			if(i==0 && j==0) curr[j] = grid[i][j];
			 else{
                int up = grid[i][j];
				//requiring previous row j coln
                if(i>0) up += prev[j];
                else up += 1e9;//max so it get neglected
                
                int left = grid[i][j];
				 //current row j-1 coln
                if(j>0) left += curr[j-1];
                else left += 1e9;
                
                curr[j] = min(up,left);
			 }
		}
		 prev = curr;
	 }
	return prev[m-1]; //for i =n who will b previous -> m-1
}
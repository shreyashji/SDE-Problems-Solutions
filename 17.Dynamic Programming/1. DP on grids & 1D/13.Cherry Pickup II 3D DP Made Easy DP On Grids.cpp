
//recursion
//time =  3^N * 3^N ~~exponential
//space = O(N) auxilary space
int f(int i, int j1, int j2, int r, int c,vector<vector<int>> &grid){
	//r= row or n
	//c=  coln or m
	if (j1 < 0 || j2 < 0 || j1 >= c || j2 >= c){ //if crosses left or right boundry return very -ive value
    return -1e9;//int_min + negative will be overflow
	}
	if (i == r - 1) { //reach destination or last row
    if (j1 == j2) //if same cell reached by alice and bob count once
      return grid[i][j1];
    else //if two different positions or cell count both alice and bob
      return grid[i][j1] + grid[i][j2];
	}
	//explore all paths
	int maxi = -1e8;
  	for (int dj1 = -1; dj1 <= 1; dj1++) { //for alice
    	for (int dj2 = -1; dj2 <= 1; dj2++) { //for bob corresponding
      		int value=0;
      		if (j1 == j2) //if same position
        		value = grid[i][j1];
      		else
        		value = grid[i][j1] + grid[i][j2];
			value +=  f(i+1, j1+dj1, j2+dj2, r, c, grid);
      	maxi = max(maxi, value);
    }
  }
  return maxi;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // Write your code here.
	return f(0,0,c-1,r,c,grid);
}

//memoization
//time = O(N*M*M) no. of diff states  * 9 for every state in loop 3*3
//space = O(N*M*M) dp array + O(n) auxilary space
int f(int i, int j1, int j2, int r, int c,vector<vector<int>> &grid, vector<vector<vector<int>>> &dp){
	//r= row or n
	//c=  coln or m
	if (j1 < 0 || j2 < 0 || j1 >= c || j2 >= c){ //if crosses left or right boundry return very -ive value
    return -1e9;//int_min + negative will be overflow
	}
	if (i == r - 1) { //reach destination or last row
    if (j1 == j2) //if same cell reached by alice and bob count once
      return grid[i][j1];
    else //if two different positions or cell count both alice and bob
      return grid[i][j1] + grid[i][j2];
	}
	if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
	//explore all paths
	int maxi = -1e8;
  	for (int dj1 = -1; dj1 <= 1; dj1++) { //for alice
    	for (int dj2 = -1; dj2 <= 1; dj2++) { //for bob corresponding
      		int value=0;
      		if (j1 == j2) //if same position
        		value = grid[i][j1];
      		else
        		value = grid[i][j1] + grid[i][j2];
			value +=  f(i+1, j1+dj1, j2+dj2, r, c, grid,dp);
      	maxi = max(maxi, value);
    }
  }
  return dp[i][j1][j2] = maxi;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // Write your code here.
	//int dp[r][c][c] //memoization
	vector<vector<vector<int>>> dp(r,vector<vector<int>> (c, vector<int> (c, -1))); //3D vector
	return f(0,0,c-1,r,c,grid,dp);
}

//tabulation : remove auxilary space


int maximumChocolates(int n, int m, vector<vector<int>> &grid) {
    // Write your code here.
	//int dp[r][c][c] //memoization
	vector<vector<vector<int>>> dp(n,vector<vector<int>> (m, vector<int> (m, 0))); //3D vector
	for (int j1 = 0; j1 < m; j1++) {
		for (int j2 = 0; j2 < m; j2++) {
			 if (j1 == j2) //same position ,additon of one guy
        		dp[n - 1][j1][j2] = grid[n - 1][j1];
      		else
        		dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
    	}
  	}
	  //Outer Nested Loops for travering DP Array
  	for (int i = n - 2; i >= 0; i--) {
    	for (int j1 = 0; j1 < m; j1++) {
      		for (int j2 = 0; j2 < m; j2++) {
				
				int maxi = -1e8;
				for (int dj1 = -1; dj1 <= +1; dj1++) { //for alice
					for (int dj2 = -1; dj2 <= +1; dj2++) { //for bob corresponding
						int value=0;
						if (j1 == j2) //if same position
							value = grid[i][j1];
						else value = grid[i][j1] + grid[i][j2];
						
						if(j1+dj1 >=0  && j1+dj1 <= m && j2+dj2 >= 0 && j2+dj2 <= m) 
							value +=  dp[i+1][j1+dj1][j2+dj2];
						else value = -1e8; //iwll not consider
						maxi = max(maxi, value);
					}
				}
			  dp[i][j1][j2] = maxi;
			}
		}
	}
	return dp[0][0][m-1];
}

//space optimization
int maximumChocolates(int n, int m, vector<vector<int>> &grid) {
    // Write your code here.
	//int dp[r][c][c] //memoization
	//1d -> two variables
	//2d -> 1D dp
	//3d -> 2D
	//int front[m][m];
	//int curr[n][m];
	vector<vector<int>> front(m,vector<int>(m,0));
	vector<vector<int>> curr(n,vector<int>(m,0));
	for (int j1 = 0; j1 < m; j1++) {
		for (int j2 = 0; j2 < m; j2++) {
			 if (j1 == j2) //same position ,additon of one guy
        		front[j1][j2] = grid[n - 1][j1];
      		else
        		front[j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
    	}
  	}
	  //Outer Nested Loops for travering DP Array
  	for (int i = n - 2; i >= 0; i--) {
    	for (int j1 = 0; j1 < m; j1++) {
      		for (int j2 = 0; j2 < m; j2++) {
				
				int maxi = -1e8;
				for (int dj1 = -1; dj1 <= +1; dj1++) { //for alice
					for (int dj2 = -1; dj2 <= +1; dj2++) { //for bob corresponding
						int value=0;
						if (j1 == j2) //if same position
							value = grid[i][j1];
						else value = grid[i][j1] + grid[i][j2];
						
						if(j1+dj1 >=0  && j1+dj1 <= m && j2+dj2 >= 0 && j2+dj2 <= m) 
							value +=  front[j1+dj1][j2+dj2];
						else value = -1e8; //iwll not consider
						maxi = max(maxi, value);
					}
				}
			  curr[j1][j2] = maxi;
			}
		}
		front= curr;
	}
	return front[0][m-1];
}
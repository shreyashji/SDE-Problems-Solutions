//recusrion
//time= exponential

#include<bits/stdc++.h>
int f(int i,int j,vector<int> &cuts){
	if(i > j) return 0;
	
	int mini = INT_MAX;
	for(int ind =i; ind<=j ; ind++){
		int cost = cuts[j+1] - cuts[i-1]
			+ f(i,ind-1,cuts)
			+ f(ind+1,j,cuts);
		mini = min(mini,cost);
	}
	return mini; 
}
int cost(int n, int c, vector<int> &cuts){
    cuts.push_back(n);
	cuts.insert(cuts.begin(),0);
	sort(cuts.begin(),cuts.end());
	
	return f(1,c,cuts);
}

//memoization
//time = O(M^2 * M) ~ M^3  
//space=  O(M^2)  + aux stack space o(N)
#include<bits/stdc++.h>
int f(int i,int j,vector<int> &cuts,vector<vector<int>> &dp){
	if(i > j) return 0;
	if(dp[i][j] != -1) return dp[i][j];
	int mini = INT_MAX;
	for(int ind =i; ind<=j ; ind++){
		int cost = cuts[j+1] - cuts[i-1]
			+ f(i,ind-1,cuts,dp)
			+ f(ind+1,j,cuts,dp);
		mini = min(mini,cost);
	}
	return dp[i][j] = mini; 
}
int cost(int n, int c, vector<int> &cuts){
    cuts.push_back(n);
	cuts.insert(cuts.begin(),0);
	sort(cuts.begin(),cuts.end());
	vector<vector<int>> dp(c+1,vector<int> (c+1,-1));
	return f(1,c,cuts,dp);
}

//tabulation
//time = O(M^2 * M) ~ M^3  
//space=  O(M^2)  
int cost(int n, int c, vector<int> &cuts){
    cuts.push_back(n);
	cuts.insert(cuts.begin(),0);
	sort(cuts.begin(),cuts.end());
	vector<vector<int>> dp(c+2,vector<int> (c+2,0));
	for(int i=c; i >= 1 ; i--){
		for(int j=1; j <= c; j++){
			if(i > j) continue;
				int mini = INT_MAX;
				for(int ind =i; ind<=j ; ind++){
					int cost = cuts[j+1] - cuts[i-1]
						+ dp[i][ind-1]
						+ dp[ind+1][j];
					mini = min(mini,cost);
				}
				dp[i][j] = mini; 
		}
	}
	
	return dp[1][c];
}
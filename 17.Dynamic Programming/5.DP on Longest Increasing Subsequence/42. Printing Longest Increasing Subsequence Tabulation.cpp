

//tabulation for  Longest Increasing Subsequence
int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
	vector<vector<int>> dp(n+1,vector<int>(n+1,0));
	for(int ind = n-1 ; ind >= 0; ind-- ){
		for(int prev_ind = ind -1; prev_ind>=-1 ; prev_ind--){
				int len = 0 + dp[ind+1][prev_ind+1]; //not take case
				if(prev_ind == -1 || arr[ind] > arr[prev_ind]){ //take case
					len = max(len, 1 + dp[ind+1][ind+1]);
				}
				dp[ind][prev_ind+1] = len;
		}
	}
	return dp[0][-1+1];
}

//tabulation need to know this tabulation cant imagine
//time  = O(N^2)
//space = O(N)
//this solution is required if you want to trace back the LIS,SO PRINT THE LIS
#include<bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
   vector<int> dp(n,1);
	int maxi = 1;
	for(int i=0; i<n ; i++){
		for(int prev = 0; prev< i ; prev++){
			if(arr[prev] < arr[i]){
				dp[i] = max(dp[i] , 1 + dp[prev]);
			}
		}
		maxi = max(maxi,dp[i]);
	}
	return maxi;
}


// printinglis backtracking
//time  = O(N^2)
//space = length of lis
#include<bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
   vector<int> dp(n,1),hash(n,1);
	int maxi = 1;
	int lastindex = 0;
	for(int i=0; i<n ; i++){
	hash[i] = i;
		for(int prev = 0; prev< i ; prev++){
			if(arr[prev] < arr[i] &&
				1 + dp[prev] > dp[i] ) {
				
				dp[i] =  1 + dp[prev];
				hash[i] = prev;
			}
		}
		if(dp[i] > maxi){
			maxi = dp[i];
			lastindex = i;
		}
	}
	//int lis[maxi];
	//int ind = 1;
	//lis[0] = arr[lastindex];
	vector<int> temp;
	temp.push_back(arr[lastindex]);
	while(hash[lastindex] != lastindex){
		lastindex =  hash[lastindex];
		//lis[ind++] =  arr[lastindex]
		temp.push_back(arr[lastindex]);
	}
	reverse(temp.begin(),temp.end());
	for(auto it: temp) cout <<it << " ";
	cout << endl;
	return maxi;
}

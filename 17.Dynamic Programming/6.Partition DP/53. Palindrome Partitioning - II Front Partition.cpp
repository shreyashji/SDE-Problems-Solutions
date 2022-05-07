//recurrence
 //time = exponential
 //space = O(N) 
bool isPalindrome(int i,int j, string &str){
	while(i<j){ 
		if(str[i] != str[j]) return false;
		i++;
		j--;
	}
	return true;
}

int f(int i,int n, string &str){
	if(i==n) return 0;
	int min_cost = INT_MAX;
	//string temp = ''; DONT NEED TO STORE TEMP
	for(int j=i ; j<n ;  j++){
		if(isPalindrome(i,j,str)){
			int cost = 1 + f(j+1,n,str);
			min_cost = min(min_cost, cost);
		}
	}
	return min_cost;
}

int palindromePartitioning(string str) {
    int  n = str.size();
	return f(0,n,str)-1; //-1 coz its partitioning at the end
}


//memoization
 //time = O(N)states  * O(n) loop ~~ O(N^2)
 //space = O(N) dp array + O(N)
#include<bits/stdc++.h>
bool isPalindrome(int i,int j, string &str){
	while(i<j){ 
		if(str[i] != str[j]) return false;
		i++;
		j--;
	}
	return true;
}

int f(int i,int n, string &str,vector<int> &dp){
	if(i==n) return 0;
	if(dp[i] != -1) return dp[i];
	int min_cost = INT_MAX;
	//string temp = ''; DONT NEED TO STORE TEMP
	for(int j=i ; j<n ;  j++){
		if(isPalindrome(i,j,str)){
			int cost = 1 + f(j+1,n,str,dp);
			min_cost = min(min_cost, cost);
		}
	}
	return dp[i] = min_cost;
}

int palindromePartitioning(string str) {
    int  n = str.size();
	vector<int> dp(n,-1); 
	return f(0,n,str,dp)-1; //-1 coz its partitioning at the end
}

//tabulation
#include<bits/stdc++.h>
bool isPalindrome(int i,int j, string &str){
	while(i<j){ 
		if(str[i] != str[j]) return false;
		i++;
		j--;
	}
	return true;
}

int f(int i,int n, string &str,vector<int> &dp){
	if(i==n) return 0;
	if(dp[i] != -1) return dp[i];
	int min_cost = INT_MAX;
	//string temp = ''; DONT NEED TO STORE TEMP
	for(int j=i ; j<n ;  j++){
		if(isPalindrome(i,j,str)){
			int cost = 1 + f(j+1,n,str,dp);
			min_cost = min(min_cost, cost);
		}
	}
	return dp[i] = min_cost;
}

int palindromePartitioning(string str) {
    int  n = str.size();
	vector<int> dp(n+1,0); //n+1 coz we are assigning 
	dp[n] =0;
	for(int i=n-1; i>=0; i--){
			int min_cost = INT_MAX;
			for(int j=i ; j<n ;  j++){
				if(isPalindrome(i,j,str)){
					int cost = 1 + dp[j+1];
					min_cost = min(min_cost, cost);
				}
			}
		dp[i] = min_cost;
	}
	return dp[0]-1; //-1 coz its partitioning at the end
}


//time = O(N^2)+ length of string+O(N log n) for sorting
//space = O(N)
#include<bits/stdc++.h>
bool  checkpossibility(string &s1, string &s2){
	if(s1.size() != s2.size() + 1) return false;
	int first= 0;
	int second = 0;
	while(first < s1.size()){
		if(second<s2.size() && s1[first]  == s2[second]){
			first++;
			second++;
		}
		else {
			first++;
		}
	}
	if(first == s1.size() && second == s2.size() ) return true;
	return false;
}
bool comp(string &s1, string &s2){
	return s1.size() < s2.size();
}
int longestStrChain(vector<string> &arr)
{
	sort(arr.begin(),arr.end(),comp);
	int n = arr.size();
   	vector<int> dp(n,1);
	int maxi = 1;
	sort(arr.begin(),arr.end());
	for(int i=0; i<n ; i++){//O(N^2)
		for(int prev = 0; prev< i ; prev++){
			if(checkpossibility(arr[i],arr[prev]) && //just this change same as lis code printing lis
				1 + dp[prev] > dp[i] ) {
				
				dp[i] =  1 + dp[prev];
			}
		}
		if(dp[i] > maxi){
			maxi = dp[i];
		}
	}
	return maxi;
}
#include<bits/stdc++.h>
int longestBitonicSequence(vector<int>& arr, int n) {
	vector<int> dp1(n,1);
	//from front lis
	for(int i=0; i<n ; i++){//O(N^2)
		for(int prev = 0; prev< i ; prev++){
			if(arr[prev]  <  arr[i] && //just this change same as lis code printing lis
				1 + dp1[prev] > dp1[i] ) {
				
				dp1[i] =  1 + dp1[prev];
			}
		}
	}
	//from backward lis
	int maxi = 0;
	vector<int> dp2(n,1);
	for(int i=n-1; i>=0 ; i--){//O(N^2)
		for(int prev = n-1; prev>i ; prev--){
			if(arr[prev] <  arr[i] && //just this change same as lis code printing lis
				1 + dp2[prev] > dp2[i] ) {
				
				dp2[i] =  1 + dp2[prev];
			}
		}
		maxi = max(maxi,dp1[i]+dp2[i]-1 );	
	} 
/*	int maxi = 0;
	for(int i=0; i<n; i++){ //O(N)
		maxi = max(maxi,dp1[i]+dp2[i]-1 );
	}
*/
	return maxi;
} 

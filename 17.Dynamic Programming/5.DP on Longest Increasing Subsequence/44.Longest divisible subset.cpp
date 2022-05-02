//time = O(N^2) +O(N)
//space = O()
#include<bits/stdc++.h>
vector<int> divisibleSet(vector<int> &arr){
	int n = arr.size();
	vector<int> dp(n,1),hash(n);
	int maxi = 1;
	int lastindex = 0;
	sort(arr.begin(),arr.end());
	for(int i=0; i<n ; i++){//O(N^2)
	hash[i] = i;
		for(int prev = 0; prev< i ; prev++){
			if(arr[i] % arr[prev]==0 && //just this change same as lis code printing lis
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
	while(hash[lastindex] != lastindex){ //trace back entire path O(N)
		lastindex =  hash[lastindex];
		//lis[ind++] =  arr[lastindex]
		temp.push_back(arr[lastindex]);
	}
	reverse(temp.begin(),temp.end());
	return temp;
}
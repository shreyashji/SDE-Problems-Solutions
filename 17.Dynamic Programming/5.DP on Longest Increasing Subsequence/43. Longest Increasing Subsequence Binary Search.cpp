#include<bits/stdc++.h>
//time = O(n * log n)
//space = O(N)
int longestIncreasingSubsequence(int arr[], int n)
{
   	vector<int> temp;
	temp.push_back(arr[0]);
	int len=1;
	for(int i=1 ; i<n ; i++){
		if(arr[i] > temp.back()){
			temp.push_back(arr[i]);
			len++;
		}
		else{//binary search on index
			int ind = lower_bound(temp.begin(),temp.end(),arr[i]) - temp.begin();
			
			temp[ind] = arr[i];
		}
	}
	return len;
}


//https://www.codingninjas.com/codestudio/problems/rahul-and-his-chocolates_3118974?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

//copy solution from buy sell stock 2 problem
//space optimized

#include<bits/stdc++.h>
int maximumProfit(int n, int fee, vector<int> &values) {
    // Write your code here.
	int aheadNotBuy, aheadBuy,currBuy,currNotBuy;
	aheadNotBuy = aheadBuy = 0; //coz ind == n buy can be anything
	for(long ind= n-1 ; ind>=0 ; ind--){
		//sell
				currNotBuy = max(values[ind]-fee + aheadBuy
							, 0+ aheadNotBuy);
		//buy
				currBuy = max(-values[ind] + aheadNotBuy
							,0+ aheadBuy); 
			
			aheadBuy = currBuy;
			aheadNotBuy = currNotBuy;
		}
	return aheadBuy;	
}

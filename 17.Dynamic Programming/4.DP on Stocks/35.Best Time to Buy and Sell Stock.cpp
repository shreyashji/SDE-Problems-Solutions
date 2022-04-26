//buy & sell only done once

int maximumProfit(vector<int> &prices){
	//time = O(N)
	//space =O(1)
	int mini = prices[0];
	int maxprofit =0;
	int n = prices.size();
	for(int i =1 ; i<n ; i++){
		int cost = prices[i] - mini; //selling at this prics - bought at this price
		maxprofit = max(maxprofit,cost);//max of this cost or previous one
		mini = min(mini,prices[i]);//on next iteration keep track of all the minimal of a[i],remembring minimal so dp solution
	}//constructive algo
	return maxprofit;
}
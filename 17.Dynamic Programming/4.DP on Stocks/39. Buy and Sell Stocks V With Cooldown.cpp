class Solution {
private:
    long f(int ind, int buy,vector<int> &prices){
	//0 means cannot buy,1 means can buy
	if(ind >= prices.size()) return 0;//no more profit can be made once array is over
	
	if(buy==1){
		return max(-prices[ind] + f(ind+1,0,prices)
					, 0+ f(ind+1,1,prices));
	}
	
	return max(prices[ind]+ f(ind+2,1,prices)
					,0+ f(ind+1,0,prices)); 
}
public:
    int maxProfit(vector<int>& prices) {
        
        return f(0,1,prices);
    }
};

//memoization
class Solution {
private:
    long f(int ind, int buy,vector<int> &prices,vector<vector<int>> &dp){
	//0 means cannot buy,1 means can buy
	if(ind >= prices.size()) return 0;//no more profit can be made once array is over
	if(dp[ind][buy] !=-1) return dp[ind][buy];
	if(buy==1){
		return dp[ind][buy] = max(-prices[ind] + f(ind+1,0,prices,dp)
					, 0+ f(ind+1,1,prices,dp));
	}
	
	return dp[ind][buy] = max(prices[ind]+ f(ind+2,1,prices,dp)
					,0+ f(ind+1,0,prices,dp)); 
}
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return f(0,1,prices,dp);
    }
};

//tabualtion
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2,vector<int>(2,0));
        for(int ind = n-1 ;ind>=0 ; ind--){ //starting from opposite
		    for(int buy=0; buy<=1; buy++){
                	if(buy==1)
                    {
                        dp[ind][buy] = max(-prices[ind] + dp[ind+1][0]
                                    , 0+ dp[ind+1][1]);
                    }
                    else dp[ind][buy] = max(prices[ind]+ dp[ind+2][1]
                                        ,0+ dp[ind+1][0]); 
                }
        }
    return dp[0][1];
    }
};

// no space optimization
//we can also do this
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2,vector<int>(2,0));
        for(int ind = n-1 ;ind>=0 ; ind--){ //starting from opposite
            dp[ind][1] = max(-prices[ind] + dp[ind+1][0]
                                    , 0+ dp[ind+1][1]);
            
            dp[ind][0] = max(prices[ind]+ dp[ind+2][1]
                                        ,0+ dp[ind+1][0]); 
        }
        return dp[0][1];
    }
};
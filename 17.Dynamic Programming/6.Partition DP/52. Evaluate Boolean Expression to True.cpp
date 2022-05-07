//recursion

#include<bits/stdc++.h>
#define ll long long;
int mod = 1000000007;
long long f(int i,int j, int isTrue,string &exp){
	if(i>j) return 0;
	if(i==j){
		if(isTrue){
			return exp[i] == 'T';
		}
		else return exp[i] == 'F';
	}
	ll ways = 0;
	for(int ind = i+1; ind<=j-1; ind+=2 ){
		ll lT = f(i,ind-1,1,exp);
		ll lF = f(i,ind-1,0,exp);
		ll rT = f(ind+1,j,1,exp);
		ll rF = f(ind+1,j,0,exp);
		
		if(exp[ind] == '&'){
			if(isTrue) ways = (ways+ (rt * lT)%mod )%mod;
			else ways = ways + (rT * lF)%mod + (rF * lT)%mod +
				(rF * lF) %mod )%mod;
		}
		else if(exp[ind] == '|'){
			if(isTrue) ways = (ways+ (lT * rT)%mod + (lT * rF)%mod 
							   + (lF *rT)%mod	)%mod;
			else ways = ways + (rF * lF)%mod) % mod;
		}
		else{ //XOR = T*T=F , T*F=T, F*T=T, F*F=T
			if(isTrue){
				ways = (ways+ (lT * rF)%mod + (lF * rT)%mod )%mod;	
			} 
			else {
				ways = ways + (lT * rT)%mod + (lF * rF)%mod  ) % mod;
			}
		}
	}
	return ways;
}
int evaluateExp(string & exp) {
	int n = exp.size();
    return f(0,n-1,1,exp);
}

//memoization 
#include<bits/stdc++.h>
#define ll long long ;
int mod = 1000000007;
long long f(int i,int j, int isTrue,string &exp,vector<vector<vector<ll>>> &dp){
	if(i>j) return 0;
	if(i==j){
		if(isTrue){
			return exp[i] == 'T';
		}
		else return exp[i] == 'F';
	}
	if(dp[i][j][isTrue] != -1) return dp[i][j][isTrue];
	ll ways = 0;
	for(int ind = i+1; ind<=j-1; ind+=2 ){
		ll lT = f(i,ind-1,1,exp,dp);
		ll lF = f(i,ind-1,0,exp,dp);
		ll rT = f(ind+1,j,1,exp,dp);
		ll rF = f(ind+1,j,0,exp,dp);
		
		if(exp[ind] == '&'){
			if(isTrue) ways = (ways+ (rt * lT)%mod )%mod;
			else ways = ways + (rT * lF)%mod + (rF * lT)%mod +
				(rF * lF) %mod )%mod;
		}
		else if(exp[ind] == '|'){
			if(isTrue) ways = (ways+ (lT * rT)%mod + (lT * rF)%mod 
							   + (lF *rT)%mod	)%mod;
			else ways = ways + (rF * lF)%mod) % mod;
		}
		else{ //XOR = T*T=F , T*F=T, F*T=T, F*F=T
			if(isTrue){
				ways = (ways+ (lT * rF)%mod + (lF * rT)%mod )%mod;	
			} 
			else {
				ways = ways + (lT * rT)%mod + (lF * rF)%mod  ) % mod;
			}
		}
	}
	return dp[i][j][isTrue] = ways;
}
int evaluateExp(string & exp) {
	int n = exp.size();
	vector<vector<vector<ll>>> dp(n,vector<vector<ll>> (n,vector<ll> (2,-1) ) );
    return f(0,n-1,1,exp,dp);
}


//tabulation
#include<bits/stdc++.h>
#define ll long long 
int mod = 1000000007;
int evaluateExp(string & exp) {
    // Write your code here.
	int n = exp.size();
	vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll> (2,0)));
	for (int i = 0; i < n; i++) {
        if (exp[i] == 'T') {
            dp[i][i][1] = 1;
        } else if (exp[i] == 'F') {
            dp[i][i][0] = 1;
        }
    }
	for(int i = n - 1; i >= 0; i--)
	{
		for(int j = 0; j < n; j++)
		{
			for(int ind = i + 1; ind <= j - 1; ind += 2)
			{
				ll LF = dp[i][ind - 1][0];
				ll LT = dp[i][ind - 1][1];
				ll RF = dp[ind + 1][j][0];
				ll RT = dp[ind + 1][j][1];
				if(exp[ind] == '&')
				{
					dp[i][j][1] = (dp[i][j][1] + (LT * RT) % mod) % mod;	
					dp[i][j][0] = (dp[i][j][0] + (LT * RF) % mod + (LF * RT) % mod + (LF * RF) % mod) % mod;
 
				}
				else if(exp[ind] == '|')
				{
					dp[i][j][1] = (dp[i][j][1] + (LT * RT) % mod+ (LT * RF) % mod + (LF * RT) % mod) % mod;	
					dp[i][j][0] = (dp[i][j][0] + (LF * RF) % mod) % mod;
				}
				else
				{
					dp[i][j][1] = (dp[i][j][1] + (LT * RF) % mod + (LF  RT) % mod) % mod;
					dp[i][j][0] = (dp[i][j][0] + (LF * RF) % mod + (LT * RT) % mod) % mod;
				}
			}
		}
	}
	return dp[0][n - 1][1];
}
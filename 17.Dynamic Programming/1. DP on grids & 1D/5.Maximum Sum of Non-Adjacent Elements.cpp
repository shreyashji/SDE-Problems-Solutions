//https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1
//recurrence relation or recursion
//time = O(2^N)
//space 
int f(int ind ,vector<int> &nums){
    if(ind == 0) return nums[ind];
    if(ind < 0 ) return 0;
    
    int pick = nums[ind] + f(ind - 2,nums);//for non adjacent
    int notpick = 0 + f(ind - 1,nums);
    
    return max(pick,notpick);
}
int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    return f(n-1,nums)
}

//memoization
//time = O(N)
//space = O(N) for recursion stack space + O(N) for dp array ~~O(N) 
int f(int ind ,vector<int> &nums,vector<int> &dp){
    if(ind == 0) return nums[ind];
    if(ind < 0 ) return 0;
    if(dp[ind] != -1) return dp[ind];
    
    int pick = nums[ind] + f(ind - 2,nums,dp);//for non adjacent
    int notpick = 0 + f(ind - 1,nums,dp);
        
    return dp[ind] = max(pick,notpick);
}

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n,-1);
    return f(n-1,nums,dp);
}

//tabulation 
#include <bits/stdc++.h>
using namespace std;
int solveUtil(int n, vector<int>& arr, vector<int>& dp){
    dp[0]= arr[0];
    for(int i=1 ;i<n; i++){
        int pick = arr[i];
        if(i>1)
            pick += dp[i-2];
        int nonPick = 0+ dp[i-1];
        
        dp[i]= max(pick, nonPick);
    }
    return dp[n-1];
}

int solve(int n, vector<int>& arr){
    vector<int> dp(n,-1);
    return solveUtil(n, arr, dp);
}
int main() {

  vector<int> arr{2,1,4,9};
  int n=arr.size();
  cout<<solve(n,arr);
}

//space optimization 
//time  = O(n)
//space = (1) 
int maximumNonAdjacentSum(vector<int> &nums){
    int n=nums.size();
    int prev = nums[0];
    int prev2 =0;
    for(int i=1; i<n; i++){
        int pick = nums[i];
        if(i>1)
            pick += prev2; //
        int nonPick = 0 + prev; //
        
        int cur_i = max(pick, nonPick); //
        prev2 = prev; //
        prev= cur_i;  //
    }
    return prev;
}
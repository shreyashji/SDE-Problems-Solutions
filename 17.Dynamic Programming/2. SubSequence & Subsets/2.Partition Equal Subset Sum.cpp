//memoization
#include <bits/stdc++.h>
//Time Complexity: O(N*K)here are N*K states therefore at max ‘N*K’ new problems will be solved  + O(N) a for loop for ‘N’ times to calculate the total sum
//Space Complexity: O(N*K) + O(N) We are using a recursion stack space(O(N)) and a 2D array ( O(N*K)).
using namespace std;
bool subsetSumUtil(int ind, int target, vector<int>& arr, vector<vector<int>> &dp){
    if(target==0)
        return true;
    
    if(ind == 0)
        return arr[0] == target;
    
    if(dp[ind][target]!=-1)
        return dp[ind][target];
        
    bool notTaken = subsetSumUtil(ind-1,target,arr,dp);
    
    bool taken = false;
    if(arr[ind]<=target)
        taken = subsetSumUtil(ind-1,target-arr[ind],arr,dp);
        
    return dp[ind][target]= notTaken||taken;
}

bool canPartition(int n, vector<int> &arr){
    
    int totSum=0;
    
    for(int i=0; i<n;i++){
        totSum+= arr[i];
    }
    
    if (totSum%2==1) return false;
    
    else{
        int k = totSum/2;
        vector<vector<int>> dp(n,vector<int>(k+1,-1));
        return subsetSumUtil(n-1,k,arr,dp);
    } 
}

int main() {
  vector<int> arr = {2,3,3,3,4,5};
  int n = arr.size();                                
  if(canPartition(n,arr))
    cout<<"The Array can be partitioned into two equal subsets";
  else 
    cout<<"The Array cannot be partitioned into two equal subsets";
}
//TABULATUON

#include <bits/stdc++.h>
using namespace std;
bool canPartition(int n, vector<int> &arr){
    int totSum=0;
    for(int i=0; i<n;i++){
        totSum+= arr[i];
    }
    
    if (totSum%2==1) return false;

    else{
        int k = totSum/2;
        vector<vector<bool>> dp(n,vector<bool>(k+1,false));
    
        for(int i=0; i<n; i++){
            dp[i][0] = true;
        }
        
        if(arr[0]<=k)
            dp[0][arr[0]] = true;
        
        for(int ind = 1; ind<n; ind++){
            for(int target= 1; target<=k; target++){
                
                bool notTaken = dp[ind-1][target];
        
                bool taken = false;
                    if(arr[ind]<=target)
                        taken = dp[ind-1][target-arr[ind]];
            
                dp[ind][target]= notTaken||taken;
            }
        }   
        return dp[n-1][k];
    } 
}

int main() {
  vector<int> arr = {2,3,3,3,4,5};
  int n = arr.size();                        
  if(canPartition(n,arr))
    cout<<"The Array can be partitioned into two equal subsets";
  else 
    cout<<"The Array cannot be partitioned into two equal subsets";
}



//space optimized 
//time =  O(N*K) +O(N)
//space = O(K)
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<bool> prev(k+1,0),curr(k+1,0);
	prev[0]=curr[0] =true;
    //if arr[0] is greater than the target,target was alwasy greater than the target element
    if(prev[arr[0]] <= k) prev[arr[0]] = true; //base case
	
	for(int ind =1; ind<n ; ind++){
		for(int target=1; target<=k; target++){
			bool nottake = prev[target];
			bool take =false;
			if(arr[ind] <= target) take = prev[target-arr[ind]]; 
			curr[target]= take | nottake;
		}
		prev = curr;
	}
	return prev[k];
}

bool canPartition(vector<int> &arr, int n)
{
	int totalsum = 0;
	for(int i=0; i<n ;i++) totalsum +=arr[i];
	if(totalsum % 2) return false; //if odd no.,odd cannot be divided into two subsets
	int target = totalsum/2;
	return (subsetSumToK(n,target,arr)); //size of array n

}

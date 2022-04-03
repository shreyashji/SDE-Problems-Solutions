

#include <bits/stdc++.h>
using namespace std;
//avoid using global variables 
//this is memoization of recursion
//time = O(n) depth of recur linear
//space = O(n) for recr stack space +O(n) array
int f(int n, vector<int>& dp){
    if(n<=1) return n;
    
    if(dp[n]!= -1) return dp[n]; //3. Check if its is already computed and store in dp array if yes return value
    return dp[n]= f(n-1,dp) + f(n-2,dp); //2. store whatever computed
}

int main() {

  int n=5;
  vector<int> dp(n+1,-1); //1. declare dp array which store whatever computed
  cout<<f(n,dp);
  return 0;
}

/*
//Steps to convert Recursive Solution to Tabulation one.
//1. declare a dp[] array of size n+1.
//2. First initialize the base condition values, i.e i=0 and i=1 of the dp array as 0 and 1 respectively.
//3. Set an iterative loop which traverses the array( from index 2 to n) and for every index set its value as dp[i-1] + dp[i-2]. 
#include <bits/stdc++.h>
using namespace std;
//time = O(n) depth of recur linear
//space = O(n) for array dp
int main() {

  int n=5;
  vector<int> dp(n+1,-1);
  
  dp[0]= 0;
  dp[1]= 1;
  
  for(int i=2; i<=n; i++){
      dp[i] = dp[i-1]+ dp[i-2];
  }
  cout<<dp[n];
  return 0;
}

*/

/*
Part 3: Space Optimization
//If we closely look the relation,
//dp[i] =  dp[i-1] + dp[i-2]
//we see that for any i, we do need only the last two values in the array. So is there a need to maintain a whole array for it? 
//The answer is ‘No’. Let us call dp[i-1] as prev and dp[i-2] as prev2. Now understand the following illustration.

//each iteration’s cur_i and prev becomes the next iteration’s prev and prev2 respectively.
//Therefore after calculating cur_i, if we update prev and prev2 according to the next step, we will always get the answer. 
//After the iterative loop has ended we can simply return prev as our answer.

#include <bits/stdc++.h>
using namespace std;
//time = O(n) depth of recur linear
//space = O(1) constant
int main() {

  int n=5;
  
  int prev2 = 0;
  int prev = 1;
  
  for(int i=2; i<=n; i++){
      int cur_i = prev2+ prev;
      prev2 = prev;
      prev= cur_i;
  }
  
  cout<<prev;
  return 0;
}


*/
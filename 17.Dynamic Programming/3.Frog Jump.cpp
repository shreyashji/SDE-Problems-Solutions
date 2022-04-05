//https://www.codingninjas.com/codestudio/problems/frog-jump_3621012?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
/*
There is a frog on the 1st step of an N stairs long staircase. The frog wants to reach the Nth stair. HEIGHT[i] is the height of the (i+1)th stair.If Frog jumps from ith to jth stair, the energy lost in the jump is given by |HEIGHT[i-1] - HEIGHT[j-1] |.In the Frog is on ith staircase, he can jump either to (i+1)th stair or to (i+2)th stair. Your task is to find the minimum total energy used by the frog to reach from 1st stair to Nth stair.
For Example
If the given ‘HEIGHT’ array is [10,20,30,10], the answer 20 as the frog can jump from 1st stair to 2nd stair (|20-10| = 10 energy lost) and then a jump from 2nd stair to last stair (|10-20| = 10 energy lost). So, the total energy lost is 20.
Input Format:
The first line of the input contains an integer, 'T,’ denoting the number of test cases.

The first line of each test case contains a single integer,' N’, denoting the number of stairs in the staircase,

The next line contains ‘HEIGHT’ array.
Output Format:
For each test case, return an integer corresponding to the minimum energy lost to reach the last stair.
Note:
You do not need to print anything. It has already been taken care of. Just implement the given function.
*/

//memoization
//time= O(n) n steps The overlapping subproblems will return the answer in constant time O(1). Therefore the total number of new subproblems we solve is ‘n’. Hence total time complexity is O(N).
///space= O(N) + O(N) ≈ O(N) ,We are using a recursion stack space(O(N)) and an array (again O(N))
#include<bits/stdc++.h>
int f(int ind,vector<int> &heights, vector<int> &dp ){
    if(ind == 0 ) return 0;
    if(dp[ind] != -1) return dp[ind]; //if ans come across just check and return
    
    int left = f(ind - 1,heights, dp) + abs(heights[ind] - heights[ind - 1]);
    int right = INT_MAX; //NOT ALWAYS
    if(ind>1) right = f(ind - 2,heights, dp) + abs(heights[ind] - heights[ind - 2]);
    return dp[ind] = min(left,right);
}

int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int> dp(n+1, -1); //for dp solution
    return f(n-1,heights,dp);
}

// tabulation bottom up
//time = O(n)  We are running a simple iterative loop
//space = O(n) Reason: We are using an external array of size ‘n+1’.
#include<bits/stdc++.h>
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int> dp(n, 0); 
    dp[0] = 0;
    for(int i=1; i<n ; i++){
        int fs = dp[i-1] + abs(heights[i] - heights[i-1]);
        int ss = INT_MAX;
        if(i>1)
            ss = dp[i-2] + abs(heights[i] - heights[i-2]);
        dp[i] = min(fs,ss);
    }
    return dp[n-1]; //anns stored at last index always
}

// space optimization  
//time= O(n) We are running a simple iterative loop
///space= O(1) We are not using any extra space.
#include<bits/stdc++.h>
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
  	int prev = 0 ;
    int prev2= 0;
    for(int i=1; i<n ; i++){
        int fs = prev + abs(heights[i] - heights[i-1]);
        int ss = INT_MAX;
        if(i>1)
            ss = prev2 + abs(heights[i] - heights[i-2]);
        int curi = min(fs,ss);
        prev2= prev;
        prev = curi;
    }
    return prev; //anns stored at last index always
}
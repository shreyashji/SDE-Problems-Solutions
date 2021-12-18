//brute force
/*
Length of Longest Substring without any Repeating Character
Problem Statement: Given a String, find the length of longest substring without any repeating character.

Examples:

Example 1:

Input: s = ”abcabcbb”

Output: 3

Explanation: The answer is abc with length of 3.

Example 2:

Input: s = ”bbbbb”

Output: 1

Explanation: The answer is b with length of 1 units.
Solution
Disclaimer: Don’t jump directly to the solution, try it out yourself first.

Solution 1: Brute force Approach

Approach: This approach consists of taking the two loops one for traversing the string and another loop – nested loop for finding different substrings and after that, we will check for all substrings one by one and check for each and every element if the element is not found then we will store that element in HashSet otherwise we will break from the loop and count it.

#include<bits/stdc++.h>

using namespace std;

int solve(string str) {
  int maxans = INT_MIN;
  for (int i = 0; i < str.length(); i++) // outer loop for traversing the string
  {
    unordered_set < int > set;
    for (int j = i; j < str.length(); j++) // nested loop for getting different string starting with str[i]
    {
      if (set.find(str[j]) != set.end()) // if element if found so mark it as ans and break from the loop
      {
        maxans = max(maxans, j - i);
        break;
      }
      set.insert(str[j]);
    }
  }
  return maxans;
}

int main() {
  string str = "takeUforward";
  cout << "The length of the longest substring without repeating characters is " << 
  solve(str);
  return 0;
}
*/


/////most optimized  solution 
//time=O(n) traversing
//space=O(n) hashmap

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       vector<int> mpp(256, -1); //frequency map,why 256,string can have 256 different characters
        int left=0,right=0;
        int n=s.size();
        int len=0;
        while(right<n){ //iterate till last index
        //if the char at right index exist or not= if does exist i take it and do a +1,
        //but i dont update it,unless it is greater than left
        //basically if it gonna lies to the left i am not gonna update it,coz its not in the range l-r
            if(mpp[s[right]]!=-1) left = max (mpp[s[right]] +1,left);
            //update the current index last seen at the hashmap
            mpp[s[right]]=right;
    //find the range of my current substring,if it is greater than the previous lenght we computed,simply update on the lenth variable
            len=max(len,right-left+1);
            right++; //move right to next
        }
        return len; //after complt iteration, this will return the length of longest substring
    }
};
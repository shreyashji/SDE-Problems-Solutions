//https://practice.geeksforgeeks.org/problems/key-pair5616/1
//https://www.youtube.com/watch?v=7xx1YcXXEYU&list=PLzjZaW71kMwQ-D3oxCEDHAvYu8VC1XOsS&index=11&t=11s

/*
Input:
N = 6, X = 16
Arr[] = {1, 4, 45, 6, 10, 8}
Output: Yes
Explanation: Arr[3] + Arr[4] = 6 + 10 = 16
*/

// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Function to check if array has 2 elements
	// whose sum is equal to the given value
	bool hasArrayTwoCandidates(int arr[], int n, int x) {
	    // code here
	    unordered_map<int,int> umap;
	    for(int i=0;i<n;i++)
	        umap[arr[i]]++;
	    for(auto itr = umap.begin(); itr!=umap.end(); itr++){//traverse every elmnt on umap
	        int key = itr->first;
	        int val = itr->second;
	        int pair = x-key;
	        if(pair==key){
	            if(val>1)//check if its only occur 2 then true
	                return true;
	            }
	            else
	            {
	                if(umap.find(pair)!=umap.end())//if pair is available in umap
	                return true;
	            }
	        }
	   return false;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.hasArrayTwoCandidates(arr, n, x);
        cout << (ans ? "Yes\n" : "No\n");
    }
    return 0;
}
  // } Driver Code Ends

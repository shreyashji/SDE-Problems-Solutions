//https://practice.geeksforgeeks.org/problems/winner-of-an-election-where-votes-are-represented-as-candidate-names-1587115621/1
//https://www.youtube.com/watch?v=GySYmmehLM0&list=PLzjZaW71kMwQ-D3oxCEDHAvYu8VC1XOsS&index=13

// { Driver Code Starts
#include <iostream>
#include <map>
#include <algorithm>
#include <cstdlib>
#include<bits/stdc++.h>
using namespace std;
class Solution{
  public:
  
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[],int n)
    {
    unordered_map<string , int>umap;
        for(int i=0;i<n;i++){
            umap[arr[i]]++;
        }
        
        string name = "";
        int max_vote = 0;
        
        for(auto itr = umap.begin(); itr!=umap.end(); itr++){
            string key = itr->first;//string
            int val = itr->second; //value
            
            if(val>max_vote){
                max_vote = val;
                name = key;
            }
            else if(val == max_vote){//in this case sort lexicographical order
                if(key<name) //small name 
                    name = key;
            }
        }
        
        vector<string> ans;
        ans.push_back(name);
        string temp = to_string(max_vote);
        ans.push_back(temp);
        
        return ans;
    }  
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++)
    {
        
        
        int n;
        cin>>n;
        
        string arr[n];
        
        for (int i=0;i<n;i++)
        cin>>arr[i];
        Solution obj;
        vector<string> result = obj.winner(arr,n);
        
        cout<<result[0] << " " << result[1] << endl;
    }
    return 0;
}
  // } Driver Code Ends
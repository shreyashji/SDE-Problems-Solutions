//https://practice.geeksforgeeks.org/problems/non-repeating-element3958/1

// { Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 // } Driver Code Ends
class Solution{
    public:
    int firstNonRepeating(int arr[], int n) 
    { 
        // Complete the function
        unordered_map<int, int> umap;//key & value(occurence)
        for(int i=0;i<n;i++)
            umap[arr[i]]++; //unordered map is ready with ocurence
        //above thing can also be implemented in below way   
        // int key = arr[i];
        // umap[key]++;
        
         for(int i=0;i<n;i++){//seach for occurence =1
            int key = arr[i]; 
            auto temp = umap.find(key); //O(1)
            if(temp->second ==1) //first is key ,second is ocurence value
                return key;
        }
        return 0;
    } 
};
// { Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.firstNonRepeating(arr,n)<<endl;
    }
}
  // } Driver Code Ends
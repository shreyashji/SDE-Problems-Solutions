/*
//https://practice.geeksforgeeks.org/problems/pairs-with-positive-negative-values3719/1
int n=12
arr[]=[11,-4,4,-3,-9,4,-4,-2,1,2,-4,2]
traverse array & store the -ive values
v[]=[-4,-3,-9,-4,-2,-4]

ordered map<int,int>mp for storing +ive elemnt counts
1->1
2->2
4->2
11->1

sort the array v  []= [-9,-4,-4,-4,-3,-2] 

traverse from behind ,decr the count if match exist if countr grter than 0 match exist
op =[-2,2,-4,4,-4,4]
*/
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
class Solution{
  public:
    vector<int> PosNegPair(int a[], int n) {
        vector<int>v, ans;
        map<int,int>mp;//storing +ive valew & count its
        
        for(int i=0;i<n;i++){
            if(a[i]<0)
                v.push_back(a[i]); //if negative
            else
                mp[a[i]]++;//store +ive vale
        }
        
        sort(v.begin(), v.end());//sort array
        
        for(int i=(int)v.size()-1; i>=0 ; i--){//from behind
            int data = abs(v[i]);//absolute value
            if(mp[data]>0){
                ans.push_back(v[i]);//first -ive value insert
                ans.push_back(data);//+ive value insert
                mp[data]-=1;//decrese the count
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> v = obj.PosNegPair(a, n);

        if (v.size() == 0) cout << "0";

        for (auto it : v) cout << it << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
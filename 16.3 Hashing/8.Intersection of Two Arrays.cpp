//https://practice.geeksforgeeks.org/problems/intersection-of-two-arrays2404/1#
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // Function to return the count of the number of elements in
    // the intersection of two arrays.
    int NumberofElementsInIntersection(int a[], int b[], int n, int m) {
        // Your code goes here
    unordered_set<int>s;
    for(int i=0;i<n;i++)    
        s.insert(a[i]); //unordered set ready
        
    int count=0;
    for(int i=0;i<m;i++){
        int key = b[i];
    if(s.find(key)!=s.end()){
            count++; //if key is prsnt incr count
            s.erase(key);//after counting remove ,if duplicate in second arry will create problem,we want common not occurence
        }
    }
    return count;
    }
};
// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n], b[m];
        for (int i = 0; i < n; i++) cin >> a[i];

        for (int i = 0; i < m; i++) cin >> b[i];
        Solution ob;
        cout << ob.NumberofElementsInIntersection(a, b, n, m) << endl;
    }
    return 0;
}  // } Driver Code Ends
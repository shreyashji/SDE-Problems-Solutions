//https://practice.geeksforgeeks.org/problems/first-repeating-element4018/1
/*
arr[] = {1, 5, 3, 4, 3, 5, 6}
unordere map
1->1
5->2
3->2
4->1
6->1
traverse the array & make unordered map & store the count
traverse the array again &  check wheather for that particular array element  its count is greater than 1
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // Function to return the position of the first repeating element.
    int firstRepeated(int arr[], int n) {
        // code here
    unordered_map<int,int> umap;
    for(int i=0;i<n;i++)
        umap[arr[i]]++; //umap is ready
    for(int i=0;i<n;i++){
        int key = arr[i];
        auto temp = umap.find(key); 
        int val= temp->second; //val is count or ocuurence
        if(val >1) //if count>! on first time then return
            return i+1;//return index,+1 coz 1 based indexing
        }   
      return -1;
    }
};

// { Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; ++i) cin >> arr[i];
        Solution ob;
        cout << ob.firstRepeated(arr, n) << "\n";
    }

    return 0;
}
  // } Driver Code Ends
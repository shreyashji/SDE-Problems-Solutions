#include <bits/stdc++.h>
using namespace std;
//count no. of subsequences whose sum is k (take /not take)
//arr[1,2,1],k=2 ->[1,1],[2]
int printS(int ind,int s,int sum,int arr[],int n){
    //condition not satisfied
    //strictly doen if array contains onnly positive
    if(s > sum) return 0;
    if(ind == n){
        //condition satisfied
        if(s == sum) return 1;
        //condition not satisfied
       else return 0;
    }
    
    //take or pick the particular index into the subsequence
    s += arr[ind];
    
    int l = printS(ind+1, s, sum, arr, n); //every recr call endup at base case,base case tell you does this recr call give ans or not,just sum it up
    
    s -= arr[ind];
    //not pick or not take condition,this element is not added to our subsequence
    //put this before take or pick to get in reverse order
    int r = printS(ind+1, s, sum, arr, n);
    return l+r;
}
int main()
{
    
    int arr[]={1,2,1};
    int n=3;
    int sum=2;
   cout<<printS(0,0, sum, arr, n);
    return 0;
}
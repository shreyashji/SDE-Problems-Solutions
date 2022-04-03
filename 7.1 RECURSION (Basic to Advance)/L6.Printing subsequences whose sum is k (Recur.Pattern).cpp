///https://www.youtube.com/watch?v=eQCS_v3bw0Q&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=7
#include <bits/stdc++.h>
using namespace std;
//printing subsequences whose sum is k (take /not take)
//arr[1,2,1],k=2 ->[1,1],[2]
void printS(int ind,vector<int> &ds,int s,int sum,int arr[],int n){//taking sum s, sum which is given
    if(ind == n){
        if(s == sum){
            for(auto it:ds) cout<<it<<" ";
            cout<<endl;
        }
        return;
    }
    
    //take or pick the particular index into the subsequence
    ds.push_back(arr[ind]);
    s += arr[ind];
    
    printS(ind+1, ds, s, sum, arr, n);
    s -= arr[ind]; //when coming back remvoe from summation
    ds.pop_back();
    
    //not pick or not take condition,this element is not added to our subsequence
    //put this before take or pick to get in reverse order
    printS(ind+1, ds, s, sum, arr, n);
}
int main()
{
    
    int arr[]={1,2,1};
    int n=3;
    int sum=2;
    vector<int> ds;
    printS(0, ds,0, sum, arr, n);
    return 0;
}
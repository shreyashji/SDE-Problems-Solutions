#include <bits/stdc++.h>
using namespace std;
//print subsequences : a contigious/non contigious sequence which follow the order
//arr[3,1,3] = 3,1,2,3 1, 1 2, 3 2 , 3 1 2 { 3 2 1 is not coz not following order of arr to call it as subsequence} 
//can use powerset algo ,but we will do with recursion
//this structure of code or patter we will follow till beyond
//time = 2^N *n (for loop to print )
//space= max 3 recr depth O(n)
void printf(int ind,vector<int> &ds,int arr[],int n){
    if(ind==n){
        for(auto it:ds){
            cout<<it<<" ";
        }
        if(ds.size()==0){
            cout<<"{}";//print null
        }
        cout<<endl;
        return;
    }
    //take or pick the particular index into the subsequence
    ds.push_back(arr[ind]);
    printf(ind+1,ds,arr,n);
    ds.pop_back();
    //not pick or not take condition,this element is not added to our subsequence
    //put this before take or pick to get in reverse order
     printf(ind+1,ds,arr,n);
}
int main()
{
    
    int arr[]={3,1,2};
    int n=3;
    vector<int> ds;
    printf(0,ds,arr,n);
    return 0;
}
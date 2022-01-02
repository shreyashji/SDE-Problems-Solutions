/*
time=O(2NlogN) two array sorting + O(2N) two pointer approach two array
space=O(1)
*/

#include<bits/stdc++.h>
using namespace std;
 
 int countPlatforms(int n,int arr[],int dep[])
 {
    sort(arr,arr+n);
    sort(dep,dep+n);
 
    int ans=1; //maximum or result,initialy  train has taken up 1 platform
    int count=1; //0th index train take 1 platform
    int i=1,j=0;  
    while(i<n && j<n) 
    {
        if(arr[i]<=dep[j]) //one more platform needed
        {
            count++;
            i++;
        }
        //dep train departed before the next arrival train
        else //one platform can be reduced
        {
            count--;
            j++;
        }
        ans=max(ans,count); //updating the value with the current maximum
    }
    return ans;
 }
 
 int main()
 {
    int arr[]={900,945,955,1100,1500,1800};
    int dep[]={920,1200,1130,1150,1900,2000};
    int n=sizeof(dep)/sizeof(dep[0]);
    cout<<"Minimum number of Platforms required "<<countPlatforms(n,arr,dep)<<endl;
 }
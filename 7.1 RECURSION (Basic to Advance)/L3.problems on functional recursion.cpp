//problems on functional recursion

#include <bits/stdc++.h>
using namespace std;
//reverse an array, with only one variable
void f(int i,int arr[],int n){
    if(i>=n/2) return;  //base case
    swap(arr[i],arr[n-i-1]);
    f(i+1,arr,n);//swap next
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    f(0,arr,n);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    return 0;
}

/*
//TIME= HALF INDEX OR N/2 HALF LENGHTH
#include <bits/stdc++.h>
using namespace std;
//check if a string is palindrome or not
bool f(int i,string &s){
    if(i>=s.size()/2) return true;
    if(s[i]!=s[s.size() - i - 1]) return false;
    return f(i+1,s);
}

int main()
{
string s="MADAM";
cout<<f(0,s);

    return 0;
}

*/
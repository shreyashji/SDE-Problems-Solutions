#include <bits/stdc++.h>
using namespace std;
//time=every time calling 2 recursion,exponential in nature n=4=2^4=16 calls,can be trimmed down with dynamic programming
//check fibonaci no. with multiple recursion calls
int f(int n){
    if(n <= 1) return n;
   int last=f(n-1);
   int sec_last=f(n-2);
    return last + sec_last;
}

int main()
{
    cout<<f(4);
    return 0;
}
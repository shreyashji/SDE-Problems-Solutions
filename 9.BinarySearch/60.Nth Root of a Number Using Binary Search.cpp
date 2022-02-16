/*
binary search is not only limited to finding elements in array,binary search can be implemented in any search 
space which is monotonic in nature either linearly increasing or either linearly decreasing
1*1*1=1
2*2*2=8
3*3*3=27
4*4*4=64
incresing
search space n=3 m=27 [1(low)....to...27(high)] ,middle of this will be 1+27/2=14, 14*14*14,
answer eill lies somewhere btw [1.......14].....27 not],find middle 1+14/2=7.5, 7.5*7.5*7.5>27,
reduce search space [1.........7.5] mid= 1+7.5/2=4.25,4.25*4.25*4.25>27
[1.........4.25] mid= 1+4.25/2=2.625*2.625*2.625<27
[2.625(low)......4.25(high)] mid= 2.625+4.25/2= 3.4375*3.4375*3.4375>27, shrink
[2.625......3.4375]  till how shrink high-low(diff)>1e-6(n^-6)
n=2,m=4 2 root 4=2, n=3 m=27 3 root 27=3,n=4 m=15 4 root 15=1.96
*/
#include <bits/stdc++.h>
using namespace std;
//time = N * log base 2 (M*10)^d
//space= log base 2 (M*10)^d (trim down to d places)
double multiply(double number, int n) {
    double ans = 1.0;
    for(int i = 1;i<=n;i++) {
        ans = ans * number;
    }
    return ans; 
}

double getNthRoot(int n, int m) {
    double low = 1;
    double high = m;
    double eps = 1e-6; //difference btw hig and low,no of places of decimal
    //while(low<=high) genral binary search tree
    //but here we are shrinking search spase
    while((high - low) > eps) {
        double mid = (low + high) / 2.0; //get middle
        if(multiply(mid, n) < m) { //multiply function runs n times n*n*n
            low = mid; 
        }
        else {
            high = mid; 
        }
    }
    
    cout << low << " " << high << endl; 
    
    // just to check
    cout << pow(m, (double)(1.0/(double)n)); 
}
int main() {
	int n, m;
	cin >> n >> m; 
	getNthRoot(n, m); 
	return 0;
}
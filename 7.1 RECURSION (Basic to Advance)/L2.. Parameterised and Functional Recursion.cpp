#include <iostream
using namespace std;
//Summation of first n numbers using recursion,n=3,3+2+1=6,(parametrized way & functional way)
//parametrized way,currently its printing
void functn(int i,int sum){
    if(i<1){
        cout<<sum<<"\n";
        return;
        }
     functn(i-1,sum+i);
}
int main()
{
    int n;
    cin>>n;
    functn(n,0);
    return 0;
}

/*
//Summation of first n numbers using recursion,n=3,3+2+1=6,(functional way)
//functionla , return the answer
int functn(int n){
    if(n==0) return 0;
    return n + functn(n-1);
}
int main()
{
    int n=3;
    cout<<functn(n);
    return 0;
}
*/

/*
//time= O(n)
//space=O(n) auxilary
//factorial of n numbers using recursion
//functionla , return the answer
int factorial(int n){
    if(n==0) return 1;
    return n * factorial(n-1);
}
int main()
{
    int n=6;
    cout<<factorial(n);
    return 0;
}
*/
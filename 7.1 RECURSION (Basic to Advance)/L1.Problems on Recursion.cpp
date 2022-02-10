using namespace std;
//Q1.PRINT NAMES n times using recursion
void functn(int i,int n){
    if(i>n) //base case
    return; 
    cout<<"shreyash"<<"\n";
    functn(i+1,n);
}
int main()
{
    int n;
    cin>>n;
    functn(1,n);
    return 0;
}
/*
//Q2.PRINT LINEARLY FROM 1 TO N ,1 TO N
void functn(int i,int n){
    if(i>n) //base case
    return;
    cout<<i<<"\n";
    functn(i+1,n);
}
int main()
{
    int n;
    cin>>n;
    functn(1,n);
    return 0;
}
*/

/*
//Q3.PRINT in opposite  n to 1, 4,3,2,1
void functn(int i,int n){
    if(i<1) //base case
    return; 
    cout<<i<<"\n";
    functn(i-1,n);
}
int main()
{
    int n;
    cin>>n;
    functn(n,n);
    return 0;
}
*/

/*
//Q4.PRINT from 1 to n, but dont use +1,use backtracking
void functn(int i,int n){
    if(i<1) //base case
    return; 
    functn(i-1,n);
    cout<<i<<"\n";
    
}
int main()
{
    int n;
    cin>>n;
    functn(n,n);
    return 0;
}
*/

/*
//Q5.Print from N to 1 in terms of backtracking
void functn(int i,int n){
    if(i>n) //base case
    return; 
    functn(i+1,n);
    cout<<i<<"\n";
    
}
int main()
{
    int n;
    cin>>n;
    functn(1,n);
    return 0;
}
*/
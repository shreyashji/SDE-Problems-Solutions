// n can be -ive or not ,if yes then then we need to handle some edge cases

class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;
        long long nn=n; //copy of n,coz value of n get destroyed in algo
        if(nn<0) nn = -1 * nn; //if -ive value,we make it as +ive value
        while(nn){       
            if(nn%2){    
                ans=ans*x; //if nn is odd power the answer will get multiply
                nn=nn-1; //and value nn get reduced by 1
            }
        else{
            x=x*x; //if even power x * by itself
            nn=nn/2;  //and nn divede by 2
        }
    }
        //check for value of n 
        //if n is a -ive no we will return 1/x^n which is 1/ans ,below
        if(n<0) ans = (double)(1.0) / (double)(ans);
        return ans;
    }
};
//Q1.every integer occur twice and 1 integer occur once,you have to print that one integer
int a[]={2,1,2,5,6,5,7,7,6};
//answer should be 1
//Use XOR 
xor=0
for(i=0; i<n; i++){
    xor=xor^a[i];
}
print(xor) -->single number(all double digit will cancel out and only 1 will be left that will be our no.) 

//Q2.swap this two no,without using two no
a=5,b=7
a=a^b |,a=5^7
b=a^b |,b=7,a=5^7, b=5^7^7 ,7 7 will get cancel,( b=5, a=5^7)
a=a^b |,a=5^7^5 5 5 will get cancel,b=5, a=5,b=7 

//Q3.Given n print the XOR OF ALL no. between (1 to n)
//input 5
//output  1^2^3^4^5=1, (1^2=3,3^3=0,0^4=4,4^5=100&101=001=1)
-N=1    1
--N=2   3
---N=3  0
N=4     4
---------pattern
-N=5    1
--N=6   7
---N=7  0
N=8     8
if(n%4==0) print(n)
if(n%4==1) print(1)
if(n%4==2) print(n+1)
if(n%4==3) print(0)
O(1) solution no matter how big is n

//Q4.given a range (L-R)print XOR 
//LIKE(L^L+1^L+2.....R-1^)
inp= L=2,R=4
o/p= 2^3^4=5 
(3-6) = (3^4^5^6)
xor(6)         xor(2)
(1^2^3^4^5^6)   (1^2) (1,2 should cancel off)
(1^2^3^4^5^6) ^(1^2) = (3^4^5^6)
XOR(R)^XOR(L-1) = O(1) SOLUTION

//USE CASE OF & AND OPERATOR
GIVEN A NO. N,check if a no. N is odd or not
//genrally (not fast)
if(n%2==0)
    even
else 
    odd
//fast 5 is slower and & operation is faster
if(n&1==0)
    even
else 
    odd
12=1100 (8+4)
13=1101 (8+4+1)  only odd no in power of 2 (2^0) odd
last bit of odd no. always be set so
1101  13
   1 &
----
0001

1100  12
   1 &
----
0000
//given (n,i),check if iith bit is set or not
index 3210
n=13 (1101) i=2,ith bit is set or not,yes it is set
i=1  ,ans no
//(mask & n) if asked to check 3rd bit
index   43210   
        11001
mask    01000
---------------
        01000 !=0
3rd bit was not set 
10001
01000 &  mask
------
00000 = 0
if we are able to create a mask and do an & ,if no comes 1 means yes set, else ==0 not
if asked to check 3rd bit 1<<3
1000
if(n,1) mask will= be 1<<i or mask=(1<<i)
bool set=mask & n will be our ans
//dont do anything with n ,always create a mask,never alter the data

//Q.5 Extract the ith bit of a no.
n=13  (1101) i=3,ans =1 //similar to bit is set or not
//Q.6 Set the ith bit of a no.
//it can be st or not set
//but make sure you make the ith bit as 1
//create a mask ,it will help 
,i=2
110010                  
000100 mask and OR 
------
110110
mask=(1<<i)
n=n|mask 

//clear the ith bit
843210
110010                 
-------    i=2
110010   already cleared so nothing will change
i=4
110010 
------
100010 cleared 4th bit

110010   i=2
111011 negation
-------&
110010   
so mask= ~(1<<n)
n & mask

//remove the last set bit
110110
removed last bit
110110
again remove

n & (n-1)
13-1101 &
12-1101 ans    (8+4) ,4 will take 1 less
11-1011 &      
8- 1000 ans  
7- 0111      7=(1+2+4)
16-
15-             (1+2+4+8) 16 se niche sare power ka plus

12(12+4)     1100
11(12+(1+2)) 1011 &
             1011
8- 1000         we have to make sure 1 becomes 0,power ot 2 ,right beneth no can always be written as(1+2+4)
7-

16-1000
15-1111 (1+2+4+8)

//check if a no. is a power of 2
n   1000    (16)
n-1  111 &   (8)
---------
    0000
if(n&n-1==0) then its a power of two,else not
//count the no. of set bits in a no.
//genrall O()
14 -1110  print=3(set bits)
while(n!=0){
    if(n&1==1)
    cnt++;
    n=n>>1; //right shift
}
print (cnt);
//
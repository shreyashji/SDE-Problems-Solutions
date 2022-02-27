^               &          |              <<      >>      ~
EVEN 1->0   ALL 1_>1    ANY 1->1        x2^i    /2^i    0->1,1->0
ODD 1->1    ANY 0->0    ANY 0->0

//set a bit 
n | (1<<i)

//check if bit is set or not
n & (1<<i)

//every integer appears twice
//two integer appear once
a[]={1,1,2,5,3,2,3,4,7,4}  ,5&7
//brute force  O(n^2)
for(i=0;i<n;i++){
    cnt=0;
    for(j=0;j<i;j++)
    if(a[i]==a[j]) cnt++;
}
if (cnt==1) print(a[i]);
}
//using map stl O(n log n)
map<int,int> mpp;
for(i=0;i<n;i++){ //o(n)
    mpp[a[i]]++; //o(log n)
}
for(auto it : mpp){
    if(it.second==1)
    print(it.first)
}
//most optimal solution
a[]={1,1,2,5,3,2,3,4,7,4}
XOR = 5^7=2 (ALL OTHER WILL GET CANCEL)
210
---
101
111
---- ^
010 xor (differing in bits )
xor=0
for(i=0 to n)
xor=xor^a[i]
//we want index of rightmost bit
cnt=0 //want differ bit,co we want to reduce the complexity,if find the rightmost bit will take lesser time
while(xor){  //xor=2
    if(xor&1)  //010&1=000 (unset), 001&1=001 break
    break; //doing a break as soon as we find it
    cnt++  //1
    xor=xor>>1; //010->001  right shift
}
xor1=0,xor2=0
for(i=0 to n){
    if(a[i]&(1<<cnt)) //if the 1st bit is set or not
    xor1=xor1^a[i];
    else 
    xor2=xor2^a[i];
}
print(xor1) print(xor2)
//o(n),space O(1)

//Q.given n integers,print the XOR of all subsets
arr[]={1,3,2}
{}                     0
{1}     xor of this is 1
{2}                    3 
{3}                    2
{1,3}                  2
{1,2}                  3
{2,3}                  1
{1,2,3}                0
--------------------------
                       0
//ANS WILL ALWAYS BE 0
XOR OF EVERY ONE,WHAT is the occurence of every element
every no is appearing even no. of times,every one is even no. 

//genrate all the subsets,power set algo (2^n*n),only applicable when n~16,17,18
arr[]={1,3,2},n=3 ,2^3 =8 subsets
for(arr=0 -> (1<<n)-1){
    ds=[];
}
for(bit=0->n-1){
    if(num&(1<<bit))
    ds.add(a[bit]);
}
for(auto it:ds) 
    print(it);

//bit masking (competitive coder)Dynamic programming
design a set data structure which gives addition of elements(log n),removal of elements(logn),print all elements in ascending order
0<=x<=60 //constraints
in set o(log n ) time complexity
want to do in O(1)
long long x=0 (computer store 64 bit)
add(5) -> (x^(1<<5)) x=32   (0000...100000)
add(1) -> (x^(1<<1)) x=33    (0000...100001)
add(5) -> (x^(1<<5)) x=33 set only store one occurence(0000...100001)
add(3) -> (x^(1<<3)) x=41  (0000...101001)
remove(5) (x^(1<<5)) x=9 (0000...001001) //remove means xor,if exist remove,if doesnt also remove
print() -> (1,3)
//below print case
if(bits=0->60){
    if(mask or x & (1<<bit))
    print(bit)
}
add= mask | (1<<x)
remove= mask ^ ~(1<<x)
//all in O(1)time ,space O(1)
//this is called bit masking
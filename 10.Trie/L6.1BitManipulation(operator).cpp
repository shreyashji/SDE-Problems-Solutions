#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
/* doesnt matter how many no. are given
& operator a=5 ,b=6 (all 1->1 ,any 0->0) 
101
110 &
----
100 
a=5,b=7,c=8
0101
0111
1000
----
0000
*/
/*
OR operator  a=5,b=7 (any 1->1,all 0->0)
101
111
----
111
*/
/*
XOR operator -> ^   
even 1 -> 0 (XOR property)
odd 1 -> 1  (XOR property)
a=5,b=7
101
111 ^
----
010
a=5,b=5
101
101 ^  (xor of same no ,value will be 0)
----
000
*/
/*
Negation operator (flip the bit) 1->0,0->1
*/

/*
right shift  >> operator  a=5 (101) base2
a>>1  (last 1 bit will go off)  -> (10)base2 means (2)(shift to the right side after removing)
a=10 >>3 
(1010) >>3 ---> (0001) (means 1) 10/2=5/2=2/2=1 (division of 2 happens thrice here)
( >> number of times)  == decimal/2^number
*/
/*
Left shift operator << 
int(32 bits) a=5 (0000....0101)base 2
5<<2 (move by 2 places to the left side) (5*2^2)
(10100) base 2
(2^31)int a=(5*2^50) overflow
*/

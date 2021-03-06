/*
source :vide explanation: https://www.youtube.com/watch?v=59VkIo4Pk3Y
Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order. 
Merge them in sorted order without using any extra space. 
Modify arr1 so that it contains the first N elements and modify arr2 so that it contains the last M elements.
 
Example 1:

Input: 
n = 4, arr1[] = [1 3 5 7] 
m = 5, arr2[] = [0 2 6 8 9]
Output: 
arr1[] = [0 1 2 3]
arr2[] = [5 6 7 8 9]
Explanation:
After merging the two 
non-decreasing arrays, we get, 
0 1 2 3 5 6 7 8 9.
Example 2:

Input: 
n = 2, arr1[] = [10, 12] 
m = 3, arr2[] = [5 18 20]
Output: 
arr1[] = [5 10]
arr2[] = [12 18 20]
Explanation:
After merging two sorted arrays 
we get 5 10 12 18 20.

*/

#include<bits/stdc++.h>
using namespace std;
//time = O(n*m)
//space= O(1)
class Solution{
public:
void merge(long long arr1[], long long arr2[], int n, int m) {  
        int i =n-1;
        int j=0;
        while(i>=0 && j<m){
            if(arr1[i]>=arr2[j]){
                swap(arr1[i],arr2[j]);
                i--;j++;
            }
            else{
                break;
            }
        }
        sort(arr1,arr1+n);
        sort(arr2,arr2+m);
        }
    }
};

int ar1[] = { 1, 5, 9, 10, 15, 20 };
int ar2[] = { 2, 3, 8, 13 };
int m = sizeof(ar1) / sizeof(ar1[0]);
int n = sizeof(ar2) / sizeof(ar2[0]);
merge(ar1, ar2, m, n);
After Merging 
First Array: 1 2 3 5 8 9 
Second Array: 10 13 15 20 
#include<bits/stdc++.h>
using namespace std;
//time= O(log(min(n,m)))
//space=O(1)
int kthelement(int arr1[], int arr2[], int m, int n, int k) {
    if(m > n) {//do the reverse,always do the binary search on smallest one
        return kthelement(arr2, arr1, n, m, k); 
    }
        
    int low = max(0,k-m), high = min(k,n); //edge case
        
    while(low <= high) {
        int cut1 = (low + high) >> 1; 
        int cut2 = k - cut1; 
        int l1 = cut1 == 0 ? INT_MIN : arr1[cut1 - 1]; 
        int l2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1];
        int r1 = cut1 == n ? INT_MAX : arr1[cut1]; 
        int r2 = cut2 == m ? INT_MAX : arr2[cut2]; 
            
        if(l1 <= r2 && l2 <= r1) { //if valid condition
            return max(l1, l2);
        }
        else if (l1 > r2) { //if not valid condition,i have to reduce elements,we have to make it smaller element
            high = cut1 - 1;//move to left
        }
        else {
            low = cut1 + 1; //have to increase element,move to the right
        }
    }
    return 1; 
}
int main() {
    int array1[] = {2,3,6,7,9};
    int array2[] = {1,4,8,10};
    int m = sizeof(array1)/sizeof(array1[0]);
    int n = sizeof(array2)/sizeof(array2[0]);
    int k = 5;
    cout<<"The element at the kth position in the final sorted array is "
    <<kthelement(array1,array2,m,n,k);
    return 0;
}
/*
for [8,4,2,1] =  i<j , a[i] >a[j]
(8,4) ,(8,2) ,(8,1)
(4,2),(4,1)
(2,1)
total is 6 ans
left should be greater than right
brute force lineraly traverse stand i on 8 and linerly traverse& check how many is smaller than i and 
put a counter becomes 3,i on 4 counter becomes 5,i on 2 counter becomes 6
time =O(n^2) n-1 iteration for 1st,2nd,3rd and so on
space=O(1)
so to optimize it using merge sort technique
merge sort  is  break in half until all of thenm reach a single element

*/
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int merge(int arr[],int temp[],int left,int mid,int right){
    //left arr[] is [left,mid-1] and
    int i,j,k;
    int inv_count=0;
     
    i=right; /*i is index for left subarray*/ //i = right
    j=mid; /*j is index for right subarray*/  //starting point of second array
    k=left; /* k is index for resultant merged subarray*/
    //can keep k=0 ialso, it is for merging it to temp array
    while((i<= mid -1) && (j <=right)){
        //checking if left is smaller than right
        if(arr[i] <= arr[j]){
            temp[k++]= arr[i++]; //copying it
        }
        //but if it is greater 
        else{
            temp[k++] =arr[j++];
            /*this is tricky --see above 
            explanation/diagram for merge()*/
            inv_count= inv_count + (mid-i);
        }
    }
    while(i <= mid-1){ /*if right pointer
    exceeds while copying,simply copy everything on left array*/
        temp[k++] = arr[i++];
    /*if left pointer
    exceeds while copying,simply copy everything on right array*/
    while (j<= right)
        temp[k++] = arr[j++];
    }
    //once we do this temp arry will have stored  sorted arry of left and right arr[]
    //we simply copy back to original array
    for(i =left ; i<= right; i++)
        arr[i] =temp[i];
        
    return inv_count;
}
//instead of this inv_count variable we can use global variable
// or refrence variable at the function
//in interview global varibale are not preferred
// low as left, high as right
int _mergeSort(int arr[],int temp[],int left,int right){
    int mid,inv_count=0;
    if(right>left){ //if not a single element we are splitting them in two halfs
        mid = (right+left)/2;
        inv_count += _mergeSort(arr,temp,left,mid);
        inv_count += _mergeSort(arr,temp,mid + 1,right);
        inv_count += merge(arr,temp,left,mid + 1,right); //our function
    }
    return inv_count;
}

int main(){
    int arr[] = {5, 3 ,2, 4, 1};
   
    int n = sizeof(arr)/ sizeof(arr[0]);
    int temp[n]; //temp array of size n
    int ans= _mergeSort(arr,temp,0,n-1); //low as 0, high as n-1
    cout<<"Number of inversions are "<<ans;
    return 0;
}
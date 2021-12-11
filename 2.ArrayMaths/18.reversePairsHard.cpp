/*class Solution {
public:
    int merge(vector<int>& nums, int low, int mid, int high){
        //low - starting point of the left half of the array
        //mid+1 - starting point of the right half of the array
        int cnt=0; //store total no. of pairs
        int j=mid+1; //take j ptrs and put it in the first index of right half that is mid+1
        //iterate i on left half , i from low to mid ,that is left half of the array
        for(i=low ; i<=mid+1; i++){
            while(j<=high && nums[i] > 2LL * nums[j]) //keep moving j ptrs to every i
                j++;
        }
        cnt += (j - (mid+1)); //count no. of elemnts in the eft,that will contribute to the no. of pairs of the ith index elemnt =no of elemnts in the left       
    }
    //till here done total no. of inversion of left half and right half of array together
    // now need to do merge function
    vector<int> temp; 
    int left = low, right=mid+1;
    //iterating till anyone get exhausted
    while(left <= mid && right <= high) {  
        if(nums[left] <= nums[right]){ 
        //if left portion is smaller ,push it into temp & inc left  ptr by 1
            temp.push_back(nums[left++]);
        }
        else{// if right half is smaller addthem to  temp ds ,and move right by one
            temp.push_back(nums[right++]);
        }
    } // till this one of the array is exhausted
    
    //if left array is left out,adding all the remaining elemnt in temp vector
    while(left<=mid){
        temp.push_back(nums[left++]);
    }
    //if right half is left  adding all the remaining elemnt in temp vector
     while(right<=high){
        temp.push_back(nums[right++]);
    }
    for(int i=low; i<=high; i++){
        nums[i]= temp[i-low];
    }
    return cnt;
}
    
    mergesort(vector<int>& nums,int low ,int high){
        if(low==high) return; //check if single element
        int mid = (low+high)/2; //compue middle
        int inv = mergeSort(nums,low,mid); //call left recursion
        inv+ = mergeSort(nums,low,mid+1); //call right recursion
        inv+ = merge(nums,low,mid,high);  //after this merge,tis will compute numbers of pairs as well as merge left sorted arr and right sorted array
        return inv;
    }
    
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums,0,nums.size()-1);
    }
};
*/
#include<bits/stdc++.h>

using namespace std;
int Merge(vector < int > & nums, int low, int mid, int high) {
  int total = 0;
  int j = mid + 1;
  for (int i = low; i <= mid; i++) {
    while (j <= high && nums[i] > 2 LL * nums[j]) {
      j++;
    }
    total += (j - (mid + 1));
  }

  vector < int > t;
  int left = low, right = mid + 1;

  while (left <= mid && right <= high) {

    if (nums[left] <= nums[right]) {
      t.push_back(nums[left++]);
    } else {
      t.push_back(nums[right++]);
    }
  }

  while (left <= mid) {
    t.push_back(nums[left++]);
  }
  while (right <= high) {
    t.push_back(nums[right++]);
  }

  for (int i = low; i <= high; i++) {
    nums[i] = t[i - low];
  }
  return total;
}
int MergeSort(vector < int > & nums, int low, int high) {

  if (low >= high) return 0;
  int mid = (low + high) / 2;
  int inv = MergeSort(nums, low, mid);
  inv += MergeSort(nums, mid + 1, high);
  inv += Merge(nums, low, mid, high);
  return inv;
}
int reversePairs(vector < int > & arr) {
  return MergeSort(arr, 0, arr.size() - 1);
}

int main() {
  vector<int> arr{1,3,2,3,1};
  cout << "The Total Reverse Pairs are " << reversePairs(arr);
}
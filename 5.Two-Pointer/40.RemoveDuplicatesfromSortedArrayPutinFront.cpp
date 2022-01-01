//naive approach 
/* 
// time = o(nlogn) traversing, insertion into set+O(n) placing elemnt in arr
//space = o(N)
//Declare a HashSet.
//Run a for loop from starting to the end.
//Put every element of the array in the set.
//Store size of the set in a variable K.
//Now put all elements of the set in the array from the starting of the array.
//Return K.
#include<bits/stdc++.h>
using namespace std;
int removeDuplicates(int arr[]) {
  set < int > set;
  for (int i = 0; i < 7; i++) {
    set.insert(arr[i]);
  }
  int k = set.size();
  int j = 0;
  for (int x: set) {
    arr[j++] = x;
  }
  return k;
}
int main() {
  int arr[] = {1,1,2,2,2,3,3};
  int k = removeDuplicates(arr);
  cout << "The array after removing duplicate elements is " << endl;
  for (int i = 0; i < k; i++) {
    cout << arr[i] << " ";
  }
}

*/
//time =O(n) just traversing
//space =O(1)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0)
        return 0;
        
        int i=0; //at first index
        //two pointer i & j initialized to 1
        
            for(int j=1;j<nums.size();j++){
                if(nums[j] != nums[i]) { //looking for elemnt which is different then i
                    i++; //if different move i pointer
                    nums[i]=nums[j]; //take that elemnt of j and put it in i
                }
            }
        //all unique elements at the right or front
        return i+1;
    }
};
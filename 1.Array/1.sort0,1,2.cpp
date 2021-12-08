#include<bits/stdc++.h>
using namespace std;

class Solution {
public :
//time= O(n)
//space= O(1)
    void sortColors(vector<int>& nums){
        int lo=0;
        int hi=nums.size()-1;
        int mid=0;
        while(mid <=1) { //till mid doest crosses the high pointer
          //switch checks the element is 0,1,2
            switch (nums[mid]){

            //if elements is 0
            case 0:
                swap(nums[lo++],nums[mid++]);
                break;
            //if the element is 1
            case 1:
                mid++;
                break;
            //if the element i 2
            case 2:
            swap(nums[mid],nums[hi--]);
            break;
            }
        }
    }
}
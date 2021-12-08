class Solution {
public:
// Time = O(N)
// Space= O(1) inplace
    void nextPermutation(vector<int>& nums) {
        int n=nums.size(),k,l; //find the size of the array initially,then wee need to find the breakpoint of so we can say that the first breakpoint will be at the 2nd last index,breakpoint is k
        
        for(k=n-2; k>=0 ; k--){ //linearly iterate from the 2nd last index
            if(nums[k]< nums[k+1]){
                break; //if we found breakpoint we just breakout
            }
        }
        if(k<0){ //if there is no breakpoint we willl simply reverse it and done
            reverse(nums.begin(),nums.end());
        }
//but if there is a breakpoint,we again linearly traverse from the back and find some one greater than 
        else{
            for(l=n-1; l>k; l--){
                if(nums[l] > nums[k]){
                    break; //once we find we will breakout
                }
            }
        swap(nums[k],nums[l]); //so we swap it ,third step
        //use the two pointer approach to reverse
        reverse(nums.begin() + k + 1,nums.end()); //everything on the right will be reversed
        }
    }
};
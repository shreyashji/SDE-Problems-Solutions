class Solution {
public:
//time =O(log(n))
//space=O(1)
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size() - 2;
            while (low <= high) {
                int mid = (low + high)>>1;
                if(nums[mid] == nums[mid^1]){//this is going to give  previous even or next odd
                    low=mid+1;//if on the left half,shrink the left half
                }
                else{
                    high= mid-1;//if on the right half ,shrink the right half
                }
            }
        return nums[low];
    }
};
//in order to check for the left half
//1st instance ->even index
//2nd instance->odd index,i need to check on the left,if the 1st instance of that number is there or not
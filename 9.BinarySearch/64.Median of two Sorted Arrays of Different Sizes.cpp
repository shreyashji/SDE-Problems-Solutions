class Solution {
public:
    //time= log base 2(min(n1,n2)) We are applying binary search on the array which has a minimum size.
    //space= O(1)
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size() < nums1.size()) return findMedianSortedArrays(nums2, nums1);
        int n1 = nums1.size();
        int n2 = nums2.size(); 
        int low = 0, high = n1;
        
        while(low <= high) {//binary search
            int cut1 = (low+high) >> 1;
            int cut2 = (n1 + n2 + 1) / 2 - cut1; 
            
            //edge cases 
            int left1 = cut1 == 0 ? INT_MIN : nums1[cut1-1];//if not taking anything from left or first arr
            int left2 = cut2 == 0 ? INT_MIN : nums2[cut2-1];// if not taking anything from left or 2nd arr
            
            int right1 = cut1 == n1 ? INT_MAX : nums1[cut1];//taking all the elements from arr1
            int right2 = cut2 == n2 ? INT_MAX : nums2[cut2]; //taking all the elements from arr2
            
            //cross check happedn here l1 r2, l2 r1,if true we have valid cut
            if(left1 <= right2 && left2 <= right1) {
                if( (n1 + n2) % 2 == 0 ) 
                    return (max(left1, left2) + min(right1, right2)) / 2.0; //median formula,if even length
                else 
                    return max(left1, left2); //if length odd
            }
            //if not valid one
            else if(left1 > right2) {
                high = cut1 - 1; //reduce it to move high to left or mid-1 
            }
            else {
                low = cut1 + 1; //or low to mid +1
            }
        }
        return 0.0; 
    }
};
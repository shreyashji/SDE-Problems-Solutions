class Solution {
public:
    //time = o(log n)
    //space= O(1)
    int search(vector<int>& a, int target) {
        int low = 0, high = a.size() - 1; 
        while(low <= high) { //iterate till low <is lesser than equal to high (binary search)
            int mid = (low + high) >> 1; //find mid
            if(a[mid] == target) return mid; //check if it is equal to target
            
            // the left side is sorted
            if(a[low] <= a[mid]) {
                //figure out if element lies on the left half or not
                if(target >= a[low] && target <= a[mid]) { //eliminate the right  half
                    high = mid - 1; //move the high to mid-1
                }
                else {
                    low = mid + 1; ///eliminate the left  half
                }
            }
            //right half is sorted
            else {
                //target appears on the right half
                if(target >= a[mid] && target <= a[high]) {
                    low = mid + 1; //left half to be eliminated
                }
                else {
                    high = mid - 1; //if doesnt ,eliminate the right half 
                }
            }
        } 
        return -1; 
    }
};
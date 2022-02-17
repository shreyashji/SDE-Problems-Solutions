
//time= log base 2 (2^32) (binary search) * N (for every row) * log base2 M (implementing binary search on col length)
//  32 * N * log base2 M
//space =passing array[i] no external space O(1)
int countSmallerThanEqualToMid(vector<int> &row, int mid) {
    //shrink the search space
    int l = 0, h = row.size() - 1; 
    while(l <= h) {
        int md = (l + h) >> 1; //get the middle
        if(row[md] <= mid) { //this guy lesser than equal to middle
            l = md + 1;
        }
        else {
            h = md - 1;
        }
    }
    return l;  //low will be ans
}
int Solution::findMedian(vector<vector<int> > &A) {
    int low = INT_MIN;
    int high = INT_MAX; //1e9 10^9 search space
    int n = A.size();
    int m = A[0].size(); 
    while(low <= high) { //binarys search
        int mid = (low + high) >> 1; 
        int cnt = 0; // <=mid
        for(int i = 0;i<n;i++) {
            cnt += countSmallerThanEqualToMid(A[i], mid); //function to count,cevery row passed on to this function
        }
        
        if(cnt <= (n * m) / 2) low = mid + 1;  //count is lesser move to right
        else high = mid - 1; 
    }
    return low; 
}
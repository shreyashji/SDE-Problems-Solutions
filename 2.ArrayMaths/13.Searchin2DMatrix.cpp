//integer in each row are in sorted order
//The first integer of each row is greater than the last integer of the previous row.
//ask interviewer 
//row wise and column wise sorted
//ask interviewer  if first element of column exceeds the last elemnt of the previous row or not

//first approach to do linear search in n*m matrix and search target elemnt and return if exist
//t(n) =O(n*m) ,space = O(1)
//2nd approach will be based on property rows are sorted ,worked on both leetcode and gfg problem
/*
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int j=m-1;
        int i=0;
        while(i<n && j>=0){
            if(mat[i][j]==x){
                cout<<"n found at"<<i <<", "<<j;
                return 1;
            }
            if(mat[i][j]>x)
                j--;
            else
                i++;
        }
*/
//t(n)= log base 2 (n*m)
//space = O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       if(!matrix.size()) return false;
        int n=matrix.size();  //compute size of rows 
        int m= matrix[0].size();//compute size of cols
        //need to perform an imaginary binary search
        int lo=0; //
        int hi=(n*m)-1; //imaginary last index
        //do a binary search 
        while(lo <= hi ){//if true we find the value of middle
            int mid=(lo + (hi-lo) /2 );  //middle is imaginary index so we have to find corresponding row & coln index
            if(matrix[mid / m][mid % m] == target){ //mid/col no
                return true;
            }
            if(matrix[mid / m][mid % m] < target){ //doing binary search on right half
                lo= mid+1;
            }
            else{//doing binary search on left half
                hi=mid-1;
            }
        }
        return false;
    }
};
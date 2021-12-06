class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size(); //compute size of matrix
        //to transpose we use this kind of looping structure
        for(int i=0; i<n ; i++)  //loop for every row
            for(int j=0; j<i; j++) //for every row just loop from 0 to i
                swap(matrix[i][j], matrix[j][i]);
                
                for(int i=0; i<n; i++) //linearly traverse for every row
                    reverse(matrix[i].begin(),matrix[i].end()); //and reverse every row
              
    }
};
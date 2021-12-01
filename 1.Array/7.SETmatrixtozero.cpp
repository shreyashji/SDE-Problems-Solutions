class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) { //2d matrix
    //calculate no. of rows
    //calculate any of the rows and calulate row size
    //col0 variable initially initilize to 1 true
    int col0 = 1, rows = matrix.size(), cols = matrix[0].size();

    for (int i = 0; i < rows; i++) {
        //value at any of the 0th colns of any of the given row i is 0
        //in that case i set col0 to false or 0 
        if (matrix[i][0] == 0) col0 = 0; 
        //and then i traverse rest of the colns that starts from 1
        for (int j = 1; j < cols; j++)
        //and if that is set to 0
            if (matrix[i][j] == 0)
            //i know, have to set the leftmost as 0 and topmost as 0
           /*leftmost*/     matrix[i][0] = matrix[0][j] = 0;/*rightmost*/ 
    //once i have done the above 
    }
   //we will linearly traverse from backwards
    for (int i = rows - 1; i >= 0; i--) {
        for (int j = cols - 1; j >= 1; j--) //for backwards
        //and i check if the dummy value is 0 at any of the given index
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
            //if it is  i set it as i of j =0
                matrix[i][j] = 0;
            //if col0 is false  or 0  if is is 
            //i am assured 0th col would set to 0
            //coz 0 or flase means col0 is set to 0
        if (col0 == 0) matrix[i][0] = 0;
        //we dont need to return anything coz it is pass by refrence
    }
    }
};
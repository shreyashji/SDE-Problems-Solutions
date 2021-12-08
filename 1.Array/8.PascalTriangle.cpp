class Solution {
public:
//Time = O(N)
//space = O(N)
    vector<vector<int>> generate(int numRows) {
    vector<vector<int>> r(numRows);// create n dynamic vector which will be empty after that
    // we know we have to genrate n rows
    for(int i=0; i<numRows; i++){
    r[i].resize(i+1);// no colns will always equal to the no. of rows,resizing empty vector to i+1
    r[i][0]= r[i][i]=1; //first and last element will be 1 so we just initialised it
            
    //linearly traverse from first coln to the 2nd last colnj<i so 2 & 1 getting added
    for(int j=1; j<i; j++)
    r[i][j]=r[i-1][j-1]+r[i-1][j];
        
    }
    //after entire addition return pascal triangle 2d vector
    return r;    
    }
};
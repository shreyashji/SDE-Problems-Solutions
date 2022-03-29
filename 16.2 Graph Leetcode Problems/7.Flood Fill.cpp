//https://leetcode.com/problems/flood-fill/submissions/
//https://www.youtube.com/watch?v=7aikf56h9Gs&list=PLzjZaW71kMwSrxEtvK5uQnfNQ9UjGGzA-&index=10

class Solution {
public:
    //fill given color=1 (with given i,j) on interconnected nodes
    //move to only specified color if found the exact color marked with new color
    bool isValid(vector<vector<int>>& image, int i, int j, int n, int m , int color){//to check for out of boundry
        if(i>=0 && i<n && j>=0 && j<m && image[i][j] == color)
            return true;
        
        return false;
    }
    
    void floodFillRec(vector<vector<int>>& image, int i, int j, int n, int m , int color, int newColor){   
        image[i][j] = newColor;
        
        if(isValid(image, i+1, j, n, m , color))//for right
            floodFillRec(image, i+1, j, n, m , color, newColor);
        
        if(isValid(image, i-1, j, n, m , color)) //for left
            floodFillRec(image, i-1, j, n, m , color, newColor);
        
        if(isValid(image, i, j+1, n, m , color)) //for upward
            floodFillRec(image, i, j+1, n, m , color, newColor);
        
        if(isValid(image, i, j-1, n, m , color)) //for below
            floodFillRec(image, i, j-1, n, m , color, newColor);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size();
        int m = image[0].size();
        
        int color = image[sr][sc];//src row,src column
        
        if(color == newColor)//to avoid visited we use this,can also use visited
            return image;//to avaoid full dfs call
        
        floodFillRec(image, sr, sc, n, m, color, newColor);
        
        return image;
    }     
};
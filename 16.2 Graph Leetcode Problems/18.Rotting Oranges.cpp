// https://leetcode.com/problems/rotting-oranges/
/*
case 2
222
022  t=-1 we need to rotten all oranges
102

case 3
02 no fresh exist t=0
20 
    
*/
class Solution {
public:
    bool isValid(int i, int j, int n, int m, vector<vector<int>>& grid){
        if(i>=0 && i<n && j>=0 && j<m && grid[i][j] == 1){//want to go to fresh oranges
            return true;
        }
        return false;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int fresh = 0, time = 0;//answer
        queue<pair<int, int>>q; //pushing i,j
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){//if rotten push to q
                    // push into queue
                    q.push({i, j});//indicating rotten oranges position
                }
                else if(grid[i][j] == 1){//if fresh exist
                    fresh++;
                }
            }
        }
        if(fresh == 0) return 0; //no fresh oranges 0 time will be needed base case
        
        // start BFS traversal
        while(!q.empty()){
            
            int size_q = q.size();
            int temp = 0;
            while(size_q != 0){
                
                pair<int, int>p = q.front(); ///pop from queue
                q.pop();
                
                int x1 = p.first;
                int y1 = p.second;
                //now we will start traversing its adjacent,new way
                int ax[4] = { 1, -1, 0, 0};
                int ay[4] = { 0, 0 , 1 , -1};
                
                for(int i=0; i<4; i++){
                    int x = ax[i] + x1;
                    int y = ay[i] + y1;
                    
                    if(isValid(x, y, n, m, grid)){
                        temp++;
                        grid[x][y] = 2;//after rotten put 2 which inidcates rottenn
                        q.push({x, y}); //push rotten elemnet to queue
                    }
                }
                size_q--;  
            }
            if(temp != 0) time++;//means some oranges got rotten
        }
        
        // we checked if any fresh oranges are still there || case no 2
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){ //if found any one in last break,menas after doing bfs ,we have still fresh ornages
                    time = 0;
                    break;
                }
            }
        }
        return (time == 0) ? -1 : time ;  
    }
};
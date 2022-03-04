#include<bits/stdc++.h>
using namespace std;
//time = O( n x n ) x 4 direction loop
//Worst-case – We will be making each fresh orange rotten in the grid and for each rotten orange will check in 4 directions    
//space= O ( n x n )
// worst-case –  If all oranges are Rotten, we will end up pushing all rotten oranges into the Queue data structure
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty()) return 0; //if empty vector return o
        int m = grid.size(), n = grid[0].size(), days = 0, tot = 0, cnt = 0;//cnt=rottten by me,tot=no. of oranges given to us
        queue<pair<int, int>> rotten;
        for(int i = 0; i < m; ++i){ //iterate on 2d matrix
            for(int j = 0; j < n; ++j){
                if(grid[i][j] != 0) tot++;//how many oranges are non empty
                if(grid[i][j] == 2) rotten.push({i, j});//how many are rotten
            }
        }
        
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        //(0,1)rightward direction,(0,-1)leftward direction,(1,0)downward direction,(-1,0)upward direction,
        while(!rotten.empty()){//bfs iteration ,till queue rooten is not empty
            int k = rotten.size();
            cnt += k; //2+2+2 i.e
            while(k--){ //while loop run on queue elements
                int x = rotten.front().first, y = rotten.front().second;
                rotten.pop();
                for(int i = 0; i < 4; ++i){
                    int nx = x + dx[i], ny = y + dy[i];//add 
                    //are this inside my boundry,if its a rotten orange or empty continue
                    if(nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != 1) continue;
                    grid[nx][ny] = 2;//if not mark it as rotten
                    rotten.push({nx, ny});
                }
            }
            if(!rotten.empty()) days++;//if rotten someone queue will contain sommething,inc days++
        }//till rotten oranges exist
        
        return tot == cnt ? days : -1;
    }

    int main()
    {
        vector<vector<int>> v{ {2,1,1} , {1,1,0} , {0,1,1} } ;
        int rotting = orangesRotting(v);
        cout<<"Minimum Number of Minutes Required "<<rotting<<endl;
        
    }
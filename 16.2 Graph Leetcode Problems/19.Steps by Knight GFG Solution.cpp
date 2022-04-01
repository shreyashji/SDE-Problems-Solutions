//https://www.youtube.com/watch?v=XhYVY6PQSxs&list=PLzjZaW71kMwSrxEtvK5uQnfNQ9UjGGzA-&index=25

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    //8 possibilities
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    bool isValid(int i, int j, int n, vector<vector<bool>>&visited){ //to check for out of board
        if(i>=0 && i<n && j>=0 && j<n && visited[i][j] == false){//aslo not visited
            return true;
        }
        return false;
    }
    
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    int n = N;
	    int tx = TargetPos[0]-1, ty = TargetPos[1]-1;//-1 for 0 based indexing ,x y index
	    int x1 = KnightPos[0]-1, y1 = KnightPos[1]-1;//x,y axis index
	    
	    if(x1 == tx && y1 == ty) return 0;
	    
	    vector<vector<bool>>visited(n, vector<bool>(n, false));
	    
	    queue<pair<int, int>>q;
	    q.push({x1, y1}); //starting knigh position push it to queue
	    visited[x1][y1] = true;//visted 7 pushed to queue
	    
	    int ans = 0;
	    while(!q.empty()){
	        
	        int size = q.size();
	        ans++; //for cnt how much bfs call happeining 
	        while(size != 0){
	            pair<int,int>p = q.front();
	            q.pop();
	            
	            int xx = p.first;
	            int yy = p.second;
	            //total 8 position
	            int ax[8] = {1, 1, -1, -1, 2, -2, 2, -2};
	            int ay[8] = {2, -2, 2, -2, 1, 1, -1, -1};
	            
	            for(int i=0; i<8; i++){
	                int nx = xx + ax[i];
	                int ny = yy + ay[i];
	                
	                if(nx == tx && ny == ty) return ans;//check if new postion is target
	                
	                if(isValid(nx, ny, n, visited)){
	                    visited[nx][ny] = true;
	                    q.push({nx, ny});
	                }
	            }
	            size--;
	        }
	    }
	   return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
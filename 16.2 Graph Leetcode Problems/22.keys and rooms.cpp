//https://leetcode.com/problems/keys-and-rooms/
//https://www.youtube.com/watch?v=IRZuPwau_M8&list=PLzjZaW71kMwSrxEtvK5uQnfNQ9UjGGzA-&index=30

class Solution {
public:
    //n is size of array of rooms,rooms array store index no. of other 
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool>visited(n, false);
        
        queue<int>q; //store key
        q.push(0);//satrting key
        visited[0] = true;
        
        while(!q.empty()){
            int room = q.front();
            q.pop();
            
            for(auto key : rooms[room]){ //room me jitni bhi keys h unko check karlo
                if(!visited[key]){ //if key is not visited
                    visited[key] = true; //
                    q.push(key); //push into queue
                }
            }
        }
               
        for(auto x: visited){
            if(!x) //if there is false return false x==false
                return x;
        }
        return true;
    }
};
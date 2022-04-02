// https://leetcode.com/problems/time-needed-to-inform-all-employees/
// https://www.youtube.com/watch?v=qjDoGPZPIjc&list=PLzjZaW71kMwSrxEtvK5uQnfNQ9UjGGzA-&index=32
// 

class Solution {
public:
/*
    adjacency list
    -1->[]nulll
    0->
*/
    unordered_map<int, vector<int>>umap;  //globally
    int ans =0 , mx= 0;
    
    void dfs(int manager, vector<int>& informTime){//srcc or manager
        mx = max(mx, ans);
        for(auto employee : umap[manager]){//manger apne employee ko call karega
            ans += informTime[manager];  //inform manger kar raha h to mnger ka inform time
            
            dfs(employee, informTime);//employee bhi manger hoga kisi aur ke lia,emp as manger,
            
            ans -= informTime[manager];//backtrack
        }
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
         // Fill umap
        for(int i=0; i<n; i++){
            int val = manager[i];
            if(val != -1){
                umap[val].push_back(i);
            }
        }
        
        dfs(headID, informTime);
        return mx;
    }
};
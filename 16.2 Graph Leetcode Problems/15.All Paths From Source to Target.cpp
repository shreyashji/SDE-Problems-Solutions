class Solution {
public:
    //o to n-1
    //path nam ka vector
    //dfs traversal of graph dfs(0)->dfs(1)->dfs(2) stored in path store in ans now pop 1,2 || 0 can go to 2 //then 3 store in path insertin ans ,then pop 3,2,0 end
      
    void dfs(vector<vector<int>>& graph, vector<vector<int>>& ans, vector<int>&path, int curr){    
        path.push_back(curr); //src is curnvertex
        
        if(curr == graph.size()-1){ //means src to target directly,means crn tvertex jana chahte h wahi mil agaya to push
            ans.push_back(path); //path mil gaya
        }
          
        else{ //if not then traverse its adjacent nodes
            for(auto x: graph[curr]){
                dfs(graph, ans, path, x);//x jo pass ho raha h
            }
        }
          
        path.pop_back();//agar nahi raha to pop from path,ans mil jata to pop from path
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int>path; //will store path, new path evert time store when dfs call
        
        dfs(graph, ans, path, 0);
        return ans;
    }
};
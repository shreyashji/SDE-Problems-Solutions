class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    //time=O(n) genralized
    //space=O(n) genralized
    // can i use recursion in this problem
    vector<int> topView(Node *root)
    {
        vector<int> ans;  //storing top view here
        if(root == NULL) return ans; //tree empty return empty
        map<int,int> mpp; //declare map
        queue<pair<Node*, int>> q; //declare queue
        q.push({root, 0}); //root and line initially 0 
        while(!q.empty()) {//traverse till  q is not empty
            auto it = q.front();  //get top most nodes
            q.pop(); 
            Node* node = it.first; 
            int line = it.second;  //get the line no
            if(mpp.find(line) == mpp.end()) mpp[line] = node->data; //make sure it doesnt exist in map,
            //if doesnt exist,,then initilaize node on that map
            
            if(node->left != NULL) { //take whatever on left,enter in queue with line-1 if left
                q.push({node->left, line-1}); 
            }
            if(node->right != NULL) {//take whatever on right,enter in queue with line+1 if right
                q.push({node->right, line + 1}); 
            }
            
        }
        
        for(auto it : mpp) { //iterate on map
            ans.push_back(it.second);  //push into ans ds
        }
        return ans; 
    }

};
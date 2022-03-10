class Solution {
  public:
  //recursive way will not work,this is iterative
  //time= O(n) level order traversal
  //space= O(n)
    vector <int> bottomView(Node *root) {
        vector<int> ans; //store bottom view
        if(root == NULL) return ans; 
        map<int,int> mpp; 
        queue<pair<Node*, int>> q; //store (root & line)
        q.push({root, 0}); //store (line & node)
        while(!q.empty()) {//level order traversal
            auto it = q.front(); 
            q.pop(); 
            Node* node = it.first; 
            int line = it.second; 
            mpp[line] = node->data; //get the line
            
            if(node->left != NULL) {
                q.push({node->left, line-1}); 
            }
            if(node->right != NULL) {
                q.push({node->right, line + 1}); 
            }
            
        }
        //iterate on map
        for(auto it : mpp) {
            ans.push_back(it.second); //second means value
        }
        return ans;  
    }
};
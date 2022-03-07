/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    //tc=O(n) for nodes
    //space= O(n) queue going to store n nodes in worst case,we are returning ans ds so we dont count it
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;  //store level wise traversal
        if(root == NULL) return ans;  //if tree empty ,return empty ds
        queue<TreeNode*> q; //defined q ds
        q.push(root);  //push root
        while(!q.empty()) {
            int size = q.size(); //take the size of 1st element in queue in first iteration,1,23,4567
            vector<int> level; 
            for(int i = 0;i<size;i++) { //traverse for size
                TreeNode *node = q.front(); //node=2 3 ,4 5 6 7
                q.pop(); //taking the node & poping it out
                if(node->left != NULL) q.push(node->left);  //if exist a left push it in queue
                if(node->right != NULL) q.push(node->right);  //if exist a right push it in queue
                level.push_back(node->val); //storing that node in vector
            }
            ans.push_back(level); //tale vector level and put it in ans
        }
        return ans; 
    }
};
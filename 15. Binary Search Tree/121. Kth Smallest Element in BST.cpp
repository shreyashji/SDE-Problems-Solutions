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
//time  = O(N) morris traversal
//space= O(1)
      int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st; 
        TreeNode* node = root;
        int cnt = 0; 
        while(true) {
            if(node != NULL) {
                st.push(node); 
                node = node->left; 
            }
            else {
    
                if(st.empty() == true) break; 
                node = st.top(); 
                st.pop(); 
                // inorder.push_back(node->val);
                cnt++; 
                if(cnt == k) return node->val; 
                node = node->right; 
            }  
        }
        return -1;
    }
};
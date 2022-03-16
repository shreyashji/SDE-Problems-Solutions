/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
 //time =O(H) height of tree bst
//space = O(1) , not considering stack space
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
         if(!root) return NULL;
        int curr = root->val; 
        if(curr < p->val && curr < q->val) {//to both of them lie on right
            return lowestCommonAncestor(root->right, p, q);//go to right
        }
        if(curr > p->val && curr > q->val) {//to both of them lie on left
            return lowestCommonAncestor(root->left, p, q);//go to left
        }
        return root;//cant determine both on left or on right ,return rooot coz this is the first point that will be ans
    }
};
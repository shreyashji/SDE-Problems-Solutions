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
     bool f(TreeNode *root1, TreeNode* root2) {
        if(!root1) return !root2;
        if(!root2) return !root1;
        return (root1->val == root2->val) && f(root1->left, root2->right) && f(root1->right, root2->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return f(root->left, root->right);
    }
};
/*
//time=O(N)
//space=O(N) worst case if skew tree ,stack space O(N)
public:
    bool isSymmetric(TreeNode* root) {
      return root==NULL || isSymmetricHelp(root->left,root->right);//two subtrees got o left & right
    }
    bool isSymmetric(TreeNode* root) { //start traversal
        if(left==NULL || right==NULL)
            return left==right; //boyh are null okay return true
        if (left.val!=right.val) return false; //if node value not sae return false
        //go left & right simultaneously
        //if any of this not matching return false 
        return isSymmetricHelp(left.left,right.right) 
            &&
                isSymmetricHelp(left.right,right.left) ;        
    }
};
*/
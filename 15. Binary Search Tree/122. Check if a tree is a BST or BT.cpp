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
//time= O(n)
//space = O(1),auxilary stack space
    bool isValid(TreeNode* root , double minVal, double maxVal){
        if(root==NULL) return true;
        if(root->val>= maxVal || root->val <= minVal) return false;
        return isValid(root->left , minVal , root->val) && isValid(root->right , root->val , maxVal);
    }
    bool isValidBST(TreeNode* root) {
        double infinity = numeric_limits<double>::infinity();
        double minusInfinity = -numeric_limits<double>::infinity();
            return isValid(root , minusInfinity , infinity);
    }
};

/*
//time= O(n)
//space = O(1),auxilary stack space
class Solution {
    public boolean isValidBST(TreeNode root) {
        return isValidBST(root, Long.MIN_VALUE, Long.MAX_VALUE);
    }
    
    public boolean isValidBST(TreeNode root, long minVal, long maxVal) {
        if (root == null) return true;
        if (root.val >= maxVal || root.val <= minVal) return false;
        return isValidBST(root.left, minVal, root.val) && isValidBST(root.right, root.val, maxVal);
    }
}

*/
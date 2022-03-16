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
    //time = O(log base 2 N) height of tree
    //space = O(1)
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) {
            return NULL;
        }
        if (root->val == key) {//if we have to delet root
            return helper(root);
        }
        TreeNode *dummy = root;//store root coz it will destroy when traversed
        while (root != NULL) {
            if (root->val > key) {
                if (root->left != NULL && root->left->val == key) {
                    root->left = helper(root->left); //when find the node ,helper function make sure connection are made in proper way
                    break;
                } else {
                    root = root->left;
                }
            } else { //
                if (root->right != NULL && root->right->val == key) {
                    root->right = helper(root->right);
                    break;
                } else {
                    root = root->right;
                }
            }
        }
        return dummy;
    }
    TreeNode* helper(TreeNode* root) {//joining right pointer 
            if (root->left == NULL) //if left subtree doesnt exist return points to right subtree
            {
                return root->right;
            } 
            else if (root->right == NULL) //if right subtree doesnt exist return points to left subtree
            {
                return root->left;
            } 
            TreeNode* rightChild = root->right;
            TreeNode* lastRight = findLastRight(root->left);
            lastRight->right = rightChild;
            return root->left;
    }
    TreeNode* findLastRight(TreeNode* root) {//got to right......
        if (root->right == NULL) {
            return root;
        }
        return findLastRight(root->right);
    }
};
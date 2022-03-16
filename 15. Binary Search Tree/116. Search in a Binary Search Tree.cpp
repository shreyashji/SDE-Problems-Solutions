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
    //time = O(lo bas 2 N) traversal time height of bst,worst case leaf node
    //space = O(1)
    TreeNode* searchBST(TreeNode* root, int val) {
        //kep on traversing till dont reach null or value dont concide with the value which i am looking for
        while(root != NULL && root->val != val){//if equal stop at this condition root->val != val
            root = val<root->val? root->left:root->right;//if valuse lesser than root value move to left ,if not move right
        }
        return root;
    }
};
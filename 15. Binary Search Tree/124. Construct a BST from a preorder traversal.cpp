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
    //time = O(3n) 3 times visiting a node at worst ~~O(N)
    //space= (1) yes stac space is there ,,
TreeNode* bstFromPreorder(vector<int>& A) {
        int i = 0;//need a pointer to move across
        return build(A, i, INT_MAX);
    }

    TreeNode* build(vector<int>& A, int& i, int bound) {
        if (i == A.size() || A[i] > bound) return NULL; //if run out of elements in bst its over or  out of bound return null in both cases
        TreeNode* root = new TreeNode(A[i++]);
        root->left = build(A, i, root->val);//on left bound has to be self adjusted,for left root val wil,l be upper bound,but if it comes back it will go to right
        root->right = build(A, i, bound);//for right bound will be same
        return root;
    }
};
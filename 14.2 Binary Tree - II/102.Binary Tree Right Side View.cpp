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
    //time = O(N)
    //space= O(H) ,but if skew tree it will be  O(n)
    vector<int> rightSideView(TreeNode *root) {
        vector<int> res;
        recursion(root, 0, res); //root,level,res(ans vector or result)
        return res;
    }
    //since we are moving rightward direction at first whichever lvl come across ,that will always be the 1st noder from right side,if at backtracking we are doing check (res.size()==level) ignoring the left side
    void recursion(TreeNode *root, int level, vector<int> &res){
        if(root==NULL) return ;
        if(res.size()==level) res.push_back(root->val); //if size==level added in result
        recursion(root->right, level+1, res); //move to right,increase level
    recursion(root->left, level+1, res); //move to left,increase level
    }
};
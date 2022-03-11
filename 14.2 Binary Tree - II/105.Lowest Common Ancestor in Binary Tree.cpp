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
    //time=O(n) dfs traversal
        //space=O(n) auxilary in  case of skew tress
   TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //base case
        if (root == NULL || root == p || root == q) {
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        //result,while comning back
        if(left == NULL) { //if left appears null,i take right guy
            return right;
        }
        else if(right == NULL) {//if right appears null,i take left guy
            return left;
        }
        else { //both left and right are not null, we found our result,
            //both the p& q lies under the root or node then return node itself
            return root;
        }
    }
};
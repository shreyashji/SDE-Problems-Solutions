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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) return new TreeNode(val);//if empty make node as root and return
        TreeNode *cur = root; //create copy of root,coz need to return root itself at the end
        while(true) { //if greater
            if(cur->val <= val) { //if val which is asked to insert that is on the right side
                if(cur->right != NULL) cur = cur->right;//on right by any chance is not null,move to right keep on
                else {//if null
                    cur->right = new TreeNode(val); //if null , point the right by creating a new node
                    break;//break its over
                }
            }
            //if not greater,move to left
            else { //if exist a left ,similarly
                if(cur->left != NULL) cur = cur->left;
                else {
                    cur->left = new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};
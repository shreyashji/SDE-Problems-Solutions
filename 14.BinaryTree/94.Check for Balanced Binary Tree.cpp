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
    //time= O(n) traversal
    //space= (n)auxilary space  fro skew tree ,worst case
    bool isBalanced(TreeNode* root) {
        return dfsHeight (root) != -1;//if doesnt return -1 ,balanced b- tree
    }
    int dfsHeight (TreeNode *root) {
        if (root == NULL) return 0;
        
        int leftHeight = dfsHeight (root -> left); //to calculate left height
        if (leftHeight == -1) return -1; //if left height -1 return -1
        int rightHeight = dfsHeight (root -> right); //to calculate right height
        if (rightHeight == -1) return -1;//if right height -1 return -1
        
        if (abs(leftHeight - rightHeight) > 1)  return -1;//if absolute is greterthan 1 means unbalanced
        return max (leftHeight, rightHeight) + 1;
    }
};
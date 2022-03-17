class Solution {
public:
//time= O(H) height of tree
//space=O(1)
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* successor = NULL; //ans as null initailly 
        while (root != NULL) {
            if (p->val >= root->val) {  //if given val is samller than equal to crnt value need to find greater
                root = root->right; //then need to find greater
            } 
            else {
                successor = root; //sbefor going left store the answer
                root = root->left;
            }
        }
        return successor;
    }
};
//for predecessor
TreeNode* inorderPredecessor(TreeNode* root, TreeNode* p) {
        TreeNode* predecessor = NULL;
        
        while (root != NULL) {
            
            if (p->val < root->val) {
                root = root->left;
            } else {
                predecessor = root;
                root = root->right;
            }
        }
        
        return predecessor;
    }
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        //we have to go through alll nodes ,can avoid it
        //time=O(n)
        //spaceO(N) for skew worst
        if(root == NULL) return 0; 
        
        int lh = maxDepth(root->left); 
        int rh = maxDepth(root->right); 
        
        return 1 + max(lh, rh); 
    }
};
class Solution {

public:
//time=O(n)
//space =O(n) stack space or O(Hieht of binary tree)
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        if(root == NULL) return preorder; 
       
        stack<TreeNode*> st; 
        st.push(root);
        while(!st.empty()){
            root = st.top(); //get topmost element
            st.pop(); 
            preorder.push_back(root->val); //every iteration get topmost of stack
            if(root->right != NULL){ //checkout if there exist right
                st.push(root->right);
            }
            if(root->left!= NULL){ //checkout if there exist left
                st.push(root->left);
            }
        }
        return preorder; //stack become empty return preorder
    }
};
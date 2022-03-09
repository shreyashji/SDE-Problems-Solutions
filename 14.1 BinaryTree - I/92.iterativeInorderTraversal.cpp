
class Solution {

public:
//time=O(n)
//space=O(n)  auxilary space,if skew O(n)~~O(height)
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st; //take empty stack
        TreeNode* node = root; //asig crnt node to root
        vector<int> inorder; //store inorder
        while(true) {
            if(node != NULL) {
                st.push(node); //not null push into the stack,auxilary stack trace
                node = node->left; //move to left
            }
            else {//null
                if(st.empty() == true) break; //if empth means no node to traverse
                node = st.top(); //or else whatever at top 
                st.pop(); //take it
                inorder.push_back(node->val); //that will be our inorder
                node = node->right;// move to the right,iteration goes over
            }  
        }
        return inorder; ///after break out return inorder
    }
};
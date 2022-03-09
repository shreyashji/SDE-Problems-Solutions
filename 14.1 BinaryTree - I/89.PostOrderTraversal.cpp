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
    private:
    void dfs(TreeNode *node, vector<int> &postorder) {
        if(node == NULL) return; 
        
        dfs(node->left, postorder); 
        dfs(node->right, postorder); 
        postorder.push_back(node->val); 
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        dfs(root, postorder);
        return postorder; 
    }
};

/* Using 2 stack itrative approcah
class Solution {
//time= (N)
//space=o(2N)
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        if(root == NULL) return postorder;
        stack<TreeNode*> st1, st2; 
        st1.push(root); 
        while(!st1.empty()) {
            root = st1.top();  //take topmost elemnt,push it into other stack
            st1.pop();
            st2.push(root); 
            if(root->left != NULL) { //if there exist a left put it in to stack1
                st1.push(root->left); 
            }
            if(root->right != NULL) {//if there exist a right put it in to stack1
                st1.push(root->right); 
            }
        }
        while(!st2.empty()) { //if stack 1 becomes empty,pop out every elemnt from stack 2 7 put it into postorder
            postorder.push_back(st2.top()->val); 
            st2.pop(); 
        }
        return postorder;//return that postorder
    }
};

*/
/* Iterative Postorder Traversal using 1 Stack
class Solution {  
//time= (2n)
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        if(root == NULL) return postorder;
        stack<TreeNode*> st1;
        TreeNode* current = root;  
        while(current != NULL || !st1.empty()) {
            if(current != NULL){
                st1.push(current);
                current = current->left;
            }else{
                TreeNode* temp = st1.top()->right;
                if (temp == NULL) {
                    temp = st1.top();
                    st1.pop(); 
                    postorder.push_back(temp->val);
                    while (!st1.empty() && temp == st1.top()->right) {
                        temp = st1.top();
                        st1.pop(); 
                        postorder.push_back(temp->val);
                    }
                } else {
                    current = temp;
                }
            }
        }
        return postorder;
    }
};

*/
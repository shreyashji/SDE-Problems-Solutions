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
//time = O(n)
//space= O(1) ,not assuming stack space,if interviewer calculating stack space then tell about morris traversal we can use and space complexity will be O(1)
class Solution {
private: 
    TreeNode* first; //first violation
    TreeNode* prev; //who was the last guy
    TreeNode* middle; //after first
    TreeNode* last;  //last
    //above variable are not global,declared inside a class & private,tey are member function
private: 
    void inorder(TreeNode* root) {
        if(root == NULL) return;//if root null stop
        inorder(root->left); //go to left
        //all the business below
        if (prev != NULL && (root->val < prev->val)){ //crnt node smaller than prev
            // If this is first violation, mark these two nodes as
            // 'first' and 'middle'
            if ( first == NULL )
            {
                first = prev;
                middle = root;
            }
            // If this is second violation, mark this node as last
            else
                last = root;
        }
 
        // Mark this node as previous
        prev = root;
        inorder(root->right); 
    }
public:
    void recoverTree(TreeNode* root) {
        first = middle = last = NULL; //all are null
        prev = new TreeNode(INT_MIN);  //first element in inorder will be smallest
        inorder(root); //do a inorder traversal
        if(first && last) swap(first->val, last->val); ///if two violation first & last swap them
        else if(first && middle) swap(first->val, middle->val); 
    }
};
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
//time = O(1) (pushing n elemnts N/N next calls might be) ~~1 on average a lot of time no callled ~~O(1)
//space= O(H)
class BSTIterator {
    stack<TreeNode *> myStack; //declared  a stack,store all tree node
public:
    BSTIterator(TreeNode *root) {
        pushAll(root); //push all to the left //left,node,right,,go tto extreme left
    }

    /** @return whether we have a next smallest number */
    bool hasNext() { //if stack is not empty means yes there are next
        return !myStack.empty();
    }

    /** @return the next smallest number */
    int next() { 
        TreeNode *tmpNode = myStack.top();
        myStack.pop(); //inorder first element
        pushAll(tmpNode->right);//go to right,pushh all the left
        return tmpNode->val;
    }

private:
    void pushAll(TreeNode *node) {
        for (; node != NULL; myStack.push(node), node = node->left);//take all left & push to stack
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
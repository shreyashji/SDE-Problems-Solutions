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
class BSTIterator {
    //reverse->true->before
    //reverse->true->next
    stack<TreeNode *> myStack;
    bool reverse = true; 
public:
    BSTIterator(TreeNode *root, bool isReverse) {
        reverse = isReverse; 
        pushAll(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !myStack.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *tmpNode = myStack.top();
        myStack.pop(); //take stack top it will be next elemnt
        if(!reverse) pushAll(tmpNode->right);//if doing for right,automatically push all left,coz of the reverse we initilized
        else pushAll(tmpNode->left);
        return tmpNode->val;
    }
//reverse : right....
 //next: left left....   
private:
    void pushAll(TreeNode *node) {
        for(;node != NULL; ) {
             myStack.push(node);
             if(reverse == true) {//if before go right
                 node = node->right; 
             } else { //left left....
                 node = node->left; 
             }
        }
    }
};
//above is bst iterator,different class
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false; 
        //created object of the same class (below),l,r will be different object will be treated differently
        BSTIterator l(root, false);  //left means next
        BSTIterator r(root, true); //right means before
        
        int i = l.next(); 
        int j = r.next(); 
        while(i<j) {//simple two poinnters
            if(i + j == k) return true; //if equal true
            else if(i + j < k) i = l.next(); //if lesser ,i will move
            else j = r.next(); //if greater j will move
        }
        return false; //if cross false
    }
};
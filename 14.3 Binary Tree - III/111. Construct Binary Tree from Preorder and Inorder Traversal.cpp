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
    //time = O(n) + hashmap O(n log n)
    //space = map O(N) + traversal stack space ~~O(N)
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> inMap; 

        for(int i = 0; i < inorder.size(); i++) {//put entire inorder into hash map
            inMap[inorder[i]] = i; 
        }
//passing preorder & index 0,pass size as size-1,inorder & index 0 and size
        TreeNode* root = buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inMap);
        return root;
    }
   TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, map<int, int> &inMap) {
        if(preStart > preEnd || inStart > inEnd) return NULL;

        TreeNode* root = new TreeNode(preorder[preStart]);
        int inRoot = inMap[root->val];//inroot pints to next element
        int numsLeft = inRoot - inStart;//1 elemnt in left
//again build yourself pass ,this time preordr start from start+1,instart starting point,inroot just after start ,this passed to build tree on left
//(preStart + 1)start with elemnt,( preStart + numsLeft)ends with same element,using this to mark reduction of array,all this is to find new preorder for left guy after this
//passing starting of inorder ,passing this to build tree on left
        root->left = buildTree(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1, inMap);
        root->right = buildTree(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, inMap);

        return root;
    }    
};
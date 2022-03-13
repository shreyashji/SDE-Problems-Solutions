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
    //time=O((log n)^2 ) height at any instane will nort be more than log n,at max traversing for log n nodes
    //log n for traversing (log n)  * height of tree (log n)=O((log n)^2 )
    //space recursive space= deep as O(log n)
    int countNodes(TreeNode* root) {
          if(root == NULL) return 0; 
        
        int lh = findHeightLeft(root); 
        int rh = findHeightRight(root); 
        
        if(lh == rh) return (1<<lh) - 1; //2^h-1 that will be no of nodes
        //if not below crnt + 
        return 1 + countNodes(root->left) + countNodes(root->right); //recursion for every nodes
    }
    //complt tree so all the nodes will be always be filled
    int findHeightLeft(TreeNode* node) {///go to left.......left
        int hght = 0; 
        while(node) {
            hght++; 
            node = node->left; 
        }
        return hght; 
    }
    int findHeightRight(TreeNode* node) {//go to righr......right
        int hght = 0; 
        while(node) {
            hght++; 
            node = node->right; 
        }
        return hght; 
    }
};
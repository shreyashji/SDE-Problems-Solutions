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
     //time=O(n) levl order traversal
        //space=O(n) queue ds
    long long widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        long long ans = 0;//STORE max width
        queue<pair<TreeNode*, int>> q;
        q.push({root,0});
        while(!q.empty()){
            long long size = q.size();
            long long mmin = q.front().second;    //to make the id starting from zero,taken first guy index,minimal index possible at that level
            long long first,last;
            for(int i=0; i<size; i++){//iterate on all the elements of queue
                long long cur_id = q.front().second-mmin;//currnt index always be minus by minimal of that level,subtract to avoid overflow
                TreeNode* node = q.front().first;
                q.pop();
                if(i==0) first = cur_id; //store the first guy
                if(i==size-1) last = cur_id;//store the second guy
                if(node->left)
                    q.push({node->left, cur_id*2+1}); //if left after subtracttion do *2+1
                if(node->right)
                    q.push({node->right, cur_id*2+2});
            }
            ans = max(ans, last-first+1);
        }
        return ans;
    }
};
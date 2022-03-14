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
    //time= O(N) traversal * O(n log n ) hashmap ~~O(N log N)
    //space= O(n)hashmap  * (n) auxilary sapce ~~ O(n)
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() != postorder.size()) //if do not match in size return null
            return NULL;
        map<int,int> hm; //create a map,store inorder,to match last elemnt of post to inorder
        for (int i=0;i<inorder.size();++i)
            hm[inorder[i]] = i;
        //call start pointer 0 ,ending ptr as  inorder.size()-1,postorder starting point 0,ending ptr as  postorder.size()-1,with hashmap
        return buildTreePostIn(inorder, 0, inorder.size()-1, postorder, 0, 
                              postorder.size()-1,hm);
    }
    //is i strting ptr of inorder,ie ending ptr of inorder,ps is strt of postorder,pe is ending ptr of postorder
    TreeNode* buildTreePostIn(vector<int> &inorder, int is, int ie, vector<int> &postorder, int ps, int pe, 
                                     map<int,int> &hm){
        if (ps>pe || is>ie) return NULL;//if run out of inorder or postorder,if size 0 then no right & left subtree
        TreeNode* root = new TreeNode(postorder[pe]);//postorder end will be root
        int ri = hm[postorder[pe]];//to get root in inorder through hashmap 
        //call the lfet with same inorder new strting,end root -1,for postorder,strt from starting & end up taking 3 nos
        TreeNode* leftchild = buildTreePostIn(inorder, is, ri-1, postorder, ps, ps+ri-is-1, hm);
//right order subtree start from  inroot+1 of inorder,till inorder end ,postorder start from 3+1 ,end at end -1 before root 
        TreeNode* rightchild = buildTreePostIn(inorder,ri+1, ie, postorder, ps+ri-is, pe-1, hm);
        root->left = leftchild;
        root->right = rightchild;
        return root;//at the end return root of tree
    }
};
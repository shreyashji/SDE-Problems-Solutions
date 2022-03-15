class Solution {
public:
//time = O(n)
//space = O(1)
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder; 
        TreeNode* cur = root; //moving on cur so root cant be destroyed
        while(cur != NULL) {///move till curr not read null
            if(cur->left == NULL) {//means it does not have a left,root will be printed
                inorder.push_back(cur->val); //this is the first  case
                cur = cur->right; 
            }
            else {//if exist a left,go to left subtree and find out last guy in that subtree that will be visited in that inorder
                TreeNode* prev = cur->left; 
                while(prev->right != NULL && prev->right != cur) {//if exist a right go right as can & right should not pointing to himself
                    prev = prev->right; //keep on moving to extreme right
                }
                
                if(prev->right == NULL) {//case when right will  become null
                    prev->right = cur;//make a thread points to curr
                    cur = cur->left; //do traversal
                }
                else {
                    prev->right = NULL; //cut the thread
                    inorder.push_back(cur->val);//since we come back 
                    cur = cur->right;  //since visited the eft go to right
                }
            }
        }
        return inorder; 
    }
};
/* preorder (rott,left,right)
//time = O(n) 
//space = O(1)
class Solution {
public:
    vector<int> getPreorder(TreeNode* root) {
        vector<int> preorder; 
        
        TreeNode* cur = root; //moving on cur so root cant be destroyed
        while(cur != NULL) {///move till curr not read null
            if(cur->left == NULL) {//means it does not have a left,root will be printed
                preorder.push_back(cur->val); //this is the first  case
                cur = cur->right; 
            }
            else {//if exist a left,go to left subtree and find out last guy in that subtree that will be visited in that inorder
                TreeNode* prev = cur->left; 
                while(prev->right != NULL && prev->right != cur) {//if exist a right go right as can & right should not pointing to himself
                    prev = prev->right; //keep on moving to extreme right
                }
                
                if(prev->right == NULL) {//case when right will  become null
                    prev->right = cur;//make a thread points to curr
                    preorder.push_back(cur->val);//while marking store that inot preorder
                    cur = cur->left; //do traversal
                }
                else {
                    prev->right = NULL; //cut the thread
                   
                    cur = cur->right;  //since visited the eft go to right
                }
            }
        }
        return preorder; 
    }
};

*/
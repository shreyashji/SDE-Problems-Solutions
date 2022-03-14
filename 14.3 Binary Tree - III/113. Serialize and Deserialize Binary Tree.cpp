/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
//overall time comple & space
//time = level order serialize O(n) ~~ O(n)
//space =  O(n) foo queue & string ~~ O(n)
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";//if root null return empty string
        string s =""; //declare an empty string
        queue<TreeNode*> q; //taken a queue
        q.push(root); //push the root
        while(!q.empty()) {//do level order traversal,start iterating till it becomes empty
           TreeNode* curNode = q.front();//took out first node from queue
           q.pop();
           if(curNode==NULL) s.append("#,");//if nude has null appen #
           else s.append(to_string(curNode->val)+',');//if not null appended the value,convert it to string and a comma
           if(curNode != NULL){ // insteead of checking left & right to be null,we have inserted the left & right,even if null it will go inside,appending # if null
               q.push(curNode->left);
               q.push(curNode->right);            
           }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL; //if data is empty,means no Binary tree return null
        stringstream s(data);//bascially allows string to be iterated over objects
        string str;  //(1,2,3,#,4,5,#,#....)
        getline(s, str, ',');//get line on stream s and string str and delimmiter is comma,go over 1,2,3
        TreeNode *root = new TreeNode(stoi(str));//create root
        queue<TreeNode*> q; //took a queue
        q.push(root); //start with roor
        while(!q.empty()) {
            
            TreeNode *node = q.front(); 
            q.pop(); //took out that value
            
            getline(s, str, ','); //what ever the next guy or in left,make sure it is atached
            if(str == "#") {
                node->left = NULL; 
            }
            else { //if a no. create a new node,attached to nodes left & pushed it into queue
                TreeNode* leftNode = new TreeNode(stoi(str)); 
                node->left = leftNode; 
                q.push(leftNode); 
            }
            
            getline(s, str, ',');  //similarly take next node ,create new node as right node
            if(str == "#") { 
                node->right = NULL; 
            }
            else { // if a no.. ,create new node as right node
                TreeNode* rightNode = new TreeNode(stoi(str));  //attached to nodes right & pushed it into queue
                node->right = rightNode;
                q.push(rightNode); 
            }
        }
        return root; //return root after deserializing
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
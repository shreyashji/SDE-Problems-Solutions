/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//time= traversal to findout parent nodes O(N)+traversing on all nodes at distance k worst O(N)+hashmap O(nlon)
//~~overall O(N) * O(n log n)
//space=parent map O(N) + queue O(N) + visited O(N) ~~ O(N)
class Solution {
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent_track, TreeNode* target) {
        queue<TreeNode*> queue;
        queue.push(root);//insert the root
        while(!queue.empty()) { //level order traversal by taking a queue
            TreeNode* current = queue.front(); //do iteration on node
            queue.pop();
            if(current->left) {
                parent_track[current->left] = current;
                queue.push(current->left);
            }
            if(current->right) {
                parent_track[current->right] = current;
                queue.push(current->right);
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent_track; // node -> parent,//parent pointer map,parent is ready
        markParents(root, parent_track, target); 
        
        unordered_map<TreeNode*, bool> visited; //visited map
        queue<TreeNode*> queue;// queue
        queue.push(target);//start from target,put that in visited
        visited[target] = true;
        int curr_level = 0; //distance
        while(!queue.empty()) { /*Second BFS to go upto K level from target node and using our hashtable info*/
            int size = queue.size();
            if(curr_level++ == k) break;
            for(int i=0; i<size; i++) {//trversing all nodes prsnt in queue
                TreeNode* current = queue.front(); queue.pop();
                if(current->left && !visited[current->left]) {//check on left exist and if not visited,take into queue mark them as visited
                    queue.push(current->left);
                    visited[current->left] = true;
                }
                if(current->right && !visited[current->right]) {//check on rigt and if not visited,take into queue mark them as visited
                    queue.push(current->right);
                    visited[current->right] = true;
                }
                if(parent_track[current] && !visited[parent_track[current]]) {//check on parent and if not visited,take into queue mark them as visited
                    queue.push(parent_track[current]);
                    visited[parent_track[current]] = true;
                }
            }
        }
        vector<int> result;//after breakout ,whatever in queue take in vector
        while(!queue.empty()) {
            TreeNode* current = queue.front(); queue.pop();
            result.push_back(current->val);
        }
        return result;//return that vector 
    }
};
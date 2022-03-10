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
    //time=O(n)traversing genrallly logn for multiset ~~O(nlogn)
    //space=O(n) fro every vverticla we have to store all nodes +o(n) fro queue ds ~~O(n)
    vector<vector<int>> verticalTraversal(TreeNode* root) {
     map<int, map<int, multiset<int>>> nodes; //for storing vertical order
        queue<pair<TreeNode*, pair<int, int>>> todo; // storing (node,vertical,level)
        todo.push({root, {0, 0}});
        while (!todo.empty()) { //level order traversal 
            auto p = todo.front(); 
            todo.pop(); //take node
            TreeNode* node = p.first;
            int x = p.second.first, y = p.second.second; //take vertical order x,and take level
            nodes[x][y].insert(node -> val);//store in ,vertical [x],level[y],insert  node->val
            if (node -> left) { //if there is left take that left,insert it into queue,do vertical(x-1),level(y+1)
                todo.push({node -> left, {x - 1, y + 1}});
            }
            if (node -> right) {//if there is right take that left,insert it into queue,do vertical(x+1),level(y+1)
                todo.push({node -> right, {x + 1, y + 1}});
            }
        }
        vector<vector<int>> ans; //answer
        for (auto p : nodes) { //traverse across map nodes,(map->p.first,multiset ->p.second)
            vector<int> col; //take a column
            for (auto q : p.second) { //map(int(level),multiset)
                col.insert(col.end(), q.second.begin(), q.second.end()); //at every level,inserting right at the end
                ///inserting entire multiset, for vertical traversal (0) we had lvl 0,1,first we travel for 0 got multiset insert into the col,next level 1 we got multiset insert into the col ,eg.(0->0->{},0->1->{},0->2->{})
                //insert the vertical order(col) into ans
            }
            ans.push_back(col);
        }
        return ans;
    }
};
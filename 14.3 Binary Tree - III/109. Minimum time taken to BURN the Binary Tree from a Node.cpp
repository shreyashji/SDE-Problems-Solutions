#include<bits/stdc++.h> 
//time = bfs to map parent O(N)+ bfs which is burning adjacent node O(N) ~~O(N) ,assuming map works in O(1)
//spaace = external map,external queue ~~O(N)
int findMaxDistance(map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> &mpp, BinaryTreeNode<int>* target) {
    queue<BinaryTreeNode<int>*> q; 
    q.push(target); //push target into queue
    map<BinaryTreeNode<int>*,int> vis; 
    vis[target] = 1; //marking visited as 1 
    int maxi = 0; //initial timer is 0
    while(!q.empty()) { //start iterating
        int sz = q.size(); //take queue directly on size ,run simultaneously
        int fl = 0; 
        for(int i = 0;i<sz;i++) {
            auto node = q.front();
            q.pop();
            if(node->left && !vis[node->left]) {//does it has left & is not visited,if it is burn it
                fl = 1; 
                vis[node->left] = 1; 
                q.push(node->left); 
            }
            if(node->right && !vis[node->right]) {
                fl = 1; 
                vis[node->right] = 1; 
                q.push(node->right); 
            }
            
            if(mpp[node] && !vis[mpp[node]]) { //does parent pointer exist ,if it is already visited,if not burn it,push it into queue
                fl = 1; 
                vis[mpp[node]] = 1; 
                q.push(mpp[node]); 
            } 
        }
        if(fl) maxi++; //if burning any node mark flag maxi(timer) as 1 ,incr maxi if burining any nodes
    }
    return maxi; 
}
BinaryTreeNode<int>* bfsToMapParents(BinaryTreeNode<int>* root, 
                                    map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> &mpp, int start) {
    queue<BinaryTreeNode<int>*> q; //declare queue 
    q.push(root); //push root
    BinaryTreeNode<int>* res;  //store the address of start
    while(!q.empty()) { //do a level order traversal
        BinaryTreeNode<int>* node = q.front(); //get the node
        if(node->data == start) res = node; //if equivalent to start,store that node address
        q.pop(); 
        if(node->left) { 
            mpp[node->left] = node; //left if parent is node
            q.push(node->left); //push it into queue
        }
        if(node->right) {
            mpp[node->right] = node;//right if parent is node
            q.push(node->right);  //push it into queue
        }
    }
    return res; 
}
int timeToBurnTree(BinaryTreeNode<int>* root, int start)
{
    map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> mpp;  ///Bfs make sure mpp contains all parent 
    BinaryTreeNode<int>* target = bfsToMapParents(root, mpp, start); //target node where start node will be
    int maxi = findMaxDistance(mpp, target); //pass map  & target node
    return maxi; 
}
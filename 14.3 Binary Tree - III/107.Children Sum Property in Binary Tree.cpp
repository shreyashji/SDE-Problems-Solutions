void reorder(BinaryTreeNode < int > * root) {
    //time = O(n) traversal on nodes
    //space=O(height of tree),worst o(n) if skew tree
    if(root == NULL) return; 
    int child = 0;
    if(root->left) { //if left exist add to child ,when you go down
        child += root->left->data; 
    }
    if(root->right) {//if right exist add to child,when you go down
        child += root->right->data; 
    }
    
    if(child >= root->data) root->data = child; 
    else {
        if(root->left) root->left->data = root->data; 
        else if(root->right) root->right->data = root->data; 
    }
    
    reorder(root->left); //move to left  ,traversal part
    reorder(root->right); //move to right,traversal part
    
    int tot = 0; 
    if(root->left) tot += root->left->data;  //when come back simply sum left & right //and assign it to root
    if(root->right) tot += root->right->data; 
    if(root->left or root->right) root->data = tot;  //check if its not leaf node,if its not leaf then only update the upper guy
    //when move up,backtrack,reupdate the roots value
}
void changeTree(BinaryTreeNode < int > * root) {
    reorder(root); 
} 
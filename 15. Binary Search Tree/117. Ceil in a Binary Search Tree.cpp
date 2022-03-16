 int findCeil(BinaryTreeNode<int> *root, int key){
    //time = O(lo bas 2 N) traversal time height of bst,worst case leaf node
    //space = O(1)
	int ceil = -1; 
    while (root) {

        if (root->data == key) {//if key already exist in bst just return 
            ceil = root->data;
            return ceil;
        }
 
        if (key > root->data) { //key greater than root ,mov eto right
            root = root->right;
        }
        else { //if not greater,update ceil move left
            ceil = root->data; 
            root = root->left;
        }
    }
    return ceil; //root becomes null return ceil
}
int floorInBST(TreeNode<int> * root, int key)
{
    //time = O(lo bas 2 N) traversal time height of bst,worst case leaf node
    //space = O(1)
    int floor = -1; 
    while (root) {
 
        if (root->val == key) { //if equivalent ot key no need to go left & right
            floor = root->val; //store in the floor variable and return
            return floor;
        }
 
        if (key > root->val) { //key greater than curnt root value,increase it & move to right
            floor = root->val; //make sure store the floor before moving
            root = root->right;
        }
        else { //if not go left,need to decrease <=key
            root = root->left;
        }
    }
    return floor;
}
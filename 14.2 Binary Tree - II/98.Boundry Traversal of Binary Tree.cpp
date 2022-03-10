#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  struct node * left, * right;
};
//time=o(h)+O(H)+O(N)~~O(N)
//space=O(N)auxilary,not considering space used in res 
bool isLeaf(node * root) {
  return !root -> left && !root -> right;
}
//step 1 left boundry ,left....left if there is no left then move to right O(H)
void addLeftBoundary(node * root, vector < int > & res) {
  node * cur = root -> left;
  while (cur) {
    if (!isLeaf(cur)) res.push_back(cur -> data); //if not a leaf node then only add to left boundry excluding leaf nodes
    if (cur -> left) cur = cur -> left;//move to left
    else cur = cur -> right;//if doesnt exist left move to right
  }
}
// step 3 for right boundry O(H)
void addRightBoundary(node * root, vector < int > & res) {
  node * cur = root -> right;//move to right
  vector < int > tmp;
  while (cur) {
    if (!isLeaf(cur)) tmp.push_back(cur -> data);//if not leaf add it,store this in temp ds
    if (cur -> right) cur = cur -> right;//move to right....right
    else cur = cur -> left;//if not a right,take left
  }
  for (int i = tmp.size() - 1; i >= 0; --i) {//right after this take the reverse
    res.push_back(tmp[i]);
  }
}
//simple inorder traversal,take leaf nodes
void addLeaves(node * root, vector < int > & res) {
  if (isLeaf(root)) { 
    res.push_back(root -> data);//if leaf node add to ds
    return;
  }
  if (root -> left) addLeaves(root -> left, res); //left
  if (root -> right) addLeaves(root -> right, res);//right
}

vector < int > printBoundary(node * root) { //store entire boundry traversal ds
  vector < int > res;
  if (!root) return res; //if root node is not leaf add into ds

  if (!isLeaf(root)) res.push_back(root -> data); //steps
    //steps 1 take left bondry excluding leaf node
  addLeftBoundary(root, res);

  // step 2 take leaf node, add leaf nodes
  addLeaves(root, res);
    //step 3 .take right boundry 
  addRightBoundary(root, res);
  return res;
}

struct node * newNode(int data) {
  struct node * node = (struct node * ) malloc(sizeof(struct node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;

  return (node);
}

int main() {

  struct node * root = newNode(1);
  root -> left = newNode(2);
  root -> left -> left = newNode(3);
  root -> left -> left -> right = newNode(4);
  root -> left -> left -> right -> left = newNode(5);
  root -> left -> left -> right -> right = newNode(6);
  root -> right = newNode(7);
  root -> right -> right = newNode(8);
  root -> right -> right -> left = newNode(9);
  root -> right -> right -> left -> left = newNode(10);
  root -> right -> right -> left -> right = newNode(11);

  vector < int > boundaryTraversal;
  boundaryTraversal = printBoundary(root);

  cout << "The Boundary Traversal is : ";
  for (int i = 0; i < boundaryTraversal.size(); i++) {
    cout << boundaryTraversal[i] << " ";
  }
  return 0;
}
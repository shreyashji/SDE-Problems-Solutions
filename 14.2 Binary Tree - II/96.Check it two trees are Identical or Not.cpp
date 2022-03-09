#include <bits/stdc++.h>
using namespace std;
struct node {
  int data;
  struct node * left, * right;
};

//time = O(n) We are doing a tree traversal.
//space=O(n) space needed for recursio stack
bool isIdentical(node * node1, node * node2) {
  if (node1 == NULL && node2 == NULL)
    return true;
  else if (node1 == NULL || node2 == NULL)
    return false;

  return ((node1 -> data == node2 -> data)  /*check for value of p & q*/
  && isIdentical(node1 -> left, node2 -> left) /*move to the left*/
  && isIdentical(node1 -> right, node2 -> right));/*move to the right*/
}

struct node * newNode(int data) {
  struct node * node = (struct node * ) malloc(sizeof(struct node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;

  return (node);
}

int main() {
  struct node * root1 = newNode(1);
  root1 -> left = newNode(2);
  root1 -> right = newNode(3);
  root1 -> right -> left = newNode(4);
  root1 -> right -> right = newNode(5);

  struct node * root2 = newNode(1);
  root2 -> left = newNode(2);
  root2 -> right = newNode(3);
  root2 -> right -> left = newNode(4);

  if (isIdentical(root1, root2))
    cout << "Two Trees are identical";
  else cout << "Two trees are non-identical";

  return 0;
}
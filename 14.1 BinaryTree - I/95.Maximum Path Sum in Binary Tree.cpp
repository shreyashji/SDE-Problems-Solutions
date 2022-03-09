#include <bits/stdc++.h>
using namespace std;
struct node {
  int data;
  struct node * left, * right;
};
    //time = O(n) We are doing a tree traversal.
    //space=O(n) space needed for recursio stack
int findMaxPathSum(node * root, int & maxi) {
  if (root == NULL) return 0;

  int leftMaxPath = max(0, findMaxPathSum(root -> left, maxi));//if maxPathDown(node->left, maxi) from left give
  // -ive return 0 ,if we are standing at -10,til here you know but after than we have to take left or right path,
  //thats why returning left path & right path is necessary,so we know whether take right or left,via -10
  int rightMaxPath = max(0, findMaxPathSum(root -> right, maxi));//if maxPathDown(node->left, maxi) from right give -ive 
  int val = root -> data;
  maxi = max(maxi, (leftMaxPath + rightMaxPath) + val);
  return max(leftMaxPath, rightMaxPath) + val;

}
int maxPathSum(node * root) {
  int maxi = INT_MIN;//maximum as int_min
  findMaxPathSum(root, maxi);
  return maxi;

}
struct node * newNode(int data) {
  struct node * node = (struct node * ) malloc(sizeof(struct node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;

  return (node);
}

int main() {

  struct node * root = newNode(-10);
  root -> left = newNode(9);
  root -> right = newNode(20);
  root -> right -> left = newNode(15);
  root -> right -> right = newNode(7);

  int answer = maxPathSum(root);
  cout << "The Max Path Sum for this tree is " << answer;

  return 0;
}
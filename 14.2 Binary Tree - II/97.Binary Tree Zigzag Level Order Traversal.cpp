#include<bits/stdc++.h>
using namespace std;
class Node {
  public:
    int val;
  Node * left, * right;
};
//time==O(n)
//space= O(n)
vector < vector < int >> zigzagLevelOrder(Node * root) {
  vector < vector < int >> result;
  if (root == NULL) {
    return result;
  }

  queue < Node * > nodesQueue; //declare queue
  nodesQueue.push(root); //push root
  bool leftToRight = true; //flag initialy marked as true= l to r,fALSE MEANS R TO LEFT

  while (!nodesQueue.empty()) { //TRAVERSE IN THE QUEUE, take all nodes of that level
    int size = nodesQueue.size();
    vector < int > row(size);
    for (int i = 0; i < size; i++) { //run for loop fro all the nodes of that level
      Node * node = nodesQueue.front();
      nodesQueue.pop();

      // find position to fill node's value
      int index = (leftToRight) ? i : (size - 1 - i);//if true put 2,3(push from front) it in ds ,
      //if false put 3,2(push from back)

      row[index] = node -> val;
      if (node -> left) {
        nodesQueue.push(node -> left);
      }
      if (node -> right) {
        nodesQueue.push(node -> right);
      }
    }
    // after this level
    leftToRight = !leftToRight; //switch on the flags 
    result.push_back(row);
  }
  return result;
}
Node * newNode(int data) {
  Node * node = new Node;
  node -> val = data;
  node -> left = NULL;
  node -> right = NULL;
  return node;
}

int main() {
  int i, j;
  Node * root = newNode(3);
  root -> left = newNode(9);
  root -> right = newNode(20);
  root -> right -> left = newNode(15);
  root -> right -> right = newNode(7);
  vector < vector < int >> ans;
  ans = zigzagLevelOrder(root);
  cout << "Zig Zag Traversal of Binary Tree" << endl;
  for (i = 0; i < ans.size(); i++) {
    for (j = 0; j < ans[i].size(); j++) {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
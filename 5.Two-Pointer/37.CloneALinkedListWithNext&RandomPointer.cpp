/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
          Node *iter = head; //dummy nodes
          Node *front = head; //dummy nodes

          // First round: make copy of each node,
          // and link them together side-by-side in a single list.
          while (iter != NULL) {
            front = iter->next;

            Node *copy = new Node(iter->val); //copy node,initilize new node val similar to first nodes,creating deep copy of node
            iter->next = copy; //copy is copied node
            copy->next = front; //

            iter = front;
            //similar stuff in next step
          }
          // Second round: assign random pointers for the copy nodes.
          iter = head;
          while (iter != NULL) {
            if (iter->random != NULL) {
              iter->next->random = iter->random->next; //deep copy node,current random of itr= deep copy of that i.e next
            }
            iter = iter->next->next;//iters gonna move 1->1'->2 ,via deep copy
          }
        
          // Third round: restore the original list, and extract the copy list.
          iter = head;
          Node *pseudoHead = new Node(0); //at dummy node
          Node *copy = pseudoHead; //initial head of deep copy list

          while (iter != NULL) {
            front = iter->next->next; //via deep copy,breaking 1->1'

            // extract the copy
            copy->next = iter->next; //dummy next pointing to iter next

            // restore the original list
            iter->next = front; //1->2
              
            copy = copy -> next;  //move copy which on deep copy ll
            iter = front;
          }

          return pseudoHead->next; //head of deep copy ll
    }
    
};
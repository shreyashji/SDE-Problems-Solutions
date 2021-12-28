/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
//time = O(N) + O(N-(N%k)) to count no. of nodes, traversing nodes to k-length  nodes
//space= o(1)
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        
        // compute the length
        ListNode *cur = head;
        int len = 1;        //counter
        while (cur->next && ++len) //simulataneoulsy increase the value of lenth or counter
            cur = cur->next;
        
        // go till that node
        //curr will be pointng to last node
        cur->next = head;
        k = k % len; //if k>=len,it get reduced to lesser than length
        k = len - k; //we need to find the len-k node from the start
        while (k--) cur = cur->next; //automatically move from head , till k reduces to len - k node
        
        //once it reach,replace the head
        // make the node head and break connection 
        head = cur->next; //replae the head to curr of next,coz curr will be at len-k node
        cur->next = NULL; // last node points to null
        return head; //of that new linked list
    }
};
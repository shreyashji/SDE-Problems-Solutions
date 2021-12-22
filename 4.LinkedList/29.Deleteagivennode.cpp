/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
Basically we are just copying node's next value to itself
Input: 1->2->3->4->5 ->6
given node = 4
output: 1->2->3->5->6

1. in first step: node->val becomes node's next ki value i.e 4 becomes 5
1->2->3->5->5->6
2. in 2nd step: node points to node's next next i.e 5->6
1->2->3->5->6
*/
class Solution {
public:
    void deleteNode(ListNode* node) { //1-4-2-3-null
        node->val = node->next->val; //assign 3 to 2 //1-4-3-
        node->next = node->next->next; //assign 1-4-3-null
    }
};
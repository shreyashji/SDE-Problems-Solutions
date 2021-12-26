/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//time = ~near about O(n) 
// space = o(1)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) //edge cases, ll is null,only one element
            return NULL;
        
        ListNode *slow  = head;
        ListNode *fast  = head;
        ListNode *entry = head;
        
        while(fast->next && fast->next->next) { //define collison points,move till fast reaches null
            slow = slow->next; //move slow by 1
            fast = fast->next->next; //move fast by 2
        if(slow==fast) {    // there is a cycle,collison point
            while(slow !=entry) {  // found the entry location
                //move slow & fast by one unit each,till they are not equal
                slow = slow->next;
                entry = entry->next;
                }
            return entry; //return collison points
            }
        }
        return NULL; //if fast reaches null,means there was never ever a cycle
    }
};
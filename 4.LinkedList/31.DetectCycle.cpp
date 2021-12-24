/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//time = o(n)
//space=o(1)
class Solution {
public:
    bool hasCycle(ListNode *head) {
        //if null or sinle element in ll then there is no cycle
        if(head == NULL || head->next == NULL)
            return false;
        
        ListNode *slow = head;
        ListNode *fast = head;
        
        //till fast reaches null,fast is going to reach null
        //stop if it is last node && second last node there is a null,stop at there
        while(fast->next && fast->next->next){
            fast=fast->next->next; //fast by two pointers
            slow=slow->next; //slow by 1 ptrs
            if(fast==slow)
                return true;      
        }
    return false;
    }
};
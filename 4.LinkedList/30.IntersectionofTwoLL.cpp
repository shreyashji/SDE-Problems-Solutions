/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//time = O(2m) 2 iteration, at worst case
//space= 0(1)
//concise
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB==NULL) return NULL;
        ListNode *a = headA;
        ListNode *b = headB;
        
        //if a & b have different length, then we will stop the loop after second iteration
        //even if there are no intersecting nodes,both will be null at the same time
        while(a != b){
            //for the end of first iteration,we just reset the pointer to the head of another ll
            a = a == NULL ? headB : a->next;//shifting to head of other(2nd) linked list
            b = b == NULL ? headA : b->next; //shifting to head of other(1st)) linked list
        }
        return a;    
    }
};
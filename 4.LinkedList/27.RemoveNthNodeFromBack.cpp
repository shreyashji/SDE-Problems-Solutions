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
//time = O(n) fast moves by n iteration
//space= o(1)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* start = new ListNode(); //dummy node
        start->next = head; //assign it to head of ll
        ListNode* fast = start;
        ListNode* slow = start;
        
        for(int i=1; i<=n; i++)  //move fast by n iteration
            fast = fast->next;
        
        while(fast->next !=NULL){ //move fast & slow together by 1 step till fast pointer doesnt reaches the last node of ll
            fast = fast->next;
            slow = slow->next;
        }
        //once it reaches last node
        //break the link
        
        slow->next = slow->next->next;
        return start->next; //dummy node head will be new head of our linked list
    }
};
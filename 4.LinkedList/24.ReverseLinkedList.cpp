/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next =head->next;;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
//time = O(N) n nodes to perform n iteration
//space= O(1)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *newHead = NULL; //DUMMY NODE
        while(head!=NULL){ //traverse till head not equals to null
            ListNode *next = head->next; //we take our next and pointed to the immediate  next of head
            head->next = newHead; //broke the link and pointed to the dummy node,
            newHead=head; //dummy node  will move to head
            head=next; //head move to next
            //till this ,is one iteration
        }
        return newHead;
    }
};
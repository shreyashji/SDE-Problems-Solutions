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
//time = O(n/2) to find middle +  O(n/2) to reverse right half of ll +  O(n/2) to compare right & left half
//space = O(1)
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL) 
            return true;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast->next != NULL && fast->next->next !=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        //finding middle of ll till here
        //from here slow will be at middle 
        slow->next= reverseList(slow->next); //reverse right half of slow
        slow = slow->next;//moves slow,pointing to first position of right half
        
        while(slow !=NULL){
            //start moving slow and head
            if(head->val != slow->val)
                return false;
            head = head->next; //only checking ll is palindrome or not,using head coz we are not remodifying the ll,thats why we are not using any dummy node as exta node
            slow = slow->next;
        }
        return true;
    }
    
    //reverse linked list node
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = NULL; 
        ListNode *next = NULL;
        while(head!=NULL){ //traverse till head not equals to null
            next = head->next;//we take our next and pointed to the immediate next of head
            head->next = pre; //broke the link and pointed to the dummy node,
            pre=head; //dummy node  will move to head
            head=next; //head move to next
            //till this ,is one iteration
        }
        return pre;
    }
};
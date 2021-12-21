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
//time = O(n) traverse largest of ll, max of n1,n2 length of l1,l2
//space= o(n)
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(); //create a dummy node
        ListNode *temp = dummy; //create a temp which copies dummy node
        int carry = 0;
        while( l1 != NULL || l2 != NULL || carry){ //iterate till all of them become null,null, 0
            int sum=0; //at the start of every iteration
             if(l1 != NULL){
                 sum += l1->val; //add it to the sum
                 l1=l1 -> next; //move l1 to next
             }
            if(l2 != NULL){
                 sum += l2->val;
                 l2 =l2 -> next;
             }
            sum += carry; //add carry to sum
            carry = sum / 10; //carry will always reinitialize to sum /10
            ListNode *node =  new ListNode(sum%10); //create  a new node, value assign to that will be sum modulo 10
            temp ->next = node; //point next link of temp to the current node that we created
            temp = temp ->next; //move temp to next
        }
        return dummy->next; //head of that ll, which will have summation of two numbers        
    }
};
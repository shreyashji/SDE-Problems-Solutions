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
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || k==1) return head; //empty ll or single node ll
        
        ListNode* dummy= new ListNode(0); //create dummy node
        dummy->next=head; //point next of dummy node to head of ll
        
        ListNode *cur = dummy, *nex=dummy , *pre=dummy; //declaring 3 diff nodes
        int count=0;
        
        while(cur->next !=NULL){ //counting no. of nodes we have in ll
            cur = cur->next;
            count++;
        }
        
        while(count>=k){ //till count >=k
            
            cur = pre->next; //always,first node of that ll of size 3,dummy->next will be 1st node at 1st time
            nex = cur->next; //nex will be 2nd node of the ll,of a group size k or 3
            
            for(int i=1 ; i<k; i++){ //k-1 iterations
                cur->next= nex->next;
                nex->next = pre->next;
                pre->next=nex;
                nex=cur->next;
            }
            pre = cur;//last node of the reversed  group of size 3
            count -= k; //reduce k from count
        }
        return dummy->next;
    }
};
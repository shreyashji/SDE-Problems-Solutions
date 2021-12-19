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
//time= O(n1+n2) legth of first & second linked list
//space=O(1) inplace 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1==NULL) return l2;
        if (l2==NULL) return l1;
        if(l1->val > l2->val) std::swap(l1,l2); //inital swap l1 going to be smaller,one ll having first value smaller
            ListNode *res=l1;  //assign res to l1 or remember head of merged sorted list
            while(l1 !=NULL && l2 !=NULL){ //iterate till either of l1 or l2
                ListNode *temp=NULL; //for every iteration
                while(l1 !=NULL && l1->val <= l2->val) { //iterate till l1 doesnt reaches null or the val still lesser or equal to l2 value 
                    temp=l1; //remember the node in temp,last node which is smaller
                    l1=l1->next;// move l1
                }
                temp->next =l2;// last node which is smaller,simply point it to l2
                std::swap(l1,l2); //swap l1 && l2 before every iteration
            }
        return res;  //after all iteration over return res which is head of newly merged sorted ll
    } 
};
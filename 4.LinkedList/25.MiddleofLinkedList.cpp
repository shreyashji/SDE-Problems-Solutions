/*
1st approach two loops,one for traversal to find n,do n/2,2nd loop for going to middle or n/2 element
time=o(n)+O(n/2) one traversal + 2nd loop to go till middle
space=O(1)
class Solution {
public:
	ListNode* middleNode(ListNode* head) {
    	int n = 0;
    	ListNode* temp = head;
    	while(temp) {
        	n++;
        		temp = temp->next;
    	}
   	 
    	temp = head;
   	 
    	for(int i = 0; i < n / 2; i++) {
        		temp = temp->next;
    	}
   	 
    	return temp;
	}
};
*/

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
//tortoise method slow and fast pointer,slow move by one, fast move by 2
//time= O(N/2) fast moves by 2 and length of ll is n so n/2
//space=O(1)
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        //it crosses the boundary,fast tortoise till it reaches last node
        while(fast != NULL && fast->next != NULL){
            slow=slow->next;
            fast= fast->next->next;
        }
        return slow; //slow will be our middle
    }
};
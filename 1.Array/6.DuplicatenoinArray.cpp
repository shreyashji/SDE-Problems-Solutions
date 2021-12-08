class Solution {
public:
//time = O(N)
//space = O(1)
    int findDuplicate(vector<int>& nums) {
        int slow=nums[0];
        int fast=nums[0];
        do{
            slow=nums[slow]; //increasing slow pointer  by 1
            fast=nums[nums[fast]]; //increasing fast pointer  by 2
        }while(slow!=fast);   //unless they meet at any given point, coz they are bound to meet
        //so after they meet wee keep slow pointer where it was and
        //and move the fast pointer to the first position 
        fast=nums[0];
         //and start moving the slow and fast pointer, unless and until they meet
        while(slow!=fast){
            slow=nums[slow]; //moving slow by 1
            fast=nums[fast]; //moving fast by 1
        }//till they meet either slow or fast will be our answer
        return slow;
    }
};
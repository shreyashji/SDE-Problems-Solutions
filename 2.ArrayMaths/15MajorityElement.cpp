class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;      //init count as 0
        int candidate=0;  //init candidate or element as 0 
        
        for(int num:nums){ //iterate over the data structure nums
            if(count==0){  //if count =0  ,we initilize candidate as num
                candidate=num;
            }
            if(num == candidate) //if numm==candidate,incr count to 1,and if not decr count as -1
                count +=1;
            else
                count -=1; 
        }
        //at the end which candidate is stored return that will be our majority element
        return candidate;        
    }
};
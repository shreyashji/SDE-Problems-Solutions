class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       vector<int> mpp(256, -1); //frequency map,why 256,string can have 256 different characters
        int left=0,right=0;
        int n=s.size();
        int len=0;
        while(right<n){ //iterate till last index
        //if the char at right index exist or not= if does exist i take it and do a +1,
        //but i dont update it,unless it is greater than left
        //basically if it gonna lies to the left i am not gonna update it,coz its not in the range l-r
            if(mpp[s[right]]!=-1) left = max (mpp[s[right]] +1,left);
            //update the current index last seen at the hashmap
            mpp[s[right]]=right;
    //find the range of my current substring,if it is greater than the previous lenght we computed,simply update on the lenth variable
            len=max(len,right-left+1);
            right++; //move right to next
        }
        return len; //after complt iteration, this will return the length of longest substring
    }
};
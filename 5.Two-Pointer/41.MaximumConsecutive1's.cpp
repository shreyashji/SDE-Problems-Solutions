//time =O(N)
//space = O(1)

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
      int cnt = 0;
      int maxi = 0;
        
      for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 1) {
          cnt++; //incr cnt if find 1
        } 
          else {
          cnt = 0;// make cnt =0 if find 0
        }//check for 1 and 0
           maxi = max(maxi, cnt); //update maxi with maximum value of curnt and maxi
      }
      return maxi;
    }
};
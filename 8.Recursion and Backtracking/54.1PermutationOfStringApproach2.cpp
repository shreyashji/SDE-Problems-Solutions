class Solution {
    //time = N! for permutation  * N for looping o to n
    //space = 
    //auxilary = O(N) recursion depth and O(N!) for returining ans
 private:
    void recurPermute(int index, vector < int > & nums, vector < vector < int >> & ans) {
      if (index == nums.size()) { //pointer reaches the end,taken decision for every index
        ans.push_back(nums); //take nums arr and put it into ans
        return;
      }
      for (int i = index; i < nums.size(); i++) { //go from index to n-1
        swap(nums[index], nums[i]); //swap
        recurPermute(index + 1, nums, ans);//fro next state
        swap(nums[index], nums[i]);//reswap for next next swap will not consider,simple backtracking
      }
    }
  public:
    vector < vector < int >> permute(vector < int > & nums) {
      vector < vector < int >> ans; //store permutation
      recurPermute(0, nums, ans);//recr function start with 0,passing arr,data structure
      return ans;
    }
};
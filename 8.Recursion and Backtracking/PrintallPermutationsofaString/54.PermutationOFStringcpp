class Solution {
    //time = N! for permutation  * N for looping o to n
    //space = O(N) for storing in data structue +O(N) for map extra
  private:
    void recurPermute(vector < int > & ds, vector < int > & nums, vector < vector < int >> & ans, int freq[]) {
      if (ds.size() == nums.size()) {
        ans.push_back(ds);
        return;
      }
      for (int i = 0; i < nums.size(); i++) {
        if (!freq[i]) {
          ds.push_back(nums[i]);
          freq[i] = 1; //marked as picked in frequency map
          recurPermute(ds, nums, ans, freq); //recr to pick other elements
          freq[i] = 0; //marked as unpicked in frequency map,come back after recr
          ds.pop_back();//through element out, after comeback from recr
        }
      }
    }
  public:
    vector < vector < int >> permute(vector < int > & nums) {
      vector < vector < int >> ans;
      vector < int > ds;
      int freq[nums.size()];
      for (int i = 0; i < nums.size(); i++) freq[i] = 0;
      recurPermute(ds, nums, ans, freq);
      return ans;
    }
};
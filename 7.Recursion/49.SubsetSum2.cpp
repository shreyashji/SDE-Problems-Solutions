//time =2^N genrating subsets * N for copying subsets
//space =O(2^N) * O(K)
//auxilary space for recursive call = O(N) depth of recursion
class Solution { 
    //no need to write base case
private:
    void findSubsets(int ind, vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans) {
        ans.push_back(ds);//taking data structure and putting it into answer,extra time deep copy here
        for(int i = ind;i<nums.size();i++) {
            //if equal to previous,but if 1st index pick it 
            if(i!=ind && nums[i] == nums[i-1]) continue; 
            ds.push_back(nums[i]);  //1. put it into ds,right after that call recursion
            findSubsets(i+1, nums, ds, ans); 
            ds.pop_back(); //remove the guy we have added before coming back
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans; //answer array,store all the subsets genrated
        vector<int> ds;  //empty data structure
        sort(nums.begin(), nums.end());  //sort the given array,coz duplicates will not be together
        findSubsets(0, nums, ds, ans);//at o index ,nothing got picked
        return ans;  
    }
};
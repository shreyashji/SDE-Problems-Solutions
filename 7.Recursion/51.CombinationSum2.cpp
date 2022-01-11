class Solution {
 public: 
//time=  2^n (all unique elements) * K (ans add to ds)
//space = K (average length k operation) * x (x combination)
    void findCombination(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int>&ds) {
        if(target==0) {
            ans.push_back(ds);
            return;
        }        
        for(int i = ind;i<arr.size();i++) {
            if(i>ind && arr[i]==arr[i-1]) continue;  //avoid picking same element twice
            //i>ind its not the first time picking
            if(arr[i]>target) break;  //if exceeds target
            ds.push_back(arr[i]); //pickup  & call recursion move to i+1
            findCombination(i+1, target - arr[i], arr, ans, ds); 
            ds.pop_back(); 
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());//sort in lexicographical order
        vector<vector<int>> ans; //store combination data strcture 
        vector<int> ds; //ds to use in recrursion to genrate all possible combination
        findCombination(0, target, candidates, ans, ds);  //call recursion with initial index 0
        return ans; 
    }
};
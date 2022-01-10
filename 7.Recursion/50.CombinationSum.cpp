// time = 2^T (2^N diff ways coz those many diff recr call made)* K (avrg length of every combination genrated i k)
//space = K(avrg length) * x (x combination) [dependent on no. of combination] 
class Solution {
public:
    void findCombination(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int>&ds) {
        if(ind == arr.size()) {
            if(target == 0) {
                ans.push_back(ds); //it does take a linear time complexity
            }
            return; 
        }
        // pick up the element 
        if(arr[ind] <= target) { //only pickup if lesser than target if,
            //yes add in our data structure
            ds.push_back(arr[ind]); //again for same index,and reduce the target by the value we had picked up
            findCombination(ind, target - arr[ind], arr, ans, ds); 
            ds.pop_back(); //remove the element which is added
        }  
        //next recr call to try out all combination
        findCombination(ind+1, target, arr, ans, ds);     
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;  //store all combinations
        vector<int> ds; 
        findCombination(0, target, candidates, ans, ds); 
        return ans; 
    }
};
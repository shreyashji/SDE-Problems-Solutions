class Solution {
public:
        vector<int> twoSum(vector<int>& nums, int target){ 
        vector<int> ans; //
        unordered_map<int,int> mpp; // declaring hash taable
        for (int i = 0; i < nums.size(); i++){ //iterate in nums vector
            if(mpp.find(target - nums[i]) != mpp.end()){
                //while we go in we check target -nums[i] exist in the hash table or not ,if it does it will never point to the end of the hash table => ! =mpp.end()
                ans.push_back(mpp[target - nums[i]]); // Get the index or value from the map of the remaining element,store it in ans
                ans.push_back(i); //current index i
                return ans; //exactly one solution will be there
            }
    // if if condition not executed,store the current nums[i] in the hash table => key[nums[i]],index
        mpp[nums[i]]=i;
        }
    return ans;//if dont get pair return ans,empty vector,means no answer
    }
};
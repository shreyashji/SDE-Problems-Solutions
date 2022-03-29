//lambda function in c++ [&] (parameter) {return expresion}
//the lambda function defines  how to sort
//1.if two no. have different freq ,the one with smaller freq goes first in our logics
//2.otherwise ,the one lexicographically greater goes first

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int>umap;//store no. with freq in unordered map
        for(auto x: nums){
            umap[x]++;
        }//we have count for all no.
        
        sort(nums.begin(), nums.end() , [&](int a , int b) //labda function
             //if freq is diff umap[a] != umap[b] then print whose freq is smaller
             //if freq is same ,we will return whose elemnt is greater  a > b
             { return  umap[a] != umap[b] ? umap[a] < umap[b] :  a > b ; } );
        
        return nums;
    }
};
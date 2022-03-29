//https://www.youtube.com/watch?v=zX9k1XvVUXI&list=PLzjZaW71kMwQ-D3oxCEDHAvYu8VC1XOsS&index=16&t=50s
//https://leetcode.com/problems/group-anagrams/

//sort the word and push it into unordered map
/*
strs = ["eat","tea","tan","ate","nat","bat"]
sorted word is key,jisko sort karne par aya wo value eat(push in vector)
,second word tea if sort aet match with key aet if match push in vector)
we have to return vector which contains all values not keys
key->value
aet->eat ,tea, ate
ant->tant,nat
abt->bat
//print in any order

*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>>umap;
        
        for(auto x: strs){//pick up every word,vecttor uthaya,aur strs vector me jo bhi ha usko x me dal diya,automatical detects type of x
            string temp = x;//store in temp so we cant change the originality of string,now sort the string
            sort(x.begin(), x.end());
            umap[x].push_back(temp);//key pushed to umap
        }
      //umap have key & value
        for(auto x : umap){
            ans.push_back(x.second);
        }
        return ans;
    }
};
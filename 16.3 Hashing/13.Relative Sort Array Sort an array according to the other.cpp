/*
Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
Output: [2,2,2,1,4,3,3,9,6,7,19]

1. create  map of arr1 
1->2
2->2
3->1
5->1
6->1
7->1
8->2
9->1
2. iterate elemnts from arr2
    we find x in map,if find remove after printing
    then print x as many times as it prsnt in arr1
    fro remaining elemt in amp print as its is from map
*/

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans;
        map<int, int>mp;
        
        for(auto x: arr1) //to insert elemnt of arr1 in map
            mp[x]++;
        
        for(auto temp :  arr2){//take elemnt of arr2
            if(mp.find(temp)!=mp.end()){//value is temp,count is no. of times prsnt
                auto x  = mp.find(temp);
                int count = x->second;  // 5->2
                
                vector<int>v(count, temp); // v = 5 5 
                
                ans.insert(ans.end(), v.begin(), v.end());
                mp.erase(temp);
            }
        }
        
        for(auto x : mp){ //for remaining elemnt of map
            int ele = x.first; 
            int count = x.second;
            vector<int>v(count, ele);
            ans.insert(ans.end(), v.begin(), v.end());
        }
        
        return ans;
    }
};
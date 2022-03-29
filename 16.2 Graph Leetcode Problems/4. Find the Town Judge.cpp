//https://leetcode.com/problems/find-the-town-judge/

class Solution {
public:
    //indegree -outdegree = n-1
    //indegree should be n-1 & outdegree 0,only inserting ,no outgoing
   // [a,b]  1->2<-3 total n=3 ,trust count n-1=2 correct 1 slould not trust nobody
    int findJudge(int n, vector<vector<int>>& trust) {//[1 to 3],[1 to 4]
        //only needed indegree & indegree should be n-1
        vector<int>data(n+1, 0); //for indegree 
        for(auto x: trust)//
        {
            data[x[0]]--; //outdegree --,x[0,1] is index
            data[x[1]]++; //indegree ++
        }
        //now vector contains and indgree which is n-1 return index
        for(int i=1; i<=n; i++){ //traverse vector 
            int x = data[i]; //return index
            if(x == n-1)
                return i;
        }
        return -1;
    }
};
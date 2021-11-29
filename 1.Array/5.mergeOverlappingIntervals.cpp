class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) { //we are returning vectors of vectors
        //we solved with using vectors of pairs
        vector<vector<int>> mergedintervals; // our empty data structure or our answer that willreturn 
        if(intervals.size()==0){ //our edge case
            return mergedintervals; //empty ans
        }
        sort(intervals.begin(),intervals.end());
        //instead of pair we taken vector int
        vector<int> tempinterval= intervals[0];
        for(auto it : intervals){
            if(it[0]<=tempinterval[1]){ //2<=3
                tempinterval[1]=max(it[1],tempinterval[1]);
            }
            //if not merging
            else{
                mergedintervals.push_back(tempinterval);
                tempinterval=it; //reassign the value interval into tempinterval
            }
        }
        mergedintervals.push_back(tempinterval);
        return mergedintervals;
    }
};
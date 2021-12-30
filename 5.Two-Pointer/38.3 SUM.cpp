

//time= o(N) TO FIND ALL A + o(N) linear two pointer appproach
//SPACE= o(1) ==> O(M)returning answer genrally this dont considered as space,m NO OF TRIPLETS 
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& num) {
        vector<vector<int>> res; 
        sort(num.begin(), num.end()); 
        // moves for a
        for (int i = 0; i < (int)(num.size())-2; i++) { //MOVE A,run till 3rd last element
            //at 3rd last,2nd last will be 2nd guy of triplet,last will be lats guy of triplet
               if (i == 0 || (i > 0 && num[i] != num[i-1])) {
                   //i==0 first guy || not equivalent to previous if yes enter loop
                //left most pointer ,right most pointer ,-a below
                int lo = i+1, hi = (int)(num.size())-1, sum = 0 - num[i];
                
                while (lo < hi) {
                    if (num[lo] + num[hi] == sum) {//b+c=-a
                        
                        vector<int> temp; 
                        temp.push_back(num[i]); 
                        temp.push_back(num[lo]); 
                        temp.push_back(num[hi]); 
                        res.push_back(temp);
                        
                        while (lo < hi && num[lo] == num[lo+1]) lo++; //move low till equialent
                        while (lo < hi && num[hi] == num[hi-1]) hi--;// same for right in reverse direction 
                        //move low to next ,which is not equivalent
                        lo++; hi--; //all duplicated ignore for low and high
                    } 
                    //sum lesser than -a,move left ptr,reaches somewhere near sum
                    else if (num[lo] + num[hi] < sum) lo++;
                    else hi--; //greater than sum case,move high ptr towards left
               }
            }
        }
        return res;//vector storing all unique triplet
    }
};
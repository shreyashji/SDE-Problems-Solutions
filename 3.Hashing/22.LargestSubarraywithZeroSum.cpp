//time = O(nlogn) traversal+ hashmap
//space= O(n) storing all summation

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    { 
        unordered_map<int,int> mpp; //creating a map
        int maxi=0; //store maxi longest seq length
        int sum=0; //store prefix sum
        //linearly iterate in array
        for(int i=0; i<n; i++){
            //and keep on adding A[i] to sum
            sum +=A[i];
            //check if prefix is equivalent to zero,if it is we can say that from first index to
            //current index that sum is giving zero,we can say,that will be the longest subarray till now
            //and simply update maxi to i+1,standing at index i obviouly length will be i+1
            if(sum==0){
                maxi = i+1;
            }
            //if sum is not zero ,check if that prefix summ previously existed int he hashmap or not
            
            
            else{
                if(mpp.find(sum) != mpp.end()){
                    //if did get it simply get the index, where did you get that
                    //and subtract it with current index to get the length of subarray which is giving us the zero sum
                    //compare it with maximum,update it if it exceeds                    
                    maxi=max(maxi, i-mpp[sum]);
                }
                //if prefix sum doesnt appear previously,simply put it in hash map
                //along with index
                else{
                    mpp[sum]=i;
                }
            }
        }
        //once done iterating,simply return the maximum,that will be our ans
        return maxi;
};

 //unordered map O(N) worst
//time = O(NlogN) ,
//space= O(N) hashmap
int Solution::solve(vector<int> &A, int B)
{
    map<int,int> freq; //storing key value pair
    int cnt=0;
    int xorr=0;
    for(auto it:A){ //linearly traverse in vector
        xorr=xorr^it; //compute the prefix xorr

        if(xorr==B){  //if prefix array giving the subarray xorr B
            cnt++; //if giving increase the count or prefix subarray giving me the xorr
        }

        if(freq.find(xorr^B) != freq.end()) //check it in hashmap if does exist
            cnt +=freq[xorr^B]; //increase the count by how many no. of times it exist

        freq[xorr]+=1; //insert it in hashmap,prefix xorr 
    }
    return cnt; //total no. of subarrays,giving xorr as b
}
// ididnt understand this clearly
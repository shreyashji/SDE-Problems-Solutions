//https://www.codingninjas.com/codestudio/problems/house-robber_839733?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1

long long int maximumNonAdjacentSum(vector<int> &nums){
    long long int n=nums.size();
    long long int prev = nums[0];
    long long int prev2 =0;
    for(int i=1; i<n; i++){
        long long int pick = nums[i];
        if(i>1)
            pick += prev2; //
        long long int nonPick = 0 + prev; //
        
        long long int cur_i = max(pick, nonPick); //
        prev2 = prev; //
        prev= cur_i;  //
    }
    return prev;
}

long long int houseRobber(vector<int>& valueInHouse)
{
   vector<int> temp1,temp2;
    long long int n = valueInHouse.size();
    if(n==1) return valueInHouse[0]; //if arry contaisn only single element
    for(int i=0; i<n; i++){
        if(i!=0) temp1.push_back(valueInHouse[i]); //temp1 contains everything apart from 1st element
        if(i != n-1) temp2.push_back(valueInHouse[i]);//temp2 contains everything apart from last element
    }
    return max(maximumNonAdjacentSum(temp1),maximumNonAdjacentSum(temp2));
}
/*
class Solution {
public:
     int maxSubArray(vector<int>& nums) {
        int sum=0, maxi=INT_MIN;
        for(int i=0; i<nums.size(); i++){ // iterate over array or vector
            sum=sum+nums[i]; //add it to sum
            maxi=max(sum,maxi); //if greater update it 
            if(sum<0) sum=0; //if sum goes less than 0 make it 0
        }
        return maxi;
    }
};

*/


#include<iostream>
#include<climits>
using namespace std;
//time= O(N)
//space= O(1)
int maxSubArraySum(int a[], int size)
{
    int max_so_far = INT_MIN, max_ending_here = 0;
 
    for (int i = 0; i < size; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
 
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}
 
/*Driver program to test maxSubArraySum*/
int main()
{
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a)/sizeof(a[0]);
    int max_sum = maxSubArraySum(a, n);
    cout << "Maximum contiguous sum is " << max_sum;
    return 0;
}
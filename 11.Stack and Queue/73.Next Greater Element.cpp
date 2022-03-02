#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
// [i%n] coz its circualr array 
//time = O(2n+2n(total iteration across the for loop will be 2n)) ~~O(N) soltion
//space= O(N) near about fro storing answer
//if 1st variant comes make 2n-1 to n,if circular 2n-1
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size(); 
        vector<int> nge(n, -1);
        stack<int> st; 
        for(int i = 2*n-1;i>=0;i--) { //copied the array twice,running 2n times
        //while loop not always running 2n times,throughout running 2n times
            while(!st.empty() && st.top() <= nums[i%n]) { //remove smaller elements,not empty remove all elements that are smaller than equal to a[i]
                st.pop(); //remove 
            }
            if(i<n) {
                if(!st.empty()) 
                    nge[i] = st.top(); 
                else 
                    nge[i] = -1;
            }
            st.push(nums[i%n]);
        }
        return nge; 
    }
};
int main() {
  Solution obj;
  vector < int > v {5,7,1,2,6,0};
  vector < int > res = obj.nextGreaterElements(v);
  cout << "The next greater elements are" << endl;
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
}
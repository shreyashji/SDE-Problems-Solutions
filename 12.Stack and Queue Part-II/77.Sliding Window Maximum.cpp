#include<bits/stdc++.h>
using namespace std;
//time= O(n) + O(n)
//space= O(k) size of space
vector < int > maxSlidingWindow(vector < int > & nums, int k) {
  deque < int > dq;
  vector < int > ans;
  for (int i = 0; i < nums.size(); i++) { //iterate through from 0 to arry size
    if (!dq.empty() && dq.front() == i - k) dq.pop_front();//all out of bound will be removed
//length is k ,i is standing at, if i-k element is there then pop front
    while (!dq.empty() && nums[dq.back()] < nums[i])//storing in decreasing fashion,remove all the smaller element<a[i]
      dq.pop_back();

    dq.push_back(i);//crnt index taken at deque
    if (i >= k - 1) ans.push_back(nums[dq.front()]);
  }
  return ans;
}
int main() {
  int i, j, n, k = 3, x;
  vector < int > arr {4,0,-1,3,5,3,6,8};
  vector < int > ans;
  ans = maxSlidingWindow(arr, k);
  cout << "Maximum element in every " << k << " window " << endl;
  for (i = 0; i < ans.size(); i++)
    cout << ans[i] << " ";
  return 0;
}
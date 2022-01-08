//for every index we have 2 ways pickit or not,if n indexes 2 ways for every one of them
//time = 2^N + 2^Nlog(2^N)  for sorting the ds
// space = 2^n
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void solve(int ind, vector < int > & arr, int n, vector < int > & ans, int sum) {
      if (ind == n) { //reach the end ,we have sum
        ans.push_back(sum); //store it in our answer ds
        return;
      }
      //element is picked
      //moveto next,summmation got increased,
      solve(ind + 1, arr, n, ans, sum + arr[ind]);
      //element is not picked
      //moveto next,summation as its is
      solve(ind + 1, arr, n, ans, sum);
    }
  vector < int > subsetSums(vector < int > arr, int n) {
    vector < int > ans;
    solve(0, arr, n, ans, 0);
    return ans;
  }
};
int main() {
  vector < int > arr{3,1,2};
  Solution ob;
  vector < int > ans = ob.subsetSums(arr, arr.size());
  sort(ans.begin(), ans.end()); //sort ds in creasing order
  cout<<"The sum of each subset is "<<endl;
  for (auto sum: ans) {
    cout << sum << " ";
  }
  cout << endl;

  return 0;
}
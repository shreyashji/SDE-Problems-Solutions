#include <bits/stdc++.h>
using namespace std;
class Solution {
    //need some skill to explain this solution ,previousone is simple to explain
    //time = O(n)+O(n)
    //space = (n)
  public:
    int largestRectangleArea(vector < int > & histo) {
      stack < int > st;
      int maxA = 0; //maximum aread
      int n = histo.size();//get size of array
      for (int i = 0; i <= n; i++) { //if empt & last index,operate by removing the greater elements
        while (!st.empty() && (i == n || histo[st.top()] >= histo[i])) {
        //compute the maximum area
          int height = histo[st.top()];
          st.pop();
          int width;
          if (st.empty())
            width = i;
          else
            width = i - st.top() - 1;
          maxA = max(maxA, width * height);
        }
        st.push(i);
      }
      return maxA;
    }
};
int main() {
  vector < int > histo = {2, 1, 5, 6, 2, 3, 1};
  Solution obj;
  cout << "The largest area in the histogram is " << obj.largestRectangleArea(histo) << endl;
  return 0;
}
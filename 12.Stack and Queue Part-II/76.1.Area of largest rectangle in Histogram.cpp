#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
  //not most optimal solution
  //time =O(n)+O(n) for left,O(n)+O(n) for right~~O(n) (couple of passes)
  //space=O(3n) where 3 is for the stack, left small array and a right small array
    int largestRectangleArea(vector < int > & heights) {
      int n = heights.size();
      stack < int > st;
      int leftsmall[n], rightsmall[n];
      //to copute the left small
      for (int i = 0; i < n; i++) {
        while (!st.empty() && heights[st.top()] >= heights[i]) {//if elemnts that are greater than crnt histogram height
          st.pop();//then remove that from the stack
        }
        if (st.empty())//if stack is empty by any chance,means remoed all the elements from stack indeed all elements are greater
          leftsmall[i] = 0;//make sure leftsmaller boundry will be 0
        else
          leftsmall[i] = st.top() + 1;//if any element left that will be my previous smaller element
        st.push(i);//curent index has to go in stack
      }
      // clear the stack to be re-used
      //next smalller element to the right
      while (!st.empty())
        st.pop();
    //iterate from back
      for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && heights[st.top()] >= heights[i])
          st.pop();

        if (st.empty())
          rightsmall[i] = n - 1;//last element to be my boundry
        else
          rightsmall[i] = st.top() - 1;//will be my right smaller element

        st.push(i);
      }
      int maxA = 0;
      for (int i = 0; i < n; i++) {
        maxA = max(maxA, heights[i] * (rightsmall[i] - leftsmall[i] + 1));
      }
      return maxA;
    }
};
int main() {
  vector<int> heights = {2, 1, 5, 6, 2, 3, 1};
  Solution obj;
  cout << "The largest area in the histogram is " << obj.largestRectangleArea(heights); 
  return 0;
}
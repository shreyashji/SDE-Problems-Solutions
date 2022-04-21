#include <bits/stdc++.h>

using namespace std;

void lcs(string s1, string s2) {

  int n = s1.size();
  int m = s2.size();

  vector < vector < int >> dp(n + 1, vector < int > (m + 1, 0));
  for (int i = 0; i <= n; i++) {
    dp[i][0] = 0;
  }
  for (int i = 0; i <= m; i++) {
    dp[0][i] = 0;
  }

  for (int ind1 = 1; ind1 <= n; ind1++) {
    for (int ind2 = 1; ind2 <= m; ind2++) {
      if (s1[ind1 - 1] == s2[ind2 - 1])
        dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
      else
        dp[ind1][ind2] = 0 + max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
    }
  }
  //above code is same for lcs tabulation DP-25
    //TAKE LENGTH
    //TIME = O(N*M) NEED TO use ENTIRE 2D ARRAY TO BACKTRACK,There are two nested loops
    //space = O(N*M),We are using an external array of size ‘N*M’. Stack Space is eliminated.
  int len = dp[n][m]; //DP LENGTTH
  int i = n;
  int j = m;

  int index = len - 1;
  string str = ""; //CREATE STRING S
  for (int k = 1; k <= len; k++) { 
    str += "$"; // dummy string assign dummmy strings  $$$
  }

  while (i > 0 && j > 0) { 
    if (s1[i - 1] == s2[j - 1]) { //WHEN CHAR MATCH MATCH
      str[index] = s1[i - 1]; //STORE THE STRING  INDEX IN ARRAY
      index--; //MOVE INDEX TO PREVIOUS,so next matching string /char will be store
      i--; //MOVE DIAGONAL
      j--; //MOVE DIAGONAL
    } 
    else if (s1[i - 1] > s2[j - 1]) {
      i--; //MOVE ABOVE  
    } 
    else j--;//FROM LAST COL TO LAST - 1 COLN 
  }
  cout << str;
}

int main() {

  string s1 = "abcde";
  string s2 = "bdgek";

  cout << "The Longest Common Subsequence is ";
  lcs(s1, s2);
}
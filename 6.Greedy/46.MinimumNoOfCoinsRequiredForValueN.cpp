//time =  o(V) not go upto O(v) where v is value which are forming from coins
//space = O(1)

#include<bits/stdc++.h>
using namespace std;
int main() {
  int V = 49;
  vector < int > ans; //store our combination
  int coins[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
  int n = 9; //size of arr
  for (int i = n - 1; i >= 0; i--) {  //start iterating from back 
    while (V >= coins[i]) { //if denomination coin is lesser than the current value tha we have
      V -= coins[i]; //subtracting and whatever adding denomination count taking of adding into combination
      ans.push_back(coins[i]);
    }
  }
  //conce completely executed prin the answer
  cout<<"The minimum number of coins is "<<ans.size()<<endl;
  cout<<"The coins are "<<endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }

  return 0;
}
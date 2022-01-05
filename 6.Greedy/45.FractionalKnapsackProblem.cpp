//time = O(NlogN) for sorting + N for iteration
//space= O(1)

#include <bits/stdc++.h>
using namespace std;
struct Item {
   int value;
   int weight;
};
class Solution {
   public:
   //sort according to value/weight in descending order
      bool static comp(Item a, Item b) {
         double r1 = (double) a.value / (double) a.weight; 
         double r2 = (double) b.value / (double) b.weight;
         return r1 > r2;
      }
   // function to return fractionalweights
   double fractionalKnapsack(int W, Item arr[], int n) {

      sort(arr, arr + n, comp);

      int curWeight = 0; 
      double finalvalue = 0.0; //count value

      for (int i = 0; i < n; i++) {
          //if fitting completely currweight +item picking is fit in knapsack
         if (curWeight + arr[i].weight <= W) {
            curWeight += arr[i].weight; //add to curr weight
            finalvalue += arr[i].value; //take entire value add to final value
         } else { //if not fitting in knapsack completely,tak efraction of that
            int remain = W - curWeight; //remaining amount left,whatever remain multiply that into value/weight of currnt item
            //and add it to final value
            finalvalue += (arr[i].value / (double) arr[i].weight) * (double) remain;
            break;//after this kanapsack is filled up ,break it
         }
      }
      //oncce done for all 
      return finalvalue; //max value here,simply return it
   }
};
int main() {
   int n = 3, weight = 50;
   Item arr[n] = { {100,20},{60,10},{120,30} };
   Solution obj;
   double ans = obj.fractionalKnapsack(weight, arr, n);
   cout << "The maximum value is " << setprecision(2) << fixed << ans;
   return 0;
}
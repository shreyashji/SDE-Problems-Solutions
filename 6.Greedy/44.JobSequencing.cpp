//time = O(NlogN) for sorting + O(N*M) n job id,m maxmim deadline iterate all jobids&checking from last deadline to 1st deadline if empty& perform 
//job on that day
//space =O(M) maximum deadline for any job

#include<bits/stdc++.h>
using namespace std;
// A structure to represent a job 
struct Job {
   int id; // Job Id 
   int dead; // Deadline of job 
   int profit; // Profit if job is over before or on deadline 
};
class Solution {
   public:
      bool static comparison(Job a, Job b) {
         return (a.profit > b.profit);
      }
   //Function to find the maximum profit and the number of jobs done
   pair < int, int > JobScheduling(Job arr[], int n) {

      sort(arr, arr + n, comparison);
      int maxi = arr[0].dead;
      for (int i = 1; i < n; i++) { //find maximum deadline
         maxi = max(maxi, arr[i].dead);
      }

      int slot[maxi + 1]; //create an array of size that  maximum 

      for (int i = 0; i <= maxi; i++)
         slot[i] = -1; // initialized with -1 coz no jobs prformed initially

      int countJobs = 0, jobProfit = 0;

      for (int i = 0; i < n; i++) { //iterate over the job ids, which is decreasing order of the profit
         for (int j = arr[i].dead; j > 0; j--) { //for any jobid start late as possible arr[i].dead
            if (slot[j] == -1) //which ever day is empty
            {
               slot[j] = i;//which ever job is empty perform job on that day
               countJobs++; //count no. of jobs
               jobProfit += arr[i].profit; // add the profit to total profit
               break; //only perform a job on a given day
            }
         }
      }

      return make_pair(countJobs, jobProfit);
   }
};
int main() {
   int n = 4;
   Job arr[n] = {{1,4,20},{2,1,10},{3,2,40},{4,2,30}};

   Solution ob;
   //function call
   pair < int, int > ans = ob.JobScheduling(arr, n);
   cout << ans.first << " " << ans.second << endl;

   return 0;
} 
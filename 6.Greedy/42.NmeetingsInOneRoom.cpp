/*
time= O(N) for traversing start,end,pos & puting it into ds 
+ O(nlogn) sort ds according to finishing 
+ O(N) to traverse all dinishing time  to find maxim no. of meeting
nearly time = O(NlogN)
space = O(N) to store all sarting and finishing time
*/
#include <bits/stdc++.h>
using namespace std;

struct meeting {
   int start;
   int end;
   int pos;
};

class Solution {
   public:
      bool static comparator(struct meeting m1, meeting m2) {
         if (m1.end < m2.end) return true; //finishing time is lesser return true
         else if (m1.end > m2.end) return false;//finishing time is greater ,pair has to be swapped,return false
         //above two condition not true means finishing time is equal,sort according to position
         else if (m1.pos < m2.pos) return true;
         return false;
      }
      //put start,end and position in data structure
      void maxMeetings(int s[], int e[], int n) {
      struct meeting meet[n]; //our data structure
      for (int i = 0; i < n; i++) {
         meet[i].start = s[i], meet[i].end = e[i], meet[i].pos = i + 1;
      }

      sort(meet, meet + n, comparator); //sort that data structure,shorter finishing time appear first and if there are 
      //equal finishing time,then the guy with lesser index appear first->comparator will do this

      vector < int > answer; //store the meeting order our answer

      int limit = meet[0].end; //first meeting no gonna perform,if performing the meeting ,the ending time will
      //be the limit, for the next metting we know the ending time
      answer.push_back(meet[0].pos); //take meeting no. add to answer,

      for (int i = 1; i < n; i++) { //start checking from the first index
         if (meet[i].start > limit) { //starting time of the new meeting is greater than the finishing time of the previous
         //metting that i performed in that room, in that cases this meeting can be performed
            limit = meet[i].end; //update limit ending time of meeting that we are performing in the room
            answer.push_back(meet[i].pos);//this meeting can be performed ,add the metting no. to answer
         }
      }//performed all the metting ,our answer will be in answer vector 
      cout<<"The order in which the meetings will be performed is "<<endl;
      for (int i = 0; i < answer.size(); i++) { //print answer vector
         cout << answer[i] << " ";
      }

   }

};
int main() {
   Solution obj;
   int n = 6;
   int start[] = {1,3,0,5,8,5};
   int end[] = {2,4,5,7,9,9};
   obj.maxMeetings(start, end, n);
   return 0;
}
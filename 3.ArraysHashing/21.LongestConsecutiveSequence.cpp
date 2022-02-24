//TIME = O(N)+O(N)+O(N)
//space= O(1) set in genral
//time = O(N)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> hashSet; //put all elements in set
        for(int num:nums){
            hashSet.insert(num);
        }
        
        int longestStreak=0; //store max of all  consecutice seq
          for(int num:nums){ //linearly iterate in array
              if(!hashSet.count(num-1)){ //1st step is checking is no. less than,does exist in hashset  or not ,if it doesnt  then only we execute  next loop,iteration
                  int currentNum=num;
                  int currentStreak= 1; //length of no. iteration
                  
                  while(hashSet.count(currentNum+1)){ // if next no. exist or not lets say 100
                      //if exist make it 101
                      currentNum +=1;
                      currentStreak +=1;   //increase the counter 
                  }
                  longestStreak = max(longestStreak,currentStreak);
              }
          }
        return longestStreak;
    }
    
};
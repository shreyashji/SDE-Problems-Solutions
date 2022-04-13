//try all possible ways 
/*
1d dp problems 
count the total no. of ways
min,max o/p

whenever concept of try all possible ways comes in ->count ,figure out best way
tend to apply recursion -> all posiible ways,count all ways,best way
try to find out if this is a recursive problem 

shortcut for all dp problems (can write recurrence relation )
1. try to represent problems in terms of index always
2. do all possible  stuff on that index according to problem stmt
3. if count all ways -> sum up all stuf
4. find min-> min of all stuffs 
   find max -> max of all stuff
*/
/*
You have been given a number of stairs. Initially, you are at the 0th stair, and you need to reach the Nth stair.
 Each time you can either climb one step or two steps. You are supposed to return the number of distinct ways 
 in which you can climb from the 0th step to Nth step.

f(n)-> no. of ways
f(index){
    if(index==0) return 1; //0th stair only 1 way
    if(index==1) return 1; // at 1 at f(1) index-2=-1 problems only 1 ways
    left = f(index-1);   //jump 1 index for leftrecursion
    right = f(index-2);  //jump 2 index  fro right recursion
    return left+right;
    //looks like fibonacci no.
}





*/
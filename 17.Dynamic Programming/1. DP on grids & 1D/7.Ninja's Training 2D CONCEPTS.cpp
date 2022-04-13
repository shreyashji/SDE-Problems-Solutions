//
//recursion ,recurrence relation
int f(int day,int last, vector<vector<int>> &points){
    if(day==0){
        int maxi=0;
        for(int task = 0; task<3 ; task++){
            if(task != last){ //if task not done on last day
                maxi = max(maxi,points[0][task]);//on day 0 whatever task you are doing take it off
            }
        }
        return maxi;
    }
    int maxi = 0;
    for(int task = 0; task<3 ; task++){
    	if(task != last){ //if task not done on last day
            int point = points[day][task] + f(day-1,task,points) ;
            maxi = max(maxi,point);
        }
    }
    return maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    return f(n-1,3,points);
    // Write your code here.
}


//memoization 
//time = O(n*4)*3 = day n & last 4[0,1,2,3] worst case,running a for loop of size 3
//space = recursion stack space O(N)  + O(n*4) 
int f(int day,int last, vector<vector<int>> &points,vector<vector<int>> &dp){
    if(day==0){
        int maxi=0;
        for(int task = 0; task<3 ; task++){
            if(task != last){ //if task not done on last day
                maxi = max(maxi,points[0][task]);//on day 0 whatever task you are doing take it off
            }
        }
        return maxi;
    }
    if(dp[day][last] !=-1) return dp[day][last]; //for memoization
    int maxi = 0;
    for(int task = 0; task<3 ; task++){
    	if(task != last){ //if task not done on last day
            int point = points[day][task] + f(day-1,task,points,dp);
            maxi = max(maxi,point);
        }
    }
    return dp[day][last]=maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n,vector<int>(4,-1)); //for memoization
    return f(n-1,3,points,dp);
    // Write your code here.
}

//tabulation to reduce stack space
//time = O(n*4)*3 = day n & last 4[0,1,2,3] worst case,running a for loop of size 3
//space =  O(n*4) 
int f(int day,int last, vector<vector<int>> &points,vector<vector<int>> &dp){
    if(day==0){
        int maxi=0;
        for(int task = 0; task<3 ; task++){
            if(task != last){ //if task not done on last day
                maxi = max(maxi,points[0][task]);//on day 0 whatever task you are doing take it off
            }
        }
        return maxi;
    }
    if(dp[day][last] !=-1) return dp[day][last]; //for memoization
    int maxi = 0;
    for(int task = 0; task<3 ; task++){
    	if(task != last){ //if task not done on last day
            int point = points[day][task] + f(day-1,task,points,dp);
            maxi = max(maxi,point);
        }
    }
    return dp[day][last]=maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n,vector<int>(4,0)); //for memoization
    
    dp[0][0] = max(points[0][1], points[0][2]);
  	dp[0][1] = max(points[0][0], points[0][2]);
  	dp[0][2] = max(points[0][0], points[0][1]);
  	dp[0][3] = max(points[0][0], max(points[0][1], points[0][2])); //for all the task
    	for (int day = 1; day < n; day++) {
    		for (int last = 0; last < 4; last++) {
      			dp[day][last] = 0;
                
      			for (int task = 0; task <= 2; task++) {
        		if (task != last) {
                    int point = points[day][task] + dp[day-1][task];
                    dp[day][last] = max(dp[day][last],point);
                }
              }
            }
         }
  		return dp[n-1][3];
}

//space optimization
//time = O(n*4)*3 = day n & last 4[0,1,2,3] worst case,running a for loop of size 3
//space =  O(4) constant
int f(int day,int last, vector<vector<int>> &points,vector<vector<int>> &dp){
    if(day==0){
        int maxi=0;
        for(int task = 0; task<3 ; task++){
            if(task != last){ //if task not done on last day
                maxi = max(maxi,points[0][task]);//on day 0 whatever task you are doing take it off
            }
        }
        return maxi;
    }
    if(dp[day][last] !=-1) return dp[day][last]; //for memoization
    int maxi = 0;
    for(int task = 0; task<3 ; task++){
    	if(task != last){ //if task not done on last day
            int point = points[day][task] + f(day-1,task,points,dp);
            maxi = max(maxi,point);
        }
    }
    return dp[day][last]=maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<int> prev(4,0); //for memoization
    
    prev[0] = max(points[0][1], points[0][2]);
  	prev[1] = max(points[0][0], points[0][2]);
  	prev[2] = max(points[0][0], points[0][1]);
  	prev[3] = max(points[0][0], max(points[0][1], points[0][2])); //for all the task
    	for (int day = 1; day < n; day++) {
            vector<int> temp(4,0);
    		for (int last = 0; last < 4; last++) {
      			temp[last] = 0;
                
      			for (int task = 0; task <= 2; task++) {
        		if (task != last) {
                    temp[last] = max(temp[last],points[day][task] + prev[task]);
                }
              }
            }
            prev=temp;
         }
  		return prev[3];
}
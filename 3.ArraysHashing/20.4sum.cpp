//time = O(N^3)
//space = O(1)

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector< vector<int> > res;
        if(nums.empty())
            return res;
        int n= nums.size();
        sort(nums.begin(),nums.end()); //sort array
            
            for(int i=0; i<n; i++){
                 int target_3 = target - nums[i];
                for(int j=i+1; j<n; j++){
                    int target_2 = target_3 - nums[j]; //remaining elemt we are looking for
                    
                    int front =j+1; //left pointer,immediately after j
                    int back = n-1; //right pointer at last
                    
                    while(front<back){ //loop til they do ot crossover
                        
                        int two_sum= nums[front] + nums[back];// will give two sum
                        
                        if(two_sum < target_2 ) front++; //move left ptrs
                        
                        else if(two_sum >target_2) back--; //decrease right
                //if above two condition does not satisfied, means our two_sum equals to target_2
                        else{
                            //all those we are adding up storing it
                            vector<int> quadruplet(4,0);
                            quadruplet[0]= nums[i];
                            quadruplet[1]= nums[j];
                            quadruplet[2]= nums[front];
                            quadruplet[3]= nums[back];
                            res.push_back(quadruplet);
                            
                            //processing duplicates of no.3
                            while(front<back && nums[front]== quadruplet[2]) ++front; //moveleft
                            //processing duplicates of no.4
                            while(front<back && nums[back]== quadruplet[3]) --back;//move right
                            
                        }
                    }
                    //when front crosses back here after
                    //processing duplicates of no.2
                    //for loop also moves j
                    // ....2 2 2 3 3 
                    //     j  
                    //         j  move j to here and for loop automaticly move it to 3
                    //that is why we are doing j+1
                    while(j+1 < n && nums[j+1] == nums[j]) ++j;
                }
                  //processing duplicates of no.1
                 while(i+1 < n && nums[i+1] == nums[i]) ++i;
        }
        return res;
    }
};
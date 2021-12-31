//tinme =o(N)
//space =O(1)

class Solution {
public:
    int trap(vector<int>& height) {     
        int n = height.size(); 
        int left=0; int right=n-1; 
        int res=0;   //total water
        int maxleft=0, maxright=0;
        
        while(left<=right){ //right move till it doesnt crosses left
            //hht of left is lesser than or equal ot right,we do operation on left pointer
            if(height[left]<=height[right]){
                //curnt hght greater than leftmax
                if(height[left]>=maxleft) maxleft=height[left];
                //if not,it is lesser than it, can store water
                else res+=maxleft-height[left];
                
                left++;
            }
            else{

                if(height[right]>=maxright) maxright= height[right];
                //if not greater than right max,can store water
                else res+=maxright-height[right];
                
                right--;
            }
        }
        //complt two pointer approach
        return res;
    }
};
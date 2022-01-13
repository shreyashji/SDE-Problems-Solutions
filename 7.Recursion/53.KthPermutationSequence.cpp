// TIME=  o(N) to genrate every no * O(N) to remove ,erase  = O(N^2) 
//space = O(N)
class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1; 
        vector<int> numbers; 
        for(int i = 1;i<n;i++) {
            fact = fact * i; 
            numbers.push_back(i); 
        }  //compute factorial
        numbers.push_back(n); 
        string ans = ""; //initializing string with empty
        k = k - 1; //for 0 based indexing
        while(true) { //till list becomes empty
            ans = ans + to_string(numbers[k / fact]); 
            numbers.erase(numbers.begin() + k / fact); 
            if(numbers.size() == 0) {
                break; 
            }
            
            k = k % fact; 
            fact = fact / numbers.size();
        }
        return ans; 
    }
};
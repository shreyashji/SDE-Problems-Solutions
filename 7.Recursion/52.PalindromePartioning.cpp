class Solution {
//time =O(2^N) genrating substring * K(for inserting  palindomes in another ds) * O(n/2) to check string is palindrome or not
//space=O(K*X) k is average length of string,, x lsit of palindrome 
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string> > res;//OUR AnsWER VECTOR
        vector<string> path;//storing individual list of substring storing in recr
        func(0, s, path, res);
        return res;
    }
    
    void func(int index, string s, vector<string> &path, vector<vector<string> > &res) {
        if(index == s.size()) { //base case when we have done the last partition
            res.push_back(path);
            return;
        }
        for(int i = index; i < s.size(); ++i) {
            if(isPalindrome(s, index, i)) {
                path.push_back(s.substr(index, i - index + 1));
                func(i+1, s, path, res);
                path.pop_back();//path is refrence variable so popback,while we come back
            }
        }
    }
    
    bool isPalindrome(string s, int start, int end) {
        while(start <= end) {
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }
};
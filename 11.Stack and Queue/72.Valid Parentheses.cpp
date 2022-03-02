class Solution {
public:
    //time=O(N)
    //space= O(N) usning stack ds
bool isValid(string s) {
        stack<char>st; 
        for(auto it: s) { //move till strng size
            if(it=='(' || it=='{' || it == '[') 
                st.push(it);  //simply push if opening
            else {
                if(st.size() == 0) //stack empty for closing didnt have opening bracket 
                    return false; //it doesnt have opening one
                char ch = st.top(); 
                st.pop();  //matching opposite bracket by poping top
                if((it == ')' and ch == '(') or  (it == ']' and ch == '[') or (it == '}' and ch == '{')) continue;
                else return false;
            }
        }
        return st.empty(); 
    }
};
/*
Intuition: Notice, that we are using a stack in order to perform our task. Can we somehow not use it and reverse the words as we move through the string? Could we store a word in reverse order when we are adding it to our answer variable?

Approach:
We start traversing the string from the end until we hit a space. It indicates that we have gone past a word and now we need to store it.
We check if our answer variable is empty or not
If it’s empty, it indicates that this is the last word we need to print, and hence, there shouldn’t be any space after this word.
If it’s empty we add it to our result with a space after it. Here’s a quick demonstration of the same
*/

#include<bits/stdc++.h>
using namespace std;
string result(string s)
{
//Time Complexity: O(N), N~length of string
//Space Complexity: O(1), Constant Space
    int left = 0;
    int right = s.length()-1;
    
    string temp="";
    string ans="";
    
    //Iterate the string and keep on adding to form a word
    //If empty space is encountered then add the current word to the result
    while (left <= right) {
        char ch= s[left];
        if (ch != ' ') {
            temp += ch;
        } else if (ch == ' ') {
            if (ans!="") ans = temp + " " + ans;
            else ans = temp;
            temp = "";
        }
        left++;
    }
    
    //If not empty string then add to the result(Last word is added)
    if (temp!="") {
        if (ans!="") ans = temp + " " + ans;
        else ans = temp;
    }
    
    return ans;    
}
int main()
{
    string st="TUF is great for interview preparation";
    cout<<"Before reversing words: "<<endl;
    cout<<st<<endl;
    cout<<"After reversing words: "<<endl;
    cout<<result(st);
    return 0;
}
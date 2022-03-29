/*
1. first count the  char in string
2. create a map (key value pair in sorted pair key ke according)
3. start traversing the order string
if prsnt in map print it according to count value ,then delete it,
whatever left print it lexicographically ,now traverse the map and print the char line by line,they are sorted coz we use map
*/
class Solution {
public:
    string customSortString(string order, string str){
        
        map<char, int>mp; //store cout in int
        string ans = "";
        
        for(auto x: str)  //for every char in str it will put in x,str ke har char ko x me
            mp[x]++; 
        for(auto x: order){//now we will take every char of order & check if it is present,
        //if prsnt find location to find its count & store in ans
            if(mp.find(x)!=mp.end()){
                auto temp = mp.find(x);
                int count = temp->second;
                // c-> 5  || in ans= ccccc
                /*
                for (int i=0; i<count; i++){ //to get rid of this loop we used,string s(count, x);
                    ans+=s;
                }
                */
                string s(count, x); //x is character
                ans+=s; //add it in answer
                mp.erase(x); //erase from map
            }
        }
        
        for(auto x: mp){ //whatever left in map 
            string s(x.second, x.first);//(count, ) dot becoz we are using shorthand auto
            ans+=s; 
        }
        return ans;
    }
};
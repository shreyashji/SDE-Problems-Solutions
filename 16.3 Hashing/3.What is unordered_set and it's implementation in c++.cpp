/*
--an unordered_set is implemented using a hash table
where keys are hashed into indices of a hash table so that insertion is always randomised
-all toperation on unorderedset takes O(1) time on an average
which can go upto O(n) in linear in worst case
whcih depends on internally used hashed function,but practically they perform very well  and genrally provide constant time
time lookup operation

set vs unordered_set
set -> keys are stored in ordered fashion,internally implemented as red black trees,O(log n)

unordered_set ->  keys are stored in unordered fashion,internally implemented hashing , O(1)
insert(),size,clear,begin,end,find,erase ,count

unordered_set does not have duplicate keys

*/
#include<bits/stdc++.h>
#include<unordered_set>

using namespace std;
int main(){

    unordered_set<int> s;
    s.insert(10);
    s.insert(5);
    s.insert(15);
    s.insert(20);
    
    for(auto it = s.begin() ; it!=s.end() ;it++)
        cout<<(*it)<<endl;
    
    cout<<"number of element : "<<s.size()<<endl;

    s.clear();
    cout<<"number of element : "<<s.size()<<endl;

    int key = 20;

    if(s.find(key) == s.end()){
        cout<<"key not found"<<endl;
    }
    else{
        auto temp = s.find(key);
        s.erase(temp);
    }

    int deleted_key = 25;
    s.erase(deleted_key);

    for(auto it = s.begin() ; it!=s.end() ;it++)
        cout<<(*it)<<endl;

    cout<<"number of element : "<<s.size()<<endl;

    if(s.find(key)!=s.end())
        cout<<"key found"<<endl;

    if(s.count(5))
        cout<<"key found"<<endl;
    else
        cout<<"not found"<<endl;
}
/*
for (auto it = S.begin(); it != S.end(); it++)
    {
        cout << (*it) << endl;
    }
*/
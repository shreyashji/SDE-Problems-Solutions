#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct Node {
    Node *links[2]; 
 
    bool containsKey(int ind) {
        return (links[ind] != NULL); 
    }
    Node* get(int ind) {
        return links[ind]; 
    }
    void put(int ind, Node* node) {
        links[ind] = node; 
    }
}; 
class Trie {
    private: Node* root; 
public:
    Trie() {
        root = new Node(); 
    }

public: 
    void insert(int num) {
        Node* node = root;
        // cout << num << endl; 
        for(int i = 31;i>=0;i--) {
            int bit = (num >> i) & 1; 
            if(!node->containsKey(bit)) {
                node->put(bit, new Node()); 
            }
            node = node->get(bit); 
        }
    }
public:
    int findMax(int num) {
        Node* node = root; 
        int maxNum = 0; 
        for(int i = 31;i>=0;i--) {
            int bit = (num >> i) & 1; 
            if(node->containsKey(!bit)) {
                maxNum = maxNum | (1<<i); 
                node = node->get(!bit); 
            }
            else {
                node = node->get(bit); 
            }
        }
        return maxNum; 
    }
};
vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
	vector<int> ans(queries.size(), 0); ///store all the ans
    vector<pair<int, pair<int,int>>> offlineQueries; //queries has to be stored,make it offline,need to store indexes
    sort(arr.begin(), arr.end()); //sort the array ///O(q log q)
    int index = 0;
    for(auto &it: queries) { //O(q)
        offlineQueries.push_back({it[1],{it[0], index++}}); 
    }
    sort(offlineQueries.begin(), offlineQueries.end()); //sort in terms of ai
    int i = 0; 
    int n = arr.size(); 
    Trie trie; 
    //O(q * 32(findmax take 32 times) + n * 32(insert)) throughout its n elements its get
    for(auto &it : offlineQueries) {//traverse all the querries again, in offline querries
        while(i < n && arr[i] <= it.first) {//only move the pointer if arr of index is lesser than equal to a[i]
            trie.insert(arr[i]); //will create trie,insert arr of index
            i++; 
        }
        if(i!=0) ans[it.second.second] = trie.findMax(it.second.first); 
        else ans[it.second.second] = -1; 
    }
    return ans; 
}    
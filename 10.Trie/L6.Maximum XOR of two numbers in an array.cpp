#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
struct Node { //trie node
  Node * links[2];//size 2 0&1
 
  bool containsKey(int ind) { //index is set or not
    return (links[ind] != NULL);
  }
  Node * get(int ind) {
    return links[ind];
  }
  void put(int ind, Node * node) { //if bit or indx does not exist,put
    links[ind] = node; //put new node for particular links
  }
};

class Trie { //with respect to node we need trie
private: Node * root;
public:
    Trie() { //constructor
      root = new Node();//always initialized with new node
    }
public:
    void insert(int num) {
      Node * node = root;
      // cout << num << endl; 
      for (int i = 31; i >= 0; i--) { //started to insert from extreme left 31st bit
        int bit = (num >> i) & 1; //ith index is set or not
        if (!node -> containsKey(bit)) { //do you contain this bit
          node -> put(bit, new Node()); //if doesnt contains,for this bit put a new node
        }
        node = node -> get(bit);//once put go to that node 
      }
    }
public:
    int findMax(int num) {
      Node * node = root;//always start with root
      int maxNum = 0;
      for (int i = 31; i >= 0; i--) {//start from the back
        int bit = (num >> i) & 1; //once get the bit 
        if (node -> containsKey(!bit)) { //if node contains opposite of it
          maxNum = maxNum | (1 << i); //if contains make this bit as 1
          node = node -> get(!bit);//go to that guy we make
        } else {//if does not contain,go to the next guy ,which i the bit itself similar one
          node = node -> get(bit);
        }
      }
      return maxNum;
    }
};
int maxXOR(int n, int m, vector < int > & arr1, vector < int > & arr2) {
  Trie trie;//create trrie object of class trie
  for (int i = 0; i < n; i++) {//iterate across arr1
    trie.insert(arr1[i]);//insert this no.
  }
  //entire trie ready 
  int maxi = 0;
  for (int i = 0; i < m; i++) { //iterate on arr2
    maxi = max(maxi, trie.findMax(arr2[i]));//try all the no. from arr2,someone will give maxi,store the maxi
  }
  return maxi;
}
int main() {
  vector < int > arr1 = {6, 8};
  vector < int > arr2 = {7, 8, 2};
  int n = 2, m = 3;
  cout << maxXOR(n, m, arr1, arr2) << endl;
  return 0;
}
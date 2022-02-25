#include<iostream>
using namespace std;
//time  =  O(n^2)
//space : cantmeasure it in trie,it depends on input (hypothetical in nature)
struct Node {
  Node * links[26];

  bool containsKey(char ch) { //does it contains
    return (links[ch - 'a'] != NULL);
  }

  Node * get(char ch) {
    return links[ch - 'a'];
  }

  void put(char ch, Node * node) { //insert new guy 
    links[ch - 'a'] = node;
  }
};
//dont require trie class
int countDistinctSubstrings(string & s) {
  Node * root = new Node();
  int count = 0;
  int n = s.size();
  for (int i = 0; i < n; i++) {
    Node * node = root;

    for (int j = i; j < n; j++) {
      if (!node -> containsKey(s[j])) { //if node does not contains this particular word
        node -> put(s[j], new Node()); //can you put ,it does not contain with new node
        count++; 
      }
      node = node -> get(s[j]); //if exist next one
    }

  }
  return count + 1; //for the empty one count
}

int main() {
  string s1 = "ababa";
  cout << "Total number of distinct substrings : " << countDistinctSubstrings(s1);
  cout << "\n";

  string s2 = "ccfdf";
  cout << "Total number of distinct substrings : " << countDistinctSubstrings(s2);

  return 0;
}
/*
Implement Trie Data Structure to support these operations:

STORE THIS PARTICULAR WORD = insert(word) - To insert a string "word" in Trie
DOES THIS WORD EXIST OR NOT = search(word) - To check if string "word" is present in Trie or not.
IS THERE ANY WORD WHOSE PREFIX IS THIS PARTICULAR WORD = startsWith(word) - To check if there is any string in the Trie that starts with the given prefix string "word".
*/
/*
trie{
    int a[26];s
    bool flag;
}
*/


#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MAXN 100001
#define INF 1e18+1
struct Node {
	Node *links[26];
	bool flag = false;
	//checks if the reference trie is present or not
	bool containKey(char ch) {
		return (links[ch - 'a'] != NULL);
	}
	//creating reference trie
	void put(char ch, Node *node) {
		links[ch - 'a'] = node; //apple a pointing to new trie
	} 
	//to get the next node for traversal
	Node *get(char ch) {
		return links[ch - 'a'];
	}
	//setting flag to true at the end of the word
	void setEnd() {
		flag = true;
	}
	//checking if the word is completed or not
	bool isEnd() {
		return flag; //last flag has to be true
	}
};
class Trie {
private:
	Node* root;
public:
	Trie() {
		//creating new obejct
		root = new Node();
	}
	
     /** Inserts a word into the trie. */
	void insert(string word) {
		//initializing dummy node pointing to root initially
		//tc= O(lenth)
		Node *node = root;//dummy variable node,initialy pointing to root
		for (int i = 0; i < word.size(); i++) { //insert every character
			if (!node->containKey(word[i])) {
				node->put(word[i], new Node());
			}
			//moves to reference trie
			node = node->get(word[i]);
		}
		node->setEnd();//set last reffrence node to true
	}
    /** Returns if the word is in the trie. */
    //tc= O(lenth)
	bool search(string word) {
		Node *node = root;
		for (int i = 0; i < word.size(); i++) {
			if (!node->containKey(word[i])) {
				return false;
			}
			node = node->get(word[i]);
		}
		return node->isEnd(); //last flag has to be true
	}
    /** Returns if there is any word in the trie that starts with the given prefix. */
    //tc= O(lenth)
	bool startsWith(string prefix) {
		Node* node = root;
		for (int i = 0; i < prefix.size(); i++) {
			if (!node->containKey(prefix[i])) {
				return false;
			}
			node = node->get(prefix[i]); //exist move to the next
		}
		return true; //reach reach reach,can be prefix
	}
};

int main()
{
	int n = 5;
	vector<int>type = {1, 1, 2, 3, 2};
	vector<string>value = {"hello", "help", "help", "hel", "hel"};
	Trie trie;
	for (int i = 0; i < n; i++) {
		if (type[i] == 1) {
			trie.insert(value[i]);
		}
		else if (type[i] == 2) {
			if (trie.search(value[i])) {
				cout << "true" << "\n";
			}
			else {
				cout << "false" << "\n";
			}
		}
		else {
			if (trie.startsWith(value[i])) {
				cout << "true" << "\n";
			}
			else {
				cout << "false" << "\n";
			}
		}
	}
}
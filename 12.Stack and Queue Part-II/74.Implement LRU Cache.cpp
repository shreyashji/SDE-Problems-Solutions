class LRUCache {
  public:
    class node {
      public:
        int key;
      int val;
      node * next;
      node * prev;
      node(int _key, int _val) {
        key = _key;
        val = _val;
      }
    };

  node * head = new node(-1, -1);
  node * tail = new node(-1, -1);
//time = O(N)
//Space = O(1)

  int cap;
  unordered_map < int, node * > m;

  LRUCache(int capacity) {//initial configuration
    cap = capacity;
    head -> next = tail;
    tail -> prev = head;
  }

  void addnode(node * newnode) {
    node * temp = head -> next;
    newnode -> next = temp;
    newnode -> prev = head;
    head -> next = newnode;
    temp -> prev = newnode;
  }

  void deletenode(node * delnode) {
    node * delprev = delnode -> prev;
    node * delnext = delnode -> next;
    delprev -> next = delnext;
    delnext -> prev = delprev;
  }

  int get(int key_) {
    if (m.find(key_) != m.end()) {
      node * resnode = m[key_];//get the  address
      int res = resnode -> val;//value stored in that node
      m.erase(key_);//erase old address
      deletenode(resnode);//delt node
      addnode(resnode);//add the node
      m[key_] = head -> next;
      return res;
    }

    return -1;//if didnt find
  }

  void put(int key_, int value) {
    if (m.find(key_) != m.end()) {//does it exist in our map
      node * existingnode = m[key_];//get node address
      m.erase(key_); //erase from map
      deletenode(existingnode);//delt if previously existed
    }
    if (m.size() == cap) { //if size full delt least recently used
      m.erase(tail -> prev -> key); //delt tail previous last guy
      deletenode(tail -> prev);//delt the node
    }

    addnode(new node(key_, value)); //add the node
    m[key_] = head -> next;//head->next add of that nodes
  }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
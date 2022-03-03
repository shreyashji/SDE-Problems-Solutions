struct Node {
    int key, value, cnt;
    Node *next; 
    Node *prev;
    Node(int _key, int _value) {
        key = _key;
        value = _value; 
        cnt = 1; 
    }
    //make sure frequency is 1
}; 
//implementation of list
struct List {
    int size; //what is the size of list at every moment
    Node *head; 
    Node *tail; 
    List() {
        //initial pointings
        head = new Node(0, 0); 
        tail = new Node(0,0); 
        head->next = tail;
        tail->prev = head; 
        size = 0;
    }
    
    void addFront(Node *node) { //right after head
        Node* temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
        size++; //when adding in front increase the size
    }
    
    void removeNode(Node* delnode) {
        Node* delprev = delnode->prev;
        Node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
        size--; //remove the node size will decrease
    }  
};//list implementation
class LFUCache {
    map<int, Node*> keyNode; 
    map<int, List*> freqListMap; 
    int maxSizeCache;
    int minFreq; 
    int curSize; //current size of cache
public:
    LFUCache(int capacity) {
        maxSizeCache = capacity; 
        minFreq = 0;
        curSize = 0; 
    }
    //frequency will not go so big ,so O(1)hashmap
    void updateFreqListMap(Node *node) {
        keyNode.erase(node->key); //take it out from our keynode map which is currently storing the node
        freqListMap[node->cnt]->removeNode(node); //wherever the node is prsnt in hashmap in the list,remove it
        if(node->cnt == minFreq && freqListMap[node->cnt]->size == 0) {//after removal
            minFreq++; 
        }
        //create a next higher frequency list
        List* nextHigherFreqList = new List();
        if(freqListMap.find(node->cnt + 1) != freqListMap.end()) {//if there exist next freq
            nextHigherFreqList = freqListMap[node->cnt + 1];//simply initialize to this guy
        } //list is ready for the next frequency
        node->cnt += 1; //increase the node count
        nextHigherFreqList->addFront(node); //inserted in list starting
        freqListMap[node->cnt] = nextHigherFreqList; //list has been modified store it in freq
        keyNode[node->key] = node;///assign it to keynode back again
    }
    
    int get(int key) { //
        if(keyNode.find(key) != keyNode.end()) {//if present ,we will get the node
            Node* node = keyNode[key]; 
            int val = node->value; 
            updateFreqListMap(node); //made sure that node updated in our hashmap freqlist,bcoz it has been accessed
            return val; 
        }
        return -1; //if key is not present
    }
    //O(1)
    void put(int key, int value) {
        if (maxSizeCache == 0) {
            return;
        }
        if(keyNode.find(key) != keyNode.end()) {//if it sis already present
            Node* node = keyNode[key]; //take occurence of that ffrom keynode map
            node->value = value; //update the value
            updateFreqListMap(node); //since we are accesing node,frequency will increase,will got the the next freq list
        }
        else {//if doesnt exist
            if(curSize == maxSizeCache) {
                List* list = freqListMap[minFreq]; //get minimal frq list
                keyNode.erase(list->tail->prev->key); //erase tail,we have to delt LRU(least tail ka previous)
                freqListMap[minFreq]->removeNode(list->tail->prev);//remove that node
                curSize--; //decrease the size
            }
            curSize++; //inserting a new element
            // new value has to be added who is not there previously 
            //every time a new element come minFreq become 1
            minFreq = 1; 
            List* listFreq = new List(); //create a list ,insert new element
            if(freqListMap.find(minFreq) != freqListMap.end()) {//if the minfreq 1 is not there
                listFreq = freqListMap[minFreq]; //if it is there ,take that list
            }
            //not there create a new list
            Node* node = new Node(key, value); 
            listFreq->addFront(node);//insert into the front
            keyNode[key] = node; //store the address at key node
            freqListMap[minFreq] = listFreq; //initilaize that list,to the corresponding frequency
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
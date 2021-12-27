/* Node structure  used in the program
struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/
/*  Function which returns the  root of 
    the flattened linked list. */
//time= O(N) summation of total no. of nodes
//space= O(1) same pntrs in same node
Node* mergeTwoLists(Node* a, Node* b) {
    
    Node *temp = new Node(0); //two varibales tem and res,pointed to dummy node which assigned value to 0
    Node *res = temp; 
    //a & b pointer initialy pointing to head of both ll
    while(a != NULL && b != NULL) { //comparing a data and b data
        if(a->data < b->data) {
            temp->bottom = a; //pointing bottom pntr of temp node to a
            temp = temp->bottom; //move temp to temp of bottom
            a = a->bottom; //move a pointer
        }
        else { //if b is smaller
            temp->bottom = b; //botom pntr of temp willl be pointing to b
            temp = temp->bottom; //move temprory pntr to temp bottom
            b = b->bottom;  //b has taken so move to next pointer
        }
    }
    //either of one of ll is completely taken
    if(a) temp->bottom = a; //some elemnts of the 1st ll are still to be taken,so take all the elements of ll
    else temp->bottom = b; //ifb b is not null,take all the lemntsof b lft
    //when we declare anode we are alwys pointing to null
    return res -> bottom; //it is head
}

Node *flatten(Node *root)
{
   if (root == NULL || root->next == NULL) 
            return root; 
        // recur for list on right 
        root->next = flatten(root->next);  //always move next l1,l2,l3,l4
        // now merge 
        root = mergeTwoLists(root, root->next); 
        // return the root 
        // it will be in turn merged with its left 
        return root;
}


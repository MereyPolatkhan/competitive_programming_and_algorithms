#include <iostream> 
#include <cassert> 

using namespace std;

struct node{
    int data;
    node *nxt = 0;

    node(){
        data = 0;
    }

    node(int _data){
        data = _data;
    }

    node(int _data, node *_nxt){
        data = _data;
        nxt = _nxt;
    }
};

struct linked_list{
    node* head = 0;

    node* get_tail(){
        if (head == 0){
            return 0;
        }

        node* cur = head;
        while(cur->nxt != 0){
            cur = cur->nxt;
        }
        return cur;
    }

    node* get(int i){
        // return node at position i or return NULL
        node* cur = head;
        for (int j = 0; j < i; j++){
            if (cur == 0){
                return 0;
            }
            cur = cur->nxt;
        }
        return cur;
    }

    void insert_begin(int data){
        node* new_node = new node(data, head);
        head = new_node;
    }

    void insert_tail(int data){
        node *tail = get_tail();
        node *new_node = new node(data);
        tail->nxt = new_node;
    }

    void insert(int i, int data){
		// insert at position i means
		// put element with data at position i
		// moving everything to right

        if (i == 0){
            insert_begin(data);
            return;
        }

        node* A = get(i - 1);
        // LL: 524 212 234 440 
        //  i: 0   1   2   3
        
        //  i = 2, data = 14234 ==> A = LL[1]

        if (A == 0){
            insert_tail(data);
            return;
        } 

        node* B = A->nxt;
        node* new_node = new node(data, B); // new -> B
        A->nxt = new_node;  // A - > new
    }

    void output() {
        cout << "[";
        node *cur = head;
        while(cur != 0){
            cout << cur->data;
            cur = cur->nxt;
            if (cur == 0){
                cout << "]";
            }
            else {
                cout << ", ";
            }
        }
        cout << "\n";
    }

    void del_begin(){ // old_head --> new_head --> 
        if(head == 0){
            return;
        }

        node* old_head = head;
        head = head->nxt;
        delete old_head;
    }

    void del_end(){
        if (head == 0){ // empty list
            return;
        }
        if (head->nxt == 0){ // head is a tail
            delete head;
            head = 0;
            return;
        }

        node* cur = head;
        while(cur->nxt->nxt != 0){ // search element before the tail
            cur = cur->nxt;
        }
        delete cur->nxt;
        cur->nxt = 0;
    }

    void del(int i){
        // implement ___
    }

};

int main() {

	linked_list L;
	L.insert(0, 10); // [10]
	L.insert(1, 20); // [10, 20]
	L.insert(2, 30); // [10, 20, 30]
	L.insert(3, 40); // [10, 20, 30, 40]

    L.insert(2, 500);
    L.output();

    L.del_begin();
	L.output();
    
    L.del_end();
	L.output();
    return 0;

}
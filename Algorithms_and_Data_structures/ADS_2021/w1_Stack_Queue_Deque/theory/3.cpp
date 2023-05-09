// Stack

#include <iostream>

using namespace std;

class Node{  
    public:
        int data;
        Node *next;

    Node(int data1){
        this->data = data1;
        this->next = NULL;
    }
};

class Stack{
    public:
        Node *top;
        int sz;

    Stack(){
        top = NULL;
        sz = 0;
    }

    void push(int data) {
        Node *node = new Node(data);
        node->next = top;
        top = node;
        sz++;
    }

    void pop() {
        if (top != NULL){
            top = top->next;
            sz--;
        }
    }

    int size() {
        return this->sz;
    }

    bool empty() {
        return (sz == 0);
    }

};


int main() {

    Stack *st = new Stack();
    st->push(10);
    st->push(20);
    st->push(30);

    cout << st->size() << endl;

    st->pop();
    st->pop();

    cout << st->size();

    return 0;
}
#include <iostream>

using namespace std;

class Node{
public:
    int data;
    int index;
    Node* next;
    Node() {
        data = 0;
        index = 0;
        next = NULL;
    }

    Node (int data, int index) {
        this->data = data;
        this->index = index;
        this->next = NULL;
    }

    Node(int data, int index, Node* next) {
        this->data = data;
        this->index = index;
        this->next = next;
    }
};

class LL {
public:
    Node *head;
    Node *tail;
    LL(){
        head = NULL;
        tail = head;
    }

    void insert(int data, int index) {
        Node *newnode = new Node(data, index);
        if (head == NULL) {
            head = newnode;
            tail = newnode;
            return;
        }

        tail->next = newnode;
        tail = tail->next;
    }

    void insertWithIndex(int val, int i) {
        Node* newnode = new Node(val, i);
        if (i == 0) {
            Node* temp = head;
            newnode->next = temp;
            head = newnode;
            return;
        }
        Node *cur = head;
        while (cur != NULL) {
            if (cur->next->index == i) {
                Node* temp = cur->next;
                cur->next = newnode;
                newnode->next = temp;
                return;
            }

            cur = cur->next;
        }
    }
    
    void print(){
        Node *cur = head;
        while (cur != NULL) {
            cout << "data: " << cur->data << "   index: " << cur->index << "\n";
            cur = cur->next;
        }
    }
};



int main() {

    int n;
    cin >> n;

    LL ll;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ll.insert(x, i);
    }

    int data, index;
    cin >> data >> index;
    ll.insertWithIndex(data, index);
    ll.print();


    return 0;
}
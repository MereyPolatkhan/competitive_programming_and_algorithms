#include <bits/stdc++.h> 

using namespace std;

struct Node { 
    int data;

    Node *next;
    
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

struct LinkedList {
    
    Node *head;
    Node *tail;
    LinkedList() {
        this->head = NULL;
        this->tail = head;
    }

    void pushBack(int data) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = tail->next;

    }


    void solve() {
        Node* cur = head;
        while (cur != NULL && cur->next != NULL) {
            cur->next = cur->next->next;
            cur = cur->next;
        }
    }

    void print(){
        Node *cur = head;
        while (cur != NULL) {
            cout << cur->data << " " ;
            cur = cur->next;
        }
    }
};


int main() {
    int n;
    cin >> n;   

    LinkedList ll;

    for (int i = 0; i < n; i++) {
        int data; cin >> data;
        ll.pushBack(data);
    }

    ll.solve();

    ll.print();
    
    return 0;
}
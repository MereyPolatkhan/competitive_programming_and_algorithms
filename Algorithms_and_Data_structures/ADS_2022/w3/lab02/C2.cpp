#include <bits/stdc++.h> 

using namespace std;

struct Node { 
    int data;
    int index;
    Node *next;

    Node(int data, int index) {
        this->data = data;
        this->index = index;
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
    void pushBack(int data, int ind) {
        Node* newNode = new Node(data, ind);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = tail->next;

    }

    
    void print(){
        Node *cur = head;
        while (cur != NULL) {
            if (cur->index % 2 == 1)
                cout << cur->data << " ";
            cur = cur->next;
        }
    }
};


int main() {
    int n;
    cin >> n;   

    LinkedList* ll = new LinkedList();

    for (int i = 1; i <= n; i++) {
        int data; cin >> data;
        ll->pushBack(data, i);
    }

    ll->print();

    return 0;
}
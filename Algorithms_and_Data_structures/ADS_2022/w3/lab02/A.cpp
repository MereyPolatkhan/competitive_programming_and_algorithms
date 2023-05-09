#include <bits/stdc++.h> 

using namespace std;

struct Node { 
    int data;
    int index;
    Node *next;

    
    Node() {
        this->data = 0;
        this->index = 0;
        this->next = NULL;
    }
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
    // pb = insert = build LL
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

    int distance(int x) {
        Node* cur = head;
        int res_index;
        int min_cur = 1000000;
        
        while (cur != NULL) {
            int dist = abs(cur->data - x);
            if (dist < min_cur) {
                min_cur = dist;
                res_index = cur->index;
            }

            cur = cur->next;
        }
        return res_index;
    }

    void print(){
        Node *cur = head;
        while (cur != NULL) {
            cout << cur->data << "  " << cur->index << endl;
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
        ll.pushBack(data, i);
    }


    int k; 
    cin >> k;
    // ll.print();

    cout << ll.distance(k);
    
    return 0;
}
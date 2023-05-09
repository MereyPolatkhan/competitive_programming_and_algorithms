#include <bits/stdc++.h>


using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int d) {
        data = d;
        next = NULL;
        prev = NULL;
    }
};

struct LL {
    Node* head = NULL;
    Node* tail = NULL;
    
    void add_back(int x) {
        Node* n = new Node(x);
        if (head == NULL) {
            head = tail = n;
        }
        else {
            tail->next = n;
            n->prev = tail;
            tail = tail->next;
        }
    }

    void add_front(int x){
        Node* n = new Node(x);
        if (head == NULL) {
            head = tail = n;
        }
        else {
            head->prev = n;
            n->next = head;
            head = head->prev;
        }
    }   

    void print_back() {
        Node* cur = head;
        while (cur != NULL) {
            cout << cur->data << " ";
            cur = cur->next;
        }
    }


    void print_front() {
        Node* cur = tail;
        while (cur != NULL) {
            cout << cur->data << " ";
            cur = cur->prev;
        }
    }
};

int main() {
    int q;
    cin >> q;
    LL l;
    int flag = 1;
    while (q--) {
        int x;
        cin >> x;
        if (x == 1) {
            int n;
            cin >> n;
            
            if (flag == 1) {
                l.add_back(n);
            }
            else {
                l.add_front(n);
            }
        }
        else {
            flag = flag * -1;
        }
    }

    if (flag == 1) {
        l.print_back();
    }
    else {
        l.print_front();
    }

    return 0;
}
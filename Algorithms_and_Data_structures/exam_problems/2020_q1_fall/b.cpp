#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

Node* head = NULL;
Node* tail = NULL;

void push_back(int data) {
    Node* newNode = new Node(data);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = tail->next;
    }
}

void reverse() {
    Node* dummy = NULL;
    Node* prev = dummy;

    Node* cur = head;

    tail = head;

    while (cur != NULL) {
        Node* next_node = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next_node;
    }

    head = prev;
}


void print(){ 
    Node* cur = head;
    while (cur != NULL) {
        cout << cur->data << " ";
        cur = cur->next;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        int com;
        cin >> com;
        if (com == 1) {
            int n;
            cin >> n;
            push_back(n);
        }
        else {
            reverse();
        }
    }

    print();

    return 0;
}
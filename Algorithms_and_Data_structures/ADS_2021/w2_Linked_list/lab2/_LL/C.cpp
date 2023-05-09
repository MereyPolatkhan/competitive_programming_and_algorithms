// time limit

#include <bits/stdc++.h> 

using namespace std;

class Node {
public: 
    int k;
    string val;
    Node* next;
    Node(string word) {
        val = word;
        k = 1;
        next = NULL;
    }
};

void push(Node*& node, string word) {
    Node* n = new Node(word);
    if (node == NULL) {
        node = n;
        return;
    }
    else {
        Node* temp = node;
        while (temp != NULL) {
            if (temp->val == word) {
                temp->k++;
                return;
            }
            else if (temp->next == NULL) {
                temp->next = n;
                return;
            }
            temp = temp->next;
        }
    }
}

void sort(Node*& node) {
    Node* cur = node;
    Node* nxt = NULL;
    while (cur->next != NULL) {
        nxt = cur->next;
        while (nxt != NULL) {
            if (cur->k < nxt->k) {
                swap(cur->val, nxt->val);
                swap(cur->k, nxt->k);
            }
            if (cur->k == nxt->k && cur->val > nxt->val) {
                swap(cur->val, nxt->val);
                swap(cur->k, nxt->k);    
            }
            nxt = nxt->next;
        }
        cur = cur->next;
    }
}


void print(Node*& node) {
    Node* temp = node;
    while (temp != NULL) {
        cout << temp->val << " " << temp->k << "\n";
        temp = temp->next;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Node* head = NULL;

    string s;
    while (cin >> s) {
        push(head, s);
    }
    
    sort(head);
    print(head);

    return 0;
}
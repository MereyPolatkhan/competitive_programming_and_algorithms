#include <bits/stdc++.h> 

using namespace std;

int r = 0, f = 0;
int a[10000];

class Node {
public: 
    int val;
    Node *next;
    Node(int word) {
        val = word;
        next = NULL;
    }
};

void push(Node*& head, int word) {
    Node* temp = head;
    Node* t = new Node(word);
    if (head == NULL) {
        head = t;
        return;
    }
    else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = t;
    }
}

void dlt(Node*& head, int word) {
    r++;
    Node* temp = head;
    Node* prev = NULL;
    if (temp != NULL && temp->val == word) {
        head = temp->next;
        delete temp;
        r--;
        return;
    }
    else if (temp != NULL) {
        while (temp->next != NULL && temp->val != word) {
            prev = temp;
            temp = temp->next;
        }
        if (temp->val == word) {
            prev->next = temp->next;
            delete temp;
            r--;
            return;
        }
    }
    else {
        r++;
    }
}

void sort(Node*& head) {
    Node* temp = head;
    Node* x = NULL;
    while (temp != NULL) {
        a[f] = temp->val;
        f++;
        temp = temp->next;
    }
}


void print(Node*& head) {
    Node* temp = head;
    if (temp == NULL) {
        cout << "EMPTY\n";
    }
    else if (r > 0) {
        cout << "ERROR\n";
    }
    else {
        sort(a, a + f);
        for (int i = 0; i < f; i++) {
            cout << a[i] << " ";
        }
    }
}

int main() {
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    Node* head = NULL;

    char c; 
    int x;

    while (cin >> c >> x) {
        if (c == '+') {
            push(head, x);
        }

        else if (c == '-') {
            dlt(head, x);
        }
    }
    sort(head);

    print(head);

    return 0;
}
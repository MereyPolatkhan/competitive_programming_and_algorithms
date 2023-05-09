#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = this->right = NULL;
    }
};

Node* root = NULL;

Node* build(Node* node, int data) {
    if (node == NULL) {
        node = new Node(data);
        return node;
    }
    else if (node->data < data) {
        node->right = build(node->right, data);
    }
    else {
        node->left = build(node->left, data);
    }
    return node;
}

int isTriangle(Node* node, int n) {
    int left_cnt = 1;
    Node* cur_left = node;
    while (cur_left->left != NULL) {
        left_cnt++;
        cur_left = cur_left->left;
    }

    int right_cnt = 1;
    Node* cur_right = node;    
    while (cur_right->right != NULL) {
        right_cnt++;
        cur_right = cur_right->right;
    }

    int k = min(left_cnt, right_cnt);
    
    return (k >= n);
}

int cnt = 0;

void counter(Node* node, int n) {
    if (node == NULL) {
        return;
    }
    
    counter(node->left, n);

    if (isTriangle(node, n)) { 
        cnt++;
    }

    counter(node->right, n);
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        root = build(root, x);
    }

    for (int i = 2; i <= n; i++) {
        counter(root, i);
        cout << cnt << " " ;
        cnt = 0;
    }
    

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

struct Node {
    Node* left;
    Node* right;
    int data;
    Node() {

    }

    Node(int data) {
        this->data = data;
        this->left = this->right = NULL;
    }
};

Node* insert(Node* node, int val) {
    if (node == NULL) {
        node = new Node(val);
        return node;
    }

    else if (val < node->data) {
        node->left = insert(node->left, val);
    }

    else if (val > node->data) {
        node->right = insert(node->right, val);
    }
    return node;
}   

int height(Node* node) {
    if (node == NULL) {
        return 0;
    }
    int l = height(node->left);
    int r = height(node->right);
    return max(l, r) + 1;
}

int res = -1;

void max_distance(Node* node) {
    if (node == NULL) {
        return;
    }

    int cur_height = height(node->left) + height(node->right) + 1;
    res = max(res, cur_height);

    max_distance(node->left);
    max_distance(node->right);
}


int main() {    
    Node* root = NULL; 

    int n;
    cin >> n;
    while (n--){
        int x;
        cin >> x;
        root = insert(root, x);
    }
    max_distance(root);
    cout << res;

    return 0;
}
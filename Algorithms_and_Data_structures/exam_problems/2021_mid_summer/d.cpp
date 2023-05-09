#include <iostream>

using namespace std;

struct Node {
    int data;
    Node * left;
    Node * right;


    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

struct BST {
    Node* root;
    BST() {
        root = NULL;
    }

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

    bool check(Node* node) {
        if (node != NULL && node->left != NULL && node->right != NULL) {
            return true;
        }
        return false;
    }

    int cnt = 0;
    void print(Node* node) {
        if (node == NULL) {
            return;
        }
        print(node->left);
        if (check(node) == true) {
            cnt++;
        }
        print(node->right);
    }
};

int main() {
    int n;
    cin >> n;

    BST b;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        b.root = b.build(b.root, x);
    }

    b.print(b.root);
    cout << b.cnt;
    return 0;
}
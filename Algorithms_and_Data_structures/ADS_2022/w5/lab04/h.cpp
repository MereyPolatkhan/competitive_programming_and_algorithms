#include <iostream>

using namespace std;

struct Node{
    Node * left;
    Node * right;
    int data;
    Node() {

    }
    Node(int data) {
        this->data = data;
        this->right = this->left = NULL;
    }
};


Node* insert(Node* node, int val) {
    if (node == NULL) {
        node = new Node(val);
    }
    else if (val < node->data) {
        node->left = insert(node->left, val);
    }
    else {
        node->right = insert(node->right, val);
    }
    return node;
}

int sum = 0;
void get_sum(Node* node) {
    if (node == NULL) {
        return;
    }
    get_sum(node->left);
    sum += node->data;
    get_sum(node->right);
}

int d = 0;
void change_bst(Node* node) {
    if (node == NULL) {
        return;
    }
    
    change_bst(node->left);

    d = node->data;
    node->data = sum;
    sum = sum - d;

    change_bst(node->right);
}   


void print_res(Node* node) {
    if (node == NULL) {
        return;
    }
    print_res(node->right);
    cout << node->data << " ";
    print_res(node->left);
}

Node* root = NULL;

int main() {

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        root = insert(root, x);
    }
    
    get_sum(root);
    change_bst(root);
    print_res(root);
    
    return 0;
}
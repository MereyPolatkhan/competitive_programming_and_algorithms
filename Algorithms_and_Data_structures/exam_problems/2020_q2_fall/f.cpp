#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

Node* func(Node* node, int a[], int l, int r) {
    if (l > r) {
        return NULL;
    }
    int mid = (l + r) / 2;
    
    node = new Node(a[mid]);

    node->left = func(node->left, a, l, mid - 1);
    node->right = func(node->right, a, mid + 1, r);

    return node;
}

void print(Node* node) {
    queue<Node* > q;
    q.push(node);
    while (q.size() > 0) {
        Node* temp = q.front();
        cout << temp->data << " ";
        q.pop();
        if (temp->left != NULL) {
            q.push(temp->left);
        }
        if (temp->right != NULL) {
            q.push(temp->right);
        }
    }
}

int main() {
    int n;
    cin >> n;
    n = pow(2, n) - 1;
    
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    Node* root;
    root = func(root, a, 0, n - 1);
    print(root);
    return 0;
}
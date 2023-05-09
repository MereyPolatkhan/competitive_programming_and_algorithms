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



void print_bfs(Node* node) {
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

Node* build(Node* node, int * a, int l, int r) {
    if (l <= r) {
        int mid = (l + r) / 2;

        Node* node = new Node(a[mid]);

        node->left = build(node->left, a, l, mid - 1);
        node->right = build(node->right, a, mid + 1, r);

        return node;
    }
    
    else if (l > r)  return NULL;
    
}



int main() {

    int n;
    cin >> n;
    n = pow(2, n) - 1;

    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    
    Node* root = NULL;
    
    root = build(root, a, 0, n - 1);

    print_bfs(root);


    return 0;
}
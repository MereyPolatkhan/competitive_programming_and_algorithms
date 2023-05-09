#include <iostream>
#include <algorithm>
#include <queue>
#include <math.h>

using namespace std;


struct Node {
    Node* left;
    Node* right;
    int data;
    Node(){

    }
    Node(int data) {
        this->data = data;
        this->right = this->left = NULL;
    }
};

Node* array_to_bst(Node* node, int * a, int l, int r) {
    if (l > r) {
        return NULL;
    }
    int mid = (l + r) / 2;
    
    int val = a[mid];
    
    node = new Node(val);
    
    node->left = array_to_bst(node->left, a, l, mid - 1);
    node->right = array_to_bst(node->right, a, mid + 1, r);
    
    return node;
}

void bfs(Node* node) {
    queue<Node* > q;
    q.push(node);
    while (q.size() > 0) {
        Node* cur = q.front();
        cout << cur->data << " " ;
        q.pop();
        if (cur->left != NULL) {
            q.push(cur->left);
        }
        if (cur->right != NULL){ 
            q.push(cur->right);
        }
    }
}

int main() {
    Node* root = NULL;
    int n;
    cin >> n;

    n = pow(2, n) - 1;
    
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    sort(a, a + n);
    root = array_to_bst(root, a, 0, n - 1);

    bfs(root);

    return 0;
}
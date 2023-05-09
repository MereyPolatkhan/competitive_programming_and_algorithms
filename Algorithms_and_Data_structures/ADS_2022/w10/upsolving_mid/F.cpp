#include <iostream> 

using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int _data){
        this->data = _data;
        this->left = NULL;
        this->right = NULL;
    }
};

struct BST {
    Node *root;
    BST() {
        root = NULL;
    }

    Node *insert(Node *node, int data) {
        if (node == NULL) {
            node = new Node(data);
            return node;
        }

        if (data <= node->data) {
            node->left = insert(node->left, data);
        } 
        else {
            node->right = insert(node->right, data);
        }

        return node;
    
    }
    
    int height(Node* node){
        if (node == NULL) {
            return 0;
        }
        int right_height = height(node->right);
        int left_height = height(node->left);
        return max(right_height, left_height) + 1;
    }

    void level(Node* node, int * lvl, int l) {
        if (node == NULL) {
            return;
        }
        lvl[l] += 1;
        if (node->left != NULL) {
            level(node->left, lvl, l + 1);
        }

        if (node->right != NULL) {
            level(node->right, lvl, l + 1);
        }
    }

    int s = 0;
    void sum(Node* node) {
        if (node == NULL) {
            return;
        }
        sum(node->left);
        s += node->data;
        sum(node->right);
    }

};


int main() {

    int n;
    cin >> n;
    BST b;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        b.root = b.insert(b.root, x);
    }

    int h = b.height(b.root);

    int a[h]; for (int i = 0; i < h; i++) a[i] = 0;

    b.level(b.root, a, 0);

    b.sum(b.root);

    for (int i = 0; i < h; i++) {
        b.s = b.s - (a[i] * i);
    }
    cout << b.s;

    return 0;
}
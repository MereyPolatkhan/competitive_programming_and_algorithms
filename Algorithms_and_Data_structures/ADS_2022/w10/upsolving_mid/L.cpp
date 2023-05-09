#include <iostream> 
#include <vector> 

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


    bool check(Node* node) {
        if (node != NULL && node->left == NULL && node->right == NULL) {
            return true;
        }
        return false;
    }

    int cnt = 0;
    void dfs(Node* node) {
        if (node == NULL) {
            return;
        }
        dfs(node->left);
        if (check(node)) cnt++;
        dfs(node->right);
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

    b.dfs(b.root);
    cout << b.cnt;

    return 0;
}
#include <iostream>

using namespace std;

struct Node {
    Node* left;
    Node* right;

    int data;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};



Node* root;
struct BST {
    
    BST() {
        root = NULL;
    } 

    Node* insert(Node* node, int val) {
        if (node == NULL) {
            Node *n = new Node(val);
            return n;
        }
        else if (val <= node->data) {
            node->left = insert(node->left, val);
        }
        else {
            node->right = insert(node->right, val);
        }

        return node;
    }

    void print(Node *node) {
        if (node == NULL) {
            return;
        }

        print(node->left);
        cout << node->data << " ";
        print(node->right);
    }

    Node* search(Node *node, int val) {
        if (node == NULL) {
            return NULL;
        }
        
        if (node->data == val) {
            return node;
        }
        else if (val <= node->data) {
            search(node->left, val);
        }
        else { // val > node->data;
            search(node->right, val);
        }
    }


    int sizeSubTree(int val){
        Node *sub = search(root, val);
        return sizeSubTree(sub, 0);
    }

    int sizeSubTree(Node* node, int sum) {
        if (node->left == NULL && node->right == NULL){
            sum++;
            return sum;
        }
        if (node->left != NULL && node->right == NULL) {
            return sizeSubTree(node->left, sum) + 1;
        }
        if (node->left == NULL && node->right != NULL) {
            return sizeSubTree(node->right, sum) + 1;
        }
        else 
            return sizeSubTree(node->left, sum) + sizeSubTree(node->right, sum) + 1;
    }

};


int main() {
    // freopen("input.txt", "r", stdin);
    int n;
    cin >> n;

    BST bst;

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        root = bst.insert(root, x);
    }

    // bst.print(root);
    // cout << endl;

    // cout << bst.search(root, 2)->data;

    int x;
    cin >> x;

    cout << bst.sizeSubTree(x);

    return 0;
}
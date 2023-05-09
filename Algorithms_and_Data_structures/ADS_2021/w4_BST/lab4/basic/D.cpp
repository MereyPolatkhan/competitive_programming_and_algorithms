#include <bits/stdc++.h> 

using namespace std;

class Node {
public:
    int data;
    Node *right;
    Node *left;
    Node(int dt){
        data = dt;
        right = NULL;
        left = NULL;
    }
};

class BST {
public:
    Node *root;
    BST() {
        root = NULL;
    }

    Node *insert(Node *node, int value){
        if (node == NULL){
            Node *node = new Node(value);
            return node;
        }
        
        if (node->data < value){
            node->right = insert(node->right, value);
        }
        else {
            node->left = insert(node->left, value);
        }

        return node;
    }

    void in_order(Node *node){
        if (node == NULL){
            return;
        }
        in_order(node->left);
        cout << node->data << endl;
        in_order(node->right);
    }
};

int main() {
    map<int, int> mp;
    BST *bst = new BST();

    while(true){
        int x; cin >> x;
        if (x == 0){
            break;
        }

        mp[x] += 1;
        if (mp[x] < 2){
            bst->root = bst->insert(bst->root, x);
        }
    }

    bst->in_order(bst->root);
    return 0;
}
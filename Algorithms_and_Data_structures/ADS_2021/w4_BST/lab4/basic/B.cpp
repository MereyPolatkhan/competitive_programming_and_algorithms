#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
    int data;
    Node *left, *right;

    Node(int _data){
        data = _data;
        left = NULL;
        right = NULL;
    }
};

int sz = 0;

class BST {
    public:
    Node *root;
    BST(){
        root = NULL;
    }

    Node *insert(Node *node, int data) {
        if (node == NULL) {
            node = new Node(data);
            sz++;
            return node;
        }
        
        if (data <= node->data){
            node->left = insert(node->left, data);
        }
        else {
            node->right = insert(node->right, data);
        }

        return node;
    }

};

int main() {

    BST *bst = new BST();
    
    map<int, int> mp;

    while(true){
        int x; cin >> x;
        if (x == 0){
            break;
        }
        mp[x] += 1;
        if (mp[x] < 2)
            bst->root = bst->insert(bst->root, x);
    }

    cout << sz;
    return 0;
}
#include <bits/stdc++.h> 

using namespace std;

class Node {
    public:
    int data;
    Node *left, *right;

    Node(int _data){
        this->data = _data;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST {
    public:
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

    int second_maximum(Node *node){
        int max_sec;
        Node *previous, *current;

        previous = current = node;

        while(current->right != NULL){
            previous = current;
            current = current->right;
        }

        if (current->left != NULL){
            current = current->left;
            while(current->right != NULL){
                current = current->right;
            }
            max_sec = current->data;
        }
        else{
            max_sec = previous->data;
        }
        
        return max_sec;
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

    cout << bst->second_maximum(bst->root);

    return 0;
}
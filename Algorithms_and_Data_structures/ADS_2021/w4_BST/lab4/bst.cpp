#include <iostream> 
#include <vector> 

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

    Node *search(Node *node, int data) {
        if (node == NULL || node->data == data){
            return node;
        }
        if (node->data < data){
            search(node->right, data);
        }
        else{
            search(node->left, data);
        }
    }

    void inOrder(Node *node){
        if (node == NULL){
            return;
        }
        inOrder(node->left);
        cout << node->data << "\n";
        inOrder(node->right);
    }


    Node *findMin(Node *node){
        while (node->left != NULL){
            node = node->left;
        }
        return node;
    }

    Node *findMax(Node *node){
        while (node->right != NULL){
            node = node->right;
        }
        return node;
    }

    Node *deleteNode(Node *node, int data){
        if (node == NULL){
            return NULL;
        }
        if (data < node->data) {
            node->left = deleteNode(node->left, data);
        }
        else if (data > node->data) {
            node->right = deleteNode(node->right, data);
        }
        else {
            if (node->left == NULL && node->right == NULL) {
                return NULL;
            } 
            else if (node->left == NULL){
                node = node->right;
            }
            else if (node->right == NULL){
                node = node->left;
            }
            else {
                Node *left_max = findMax(node->left);
                node->data = left_max->data;
                node->left = deleteNode(node->left, left_max->data);
            }
        }
        return node;
    }
};


int main() {

    BST *bst = new BST();
    bst->root = bst->insert(bst->root, -10);
    bst->root = bst->insert(bst->root, -5);
    bst->root = bst->insert(bst->root, 2);
    bst->root = bst->insert(bst->root, 3);
    bst->root = bst->insert(bst->root, 10);
    bst->root = bst->insert(bst->root, 20);
    bst->root = bst->insert(bst->root, 27);
    bst->root = bst->insert(bst->root, 45);

    // cout << bst->root->left->right->left->data << endl;
    // cout << bst->root->data << endl;
    // bst->root = bst->deleteNode(bst->root, 5);

    bst->inOrder(bst->root);

    return 0;
}
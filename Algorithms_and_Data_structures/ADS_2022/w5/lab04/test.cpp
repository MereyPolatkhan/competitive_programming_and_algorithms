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
 
        return node;
    }

    void inOrder(Node *node){
        if (node == NULL){
            return;
        }
        inOrder(node->left);
        cout << node->data << "\n";
        inOrder(node->right);
    }





    int solve(Node* node, int l, int r) {
        Node* left_node = search(node, l);
        Node* right_node = search(node, r);

        dfs(node, left_node, right_node);
        return cnt;
    }

    int cnt = 2;
    void dfs(Node* node, Node* left_node, Node* right_node) {
        if (node == NULL || node == left_node || node == right_node) {
            cnt++;
            return;
        }
        cnt++;
        dfs(node->left, left_node, right_node);
        dfs(node->right, left_node, right_node);
    } 

};


int main() {

    BST *bst = new BST();
    bst->root = bst->insert(bst->root, 5);
    bst->root = bst->insert(bst->root, 3);
    bst->root = bst->insert(bst->root, 6);
    bst->root = bst->insert(bst->root, 1);
    bst->root = bst->insert(bst->root, 4);
    bst->root = bst->insert(bst->root, 8);
    bst->root = bst->insert(bst->root, 0);
    bst->root = bst->insert(bst->root, 2);
    bst->root = bst->insert(bst->root, 10);
    bst->root = bst->insert(bst->root, 9);


    int l, r;
    cin >> l >> r;

    cout << bst->solve(bst->root, l, r);
 
    return 0;
}
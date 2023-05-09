#include <iostream> 
#include <map> 
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

class BST {
    public:
    Node *root;
    BST() {
        root = NULL;
    }

    Node *insert(Node *node, int data) {
        if (node == NULL) {
            Node *node = new Node(data);
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

    cout << bst->height(bst->root);
    return 0;
}
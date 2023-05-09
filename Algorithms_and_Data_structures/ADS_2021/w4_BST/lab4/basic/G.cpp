#include <iostream> 
#include <map> 

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

    void only_one_baby(Node *node){
        if (node == NULL) return;
        
        only_one_baby(node->left);
        
        if ((node->left != NULL && node->right == NULL) || (node->left == NULL && node->right != NULL)) {
            cout << node->data << endl;
            
        }
        
        only_one_baby(node->right);
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

    bst->only_one_baby(bst->root);

    return 0;

}
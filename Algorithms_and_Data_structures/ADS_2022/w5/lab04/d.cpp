#include <iostream>
#include <queue>
#include <vector>

using namespace std;


struct Node {
    Node* left;
    Node* right;
    int data;
    Node() {

    }
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

};



struct BST {
    BST() {
        
    }

    Node* insert(Node* node, int data) {
        if (node == NULL) {
            Node* newNode = new Node(data);
            return newNode;
        }
        else if (data <= node->data) {
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

    void level(Node* node, vector<int>& lvl, int l) {
        if (node == NULL) {
            return;
        }
        
        lvl[l] += node->data;

        if (node->left != NULL) {
            level(node->left, lvl, l + 1);
        }

        if (node->right != NULL) {
            level(node->right, lvl, l + 1);
        }
    }
    
};

int main() {
    // freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    BST bst;
    Node *root = NULL;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        root = bst.insert(root, x);
    }


    int height = bst.height(root);
    cout << height << "\n";

    vector<int> lvl(height, 0);
    
    bst.level(root, lvl, 0);

    for (int i = 0; i < height; i++) {
        cout << lvl[i] << " ";
    }

    return 0;
}
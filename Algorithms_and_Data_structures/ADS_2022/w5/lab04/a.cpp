#include <bits/stdc++.h>

using namespace std;

struct Node {
    Node* left;
    Node* right;
    int key;

    Node() {
        this->key = 0;
        left = NULL;
        right = NULL;
    }

    Node(int key) {
        this->key = key;
        this->left = NULL;
        this->right = NULL;    
    }

    Node(int key, Node* left, Node* right) {
        this->key = key;
        this->left = left;
        this->right = right;
    }
};

struct BST {
    Node* root;

    BST() {
        root = NULL;
    }

    Node* insert(Node* node, int data) {
        if (node == NULL) {
            Node* node = new Node(data);
            return node;
        }

        else if (data <= node->key) {
            node->left = insert(node->left, data);
        }
        else {   
            node->right = insert(node->right, data);
        }
        return node;
    }

    void print(Node* node) { // dfs
        if (node == NULL) {
            return;
        }
        print(node->left);
        cout << node->key << " ";
        print(node->right);
    }

    bool trueCase(Node* node) {
        // if (node != NULL && node->right == NULL && node->left == NULL) {
        if (node != NULL) {
            return true;
        }
        return false;
    }

    bool isPath(string s) {
        Node* temp = root;
        for (int i = 0; i < s.size(); i++) {
            if (temp == NULL) {
                return false;
            }

            char c = s[i];
            
            if (c == 'R') {
                temp = temp->right;
            }

            else if (c == 'L') {
                temp = temp->left;
            }
        }

        return trueCase(temp);
    }
};

int main() {
    // freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    BST* bst = new BST();
    for (int i = 0; i < n; i++) {
        int x; 
        cin >> x;
        bst->root = bst->insert(bst->root, x);
    }

    // bst->print(bst->root);
    // cout << endl;

    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;

        if (bst->isPath(s) == true) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }




    return 0;
}
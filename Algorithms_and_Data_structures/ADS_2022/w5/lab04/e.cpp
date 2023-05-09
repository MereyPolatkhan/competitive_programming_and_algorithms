#include <bits/stdc++.h>

using namespace std;

struct Node {
    Node* right;
    Node* left;
    int data;
    Node() {

    }
    Node(int data) {
        this->data = data;
        this->right = this->left = NULL;
    }
};

struct BST {
    Node* root;
    BST() {
        root = new Node(1);
    }

    void insert(Node* node, int where, int val, int LorR) {
        if (node == NULL) {
            return;
        }
        if (node->data == where) {
            if (LorR == 0) {
                node->left = new Node(val);
            }
            else {
                node->right = new Node(val);
            }
            return;
        }
        insert(node->left, where, val, LorR);
        insert(node->right, where, val, LorR);
    }

    int height(Node* node) {
        if (node == NULL) {
            return 0;
        }
        int l = height(node->left);
        int r = height(node->right);
        return max(l, r) + 1;
    }

    void count(vector<int> & lvl, Node* node, int cnt = 0) {
        if (node == NULL) {
            return;
        }
        lvl[cnt] += 1;

        if (node->left != NULL) {
            count(lvl, node->left, cnt + 1);
        }
        if (node->right != NULL) {
            count(lvl, node->right, cnt + 1);
        }

    }

};


int main() {
    // freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    BST b;

    for (int i = 0; i < n-1; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        b.insert(b.root, x, y, z);
    }   

    vector<int> lvl(b.height(b.root), 0);

    b.count(lvl, b.root);

    int mx = -1;
    for (auto i: lvl){
        mx = max(mx, i);
    }
    cout << mx;

    return 0;
}
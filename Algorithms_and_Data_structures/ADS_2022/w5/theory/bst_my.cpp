#include <iostream>
#include <queue>

using namespace std;

struct Node {
    Node* left;
    Node* right;
    int data;
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *root = NULL;
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

    void dfs_In_Order(Node* node) {
        if (node == NULL) {
            return;
        }
        dfs_In_Order(node->left);
        cout << node->data << " ";
        dfs_In_Order(node->right);
    }

    void dfs_Pre_Order(Node* node) {
        if (node == NULL) {
            return;
        }
        cout << node->data << " ";
        dfs_Pre_Order(node->left);
        dfs_Pre_Order(node->right);
    }

    void dfs_Post_Order(Node* node) {
        if (node == NULL) {
            return;
        }
        dfs_Post_Order(node->left);
        dfs_Post_Order(node->right);
        cout << node->data << " ";
    }

    void bfs(Node *node) {
        queue<Node *> q;
        q.push(node);
        
        while (q.size() > 0) {
            Node* temp = q.front();
            cout << temp->data << " ";
            q.pop();
            if (temp->left != NULL) {
                q.push(temp->left);
            }
            if (temp->right != NULL) {
                q.push(temp->right);
            }
        }
    }

    Node* search(Node* node, int val) {
        if (node->data == val || node == NULL) {
            return node;
        }

        else if (val <= node->data) {
            return search(node->left, val);
        }
        else {
            return search(node->right, val);
        }
    }

    
};

int main() {

    // freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    BST bst;

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        root = bst.insert(root, x);
    }

    // cout << "pre order: "; bst.dfs_Pre_Order(root); cout << "\n";
    // cout << "bfs: "; bst.bfs(root); cout << "\n";


    int k;
    cin >> k;

    Node* subTree = bst.search(root, k);

    bst.dfs_Pre_Order(subTree);


    return 0;
}
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
int counter = 0;
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


    bool check(Node* node) {
        if (node != NULL && node->left != NULL && node->right != NULL){ 
            return true;
        }
        return false;
    }

    void bfs(Node *node) {
        queue<Node *> q;
        q.push(node);
        
        while (q.size() > 0) {
            Node* temp = q.front();
            q.pop();
            
            if (check(temp) == true) {
                counter++;
            }
            
            if (temp->left != NULL) {
                q.push(temp->left);
            }
            if (temp->right != NULL) {
                q.push(temp->right);
            }
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

    bst.bfs(root);
    cout << counter;
    return 0;
}
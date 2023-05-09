#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
    int cnt;

	Node(int data) {
        cnt = 1;
		this->data = data;
		left = NULL;
		right = NULL;
	} 
};

Node* getMin(Node* root) {
	while (root->left != NULL) {
		root = root->left;
	}
	return root;
}

Node* add(Node* root, int data) {
	if (root == NULL) {
		return new Node(data);
	} 
    
    if (root->data == data) {
        root->cnt++;
        return root;
    }
    
    else if (root->data > data) {
		if (root->left == NULL) {
			root->left = new Node(data);
		} else {
			root->left = add(root->left, data);
		}
	} 
    
    else if (root->data < data) {
		if (root->right == NULL) {
			root->right = new Node(data);
		} else {
			root->right = add(root->right, data);
		}
	}
	
    return root;
}

Node* deleteNode(Node* root, int data) {
	if (root == NULL) {
		return NULL;
	} 
    else if (root->data > data) {
		root->left = deleteNode(root->left, data);
		return root;
	} 
    else if (root->data < data) {
		root->right = deleteNode(root->right, data);
		return root;
	} 
    else if (root->data == data) { 
        if (root->cnt > 0) root->cnt--;
        // if (root->cnt >= 2) {
        //     root->cnt--;
        //     return root;
        // }
        // else if (root->cnt == 1){
        //     if (root->left == NULL && root->right == NULL) {
        //         delete root;
        //         return NULL;
        //     } else if (root->right == NULL) {
        //         Node* temp = root->left;
        //         delete root;
        //         return temp;
        //     } else if (root->left == NULL) {
        //         Node* temp = root->right;
        //         delete root;
        //         return temp;
        //     } else {
        //         Node* temp = getMin(root->right);
        //         root->data = temp->data;
        //         root->right = deleteNode(root->right, temp->data);
        //         return root;
        //     }
        // }
	}
    return root;
}

Node* find(Node* root, int x) {
	if (root == NULL) {
		return NULL;
	} else if (root->data == x) {
		return root;
	} else if (root->data < x) {
		return find(root->right, x);
	} else {
		return find(root->left, x);
	}
}


int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    
    Node* root = NULL;
    
    int n;
    cin >> n;

    while (n--){
        string s; int x;
        cin >> s >> x;
        if (s == "insert") {
            root = add(root, x);
        }
        else if (s == "cnt") {
            Node* node = find(root, x);
            if (node == NULL) {
                cout << 0 << "\n";
            }
            else {
                cout << node->cnt << "\n";
            }
        }
        else {
            root = deleteNode(root, x);
        }
    }

    return 0;
}
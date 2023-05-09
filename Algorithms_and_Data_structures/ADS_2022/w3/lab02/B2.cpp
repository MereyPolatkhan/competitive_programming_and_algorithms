// ахахаххаха хитрожопский вариант 
// за O(N)

#include <iostream>
using namespace std;

struct Node {
	string word;
	Node* next;

	Node() {}

	Node(string word) {
		this->word = word;
		this->next = NULL;
	}
};

// your code goes here

    
Node* cyclicShift(Node* head, int k) {
    // for (int i = 0; i < k; i++) {
        Node * newHead = head;
        while (newHead->next != NULL) {
            newHead = newHead->next;
        }    
        newHead->next = head;
    // }
    return head;
}

void print(Node* head, int cnt, int k) {
	Node* cur = head;
    while (k--) {
        cur = cur->next;
    }
	while (cnt--) {
		cout << cur->word << " ";
		cur = cur->next;
	}
	cout << endl;
}

int main() {
	int n; cin >> n;
	int k; cin >> k;
	Node* head;
	Node* cur;
	for (int i = 0; i < n; i++) {
		string word; cin >> word;
		if (i == 0) {
			head = new Node(word);
			cur = head;
		} else {
			cur->next = new Node(word);
			cur = cur->next;
		}
	}

	head = cyclicShift(head, k);
    int cnt = n;
	print(head, cnt, k);
}
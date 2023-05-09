// Runtime error

#include <iostream>

using namespace std;

const int N = 26;

class Node  {
    public:
    char value;
    Node *ch[N];
    int k;

    Node(char _value) {
        this->value = _value;
        for (int i = 0; i < N; i++) 
            this->ch[i] = NULL;
        k = 1;
    }
};

class Trie {
    public:
    Node *root;
    int cnt;
    Trie() {
        root = new Node('*');
        this->cnt = 0;
    }

    void insert(string s) { // abcd
        Node *cur = root;
        for (int i = 0; i < s.size(); i++) {
            if (cur->ch[s[i] - 'a'] != NULL) {
                cur = cur->ch[s[i] - 'a'];
                cur->k += 1;
            }
            else {
                Node *node = new Node(s[i]);
                cur->ch[s[i] - 'a'] = node;
                cur = node;
                this->cnt++;
            }
        } 
    }
};


int main() {

    int n;
    cin >> n;

    for (int j = 0; j < n; j++) {
        string s;
        cin >> s;
        Trie *trie = new Trie();
        for (int i = 0; i < s.size(); i++) {
            trie->insert(s.substr(i, s.size() - i));
        }
        cout << trie->cnt << '\n';
    }
    return 0;
}
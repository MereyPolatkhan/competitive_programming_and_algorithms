//Memory limit exceeded
#include <iostream> 

using namespace std;

const int N = 26;

class Node {
public:
    char value;
    Node *ch[N];
    int k;

    Node(char _val) {
        this->value = _val;
        for (int i = 0; i < N; i++) {
            this->ch[i] = NULL;
        }
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

    void insert(string s) {
        Node *cur = root;
        for (int i = 0; i < s.size(); i++) {
            if (cur->ch[s[i] - 'a'] != NULL) {
                cur = cur->ch[s[i] - 'a'];
                cur->k++;
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
    Trie *trie = new Trie();
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        trie->insert(s.substr(i, s.size() - i));
    }
    cout << trie->cnt;

    return 0;
}

class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;
    
    Node(int key, int val) {
        this->key = key;
        this->val = val;
        prev = next = NULL;
    }   
};

class LRUCache {
public:
    unordered_map <int, Node*> ump;
    int capacity;
    Node* left;
    Node* right;

    LRUCache(int capacity) {
        this->capacity = capacity;
        left = new Node(1e9, 1e9);
        right = new Node(1e9, 1e9);
        left->next = right;
        left->prev = NULL;
        right->prev = left;
        right->next = NULL;    
    }

    void remove(Node* curr) {// O(1)
        Node* l = curr->prev;
        Node* r = curr->next;
        l->next = r;
        r->prev = l;
    }

    void insert(Node* node) {// O(1)
        Node* curr = right->prev;
        curr->next = node;
        node->prev = curr;
        node->next = right;
        right->prev = node;
    }
    
    int get(int key) {// O(1)
        if (ump.count(key) == 0) {
            return -1;
        }
        Node* node = ump[key];
        remove(ump[key]);
        insert(node);
        return node->val;
    }
    
    void put(int key, int value) {// O(1)
        if (ump.count(key) != 0) {
            remove(ump[key]);
        }
        Node* node = new Node(key, value);
        insert(node);
        ump[key] = node;


        if (ump.size() > capacity) {
            ump.erase(left->next->key); 
            remove(left->next);
        }
    }
};

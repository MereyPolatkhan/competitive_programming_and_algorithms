class RandomizedSet {
public:
    unordered_map<int, int> m;
    vector<int> a;

    RandomizedSet() {

    }
    
    bool insert(int val) {
        if (m.count(val) != 0) {
            return false;
        }
        a.push_back(val);
        m[val] = a.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (m.count(val) == 0) {
            return false;
        }

        int cur_index = m[val];
        int el = a[a.size() - 1];
        swap(a[cur_index], a[a.size() - 1]);
        a.pop_back();
        m[el] = cur_index;
        m.erase(val);
        return true;
    }
    
    int getRandom() {
        // srand(time(0));
        // for (auto i : a) cout << i << " "; cout << "\n";
        srand(time(NULL) + rand());
        return a[rand() % a.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
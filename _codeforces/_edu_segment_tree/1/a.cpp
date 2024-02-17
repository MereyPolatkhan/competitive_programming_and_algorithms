#include <iostream>
#include <vector>



using namespace std;


struct segmentTree {
    vector<long long> tree;
    int sz;

    void init(int n) {
        sz = 1;
        while (sz < n) {
            sz *= 2;
        }
        tree.resize(2 * sz - 1, 0);
        cout << "tree size: " << tree.size() << "\n";
    }


    void build(vector<int> &a, int x, int lx, int rx) {
        cout << "lx: " << lx << "   rx: " << rx  << "   x: " << x << "\n";
        if (lx == rx - 1) {
            if (lx < a.size()) {
                tree[x] = a[lx]; 
                cout << "done at tree[" << x << "] = a[" << lx << "]\n";
            }
        }
        else {
            int m = (lx + rx) / 2;
            build(a, 2 * x + 1, lx, m);
            build(a, 2 * x + 2, m, rx);
            tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
        }

    }
    void build(vector<int> &a) {
        init(a.size());
        build(a, 0, 0, sz);
    } 


    void set(int i, int val, int x, int lx, int rx) {
        if (lx == rx - 1) {
            tree[x] = val;
        }
        else {
            int m = (lx + rx) / 2;
            if (i < m) {
                set(i, val, 2 * x + 1, lx, m);
            }
            else {
                set(i, val, 2 * x + 2, m, rx);
            }
            tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
        }
    }

    void set(int i, int val) {
        set(i, val, 0, 0, sz);
    }


    long long sum(int l, int r, int x, int lx, int rx) {
        if (l >= rx || lx >= r) {
            return 0;
        }
        else if (l <= lx and rx <= r) {
            return tree[x];
        }
        else {
            int m = (lx + rx) / 2;
            long long s1 = sum(l, r, 2 * x + 1, lx, m);
            long long s2 = sum(l, r, 2 * x + 2, m, rx);
            return s1 + s2;
        }
    }

    long long sum(int l, int r) {
        return sum(l, r, 0, 0, sz);
    }
};

int main() {
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif


    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    segmentTree st;
    st.build(a);

    while (m--) {
        int t;
        cin >> t;
        if (t == 1) {
            int i, v;
            cin >> i >> v;
            st.set(i, v);
        }   
        if (t == 2) {
            int l, r;
            cin >> l >> r;
            cout << st.sum(l, r) << "\n";
        }   
    }

    for (int i = 0; i < st.tree.size(); i++) {
        cout << "i: " << i << "   tree[i]: " << st.tree[i] << "\n";
    }

    return 0;
}
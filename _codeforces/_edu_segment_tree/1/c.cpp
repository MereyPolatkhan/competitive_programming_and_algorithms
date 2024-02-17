#include <iostream>
#include <vector>

using namespace std;

class segtree {
public:
    int sz;
    vector< pair<int, int> > tree;

    void init(int n) {
        sz = 1;
        while (sz < n)  
            sz *= 2;
        tree.resize(2 * sz, {0, 0});
    }

    pair<int, int> combine(pair<int, int> a, pair<int, int> b) {
        if (a.first < b.first) 
            return a;
        else if (a.first > b.first) 
            return b;
        return {a.first, a.second + b.second};
    }

    void build(vector<int> &a, int x, int lx, int rx) {
        if (lx == rx - 1) {
            if (lx < a.size()) 
                tree[x] = {a[lx], 1};
        }
        else {
            int m = (lx + rx) / 2;
            build(a, 2 * x + 1, lx, m);
            build(a, 2 * x + 2, m, rx);

            tree[x] = combine(tree[2 * x + 1], tree[2 * x + 2]);
        }
    }

    pair<int, int> getMin(int l, int r, int x, int lx, int rx) {
        if (lx >= r or l >= rx) {
            return {INT_MAX, 0};
        }
        else if (l <= lx and rx <= r) {
            return tree[x];
        }
        else {
            int m = (lx + rx) / 2;
            pair<int, int> left_child = getMin(l, r, 2 * x + 1, lx, m);
            pair<int, int> right_child = getMin(l, r, 2 * x + 2, m, rx);

            return combine(left_child, right_child);
        }
    }

    void set(int i, int val, int x, int lx, int rx) {
        if (lx == rx - 1) {
            tree[x] = {val, 1};
        }
        else {
            int m = (lx + rx) / 2;
            if (i < m) {
                set(i, val, 2 * x + 1, lx, m);
            }
            else {
                set(i, val, 2 * x + 2, m, rx);
            }
            tree[x] = combine(tree[2 * x + 1], tree[2 * x + 2]);
        }
    }


    void build(vector<int> &a) {
        init(a.size());
        build(a, 0, 0, sz);
    }

    pair<int, int> getMin(int l, int r) {
        return getMin(l, r, 0, 0, sz);
    }
    void set(int i, int v) {
        set(i, v, 0, 0, sz);
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

    segtree st;
    st.build(a);


    while (m--) {
        int w;
        cin >> w;
        if (w == 1) {
            int i, v;
            cin >> i >> v;  
            st.set(i, v);
        }
        else if (w == 2) {
            int l, r;
            cin >> l >> r;

            pair<int, int> res = st.getMin(l, r);
            cout << res.first << " " << res.second << "\n";
        }
    }

    return 0;
}
#include <iostream>
#include <vector>



using namespace std;

struct SegTree {
    int sz = 1;
    vector<int> tree;

    void init(int n) {
        while (sz < n) {
            sz *= 2;
        }
        tree.assign(2 * sz, INT_MAX);
    }

    void built(vector<int> &a, int x, int lx, int rx) {
        if (lx == rx - 1) {
            if (lx < a.size()) {
                tree[x] = a[lx];
            }
        }
        else {
            int m = (lx + rx) / 2;
            built(a, 2 * x + 1, lx, m);
            built(a, 2 * x + 2, m, rx);
            tree[x] = min(tree[2 * x + 1], tree[2 * x + 2]);
        }
    }

    void built(vector<int> &a) {
        init(a.size());

        built(a, 0, 0, sz);
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
            tree[x] = min(tree[2 * x + 1], tree[2 * x + 2]);
        }
    }

    void set(int i, int val) {
        set(i, val, 0, 0, sz);
    }



    int getMin(int l, int r, int x, int lx, int rx) {
        if (l >= rx or lx >= r) {
            return INT_MAX;
        }
        else if (l <= lx and rx <= r) {
            return tree[x];
        }
        else {
            int m = (lx + rx) / 2;
            return min(
                getMin(l, r, 2 * x + 1, lx, m),
                getMin(l, r, 2 * x + 2, m, rx)
            );
        }
    }
    
    int getMin(int l, int r) {
        return getMin(l, r, 0, 0, sz);
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

    SegTree st;
    st.built(a);

    while (m--) {
        int x;
        cin >> x;
        if (x == 1) {
            int i, val;
            cin >> i >> val;
            st.set(i, val);
        }
        else {
            int l, r;
            cin >> l >> r;
            cout << st.getMin(l, r) << "\n";
        }
    }





    return 0;
}
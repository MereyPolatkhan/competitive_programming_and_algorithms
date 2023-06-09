#include <bits/stdc++.h> 

using namespace std;

struct SegTree {
    vector<long long> tree;
    int size;

    void init(int n) {
        size = 1;
        while (size < n) size = size * 2;
        tree.assign(2 * size - 1, 0);
    }

    void set(int i, int v, int x, int lx, int rx) {
        if (lx == rx - 1) {
            tree[x] = v;
            return;
        }

        int m = (lx + rx) / 2;
        if (i < m) {
            set(i, v, 2 * x + 1, lx, m);
        }
        else {
            set(i, v, 2 * x + 2, m, rx);
        }
        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }

    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }


    long long sum(int l, int r, int x, int lx, int rx) {
        if (l >= rx || lx >= r) {
            return 0;
        }
        
        if (lx >= l && rx <= r) {
            return tree[x];
        }

        int m = (lx + rx) / 2;
        long long s1 = sum(l, r, 2 * x + 1, lx, m);
        long long s2 = sum(l, r, 2 * x + 2, m, rx);

        return s1 + s2;
    }

    long long sum(int l, int r) {
        return sum(l, r, 0, 0, size);
    }
};


int main() {
    // freopen("input.txt", "r", stdin);

    ios::sync_with_stdio(false);
    cin.tie(0);


    int n, m;
    cin >> n >> m;

    SegTree st;
    st.init(n);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        st.set(i, x);
    }

    for (int i = 0; i < st.tree.size(); i++) {
        cout << st.tree[i] << " " ;
    }
    cout << endl;

    for (int t = 0; t < m; t++) {
        int c;
        cin >> c;
        if (c == 1) {
            int i, v;
            cin >> i >> v;
            st.set(i, v);
        }
        else if (c == 2) {
            int l, r;
            cin >> l >> r;
            cout << st.sum(l, r) << "\n";
        }
    }

    return 0;
}
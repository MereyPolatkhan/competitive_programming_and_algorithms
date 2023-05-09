#include <bits/stdc++.h>

using namespace std;

#define ll long long

vector <ll> tree;
int size;

void init(int n) {
    size = 1;
    while (size < n) {
        size *= 2;
    }
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
    else if (m <= i) {
        set(i, v, 2 * x + 2, m, rx);
    }

    tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
}

void set(int i, int v) {
    set(i, v, 0, 0, size);
}


ll sum(int l, int r, int x, int lx, int rx) {
    if (l >= rx || r <= lx) {
        return 0;
    }

    if (l <= lx && rx <= r) {
        return tree[x];
    }

    int m = (lx + rx) / 2;
    ll s1 = sum(l, r, 2 * x + 1, lx, m);
    ll s2 = sum(l, r, 2 * x + 2, m, rx);

    return s1 + s2;
}

ll sum(int l, int r) {
    return sum(l, r, 0, 0, size);
}



int main() {
    freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    int a[n];
    init(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        int c; cin >> c;

        if (c == 1) {
            int i, v;
            cin >> i >> v;
            set(i, v);
        }
        else if (c == 2) {
            int l, r;
            cin >> l >> r;
            cout << sum(l, r) << "\n";
        }   
    }

    return 0;
}
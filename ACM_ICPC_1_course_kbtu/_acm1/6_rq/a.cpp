#include <bits/stdc++.h>

using namespace std;



const int sz = 1e6;
int t[sz * 4];

void build(vector<int> &a, int l, int r, int tree_index=1) {
    if (l > r) {
        return;
    }
    if (l == r) {
        t[tree_index] = a[l];
        return;
    }

    int mid = (l + r) / 2;
    build(a, l, mid, tree_index * 2);
    build(a, mid + 1, r, tree_index * 2 + 1);
    t[tree_index] = min(t[tree_index * 2], t[tree_index * 2 + 1]);
}

void build(vector<int> & a) {
    build(a, 0, a.size() - 1);
}


int get_min(int l, int r, int L, int R, int tree_index=1) {
    if (r < L or R < l) {
        return 1e9;
    }
    if (l <= L and R <= r) {
        return t[tree_index];
    }
    int mid = (L + R) / 2;
    int ans = min(
        get_min(l, r, L, mid, tree_index * 2),
        get_min(l, r, mid + 1, R, tree_index * 2 + 1)
    );
    return ans;
}

void change_element(int index, int value, int L, int R, int tree_index=1) {
    if (L > R) {
        return;
    }
    if (L > index || R < index) {
        return;
    }
    if (L == R) {
        t[tree_index] = value;
    }
    int mid = (L + R) / 2;
    change_element(index, value, L, mid, tree_index * 2);
    change_element(index, value, mid + 1, R, tree_index * 2 + 1);
    t[tree_index] = min(t[tree_index * 2], t[tree_index * 2 + 1]);
}

int main() {
    
    freopen("stupid_rmq.in", "r", stdin);
    freopen("stupid_rmq.out", "w", stdout);
    
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }


    build(a);

    int m;
    cin >> m;

    while (m--) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        cout << get_min(l, r, 0, n - 1) << "\n";
    }

    return 0;
}
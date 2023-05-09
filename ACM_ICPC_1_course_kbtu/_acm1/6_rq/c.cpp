#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


int t_min[4000000];

void build_min(vector<int> &a, int l, int r, int tree_index=1) {
    if (l > r) {
        return;
    }
    if (l == r) {
        t_min[tree_index] = a[l];
        return;
    }

    int mid = (l + r) / 2;
    build_min(a, l, mid, tree_index * 2);
    build_min(a, mid + 1, r, tree_index * 2 + 1);
    t_min[tree_index] = min(t_min[tree_index * 2], t_min[tree_index * 2 + 1]);
}

void build_min(vector<int> & a) {
    build_min(a, 0, a.size() - 1);
}


int get_min(int l, int r, int L, int R, int tree_index=1) {
    if (r < L or R < l) {
        return 1e9;
    }
    if (l <= L and R <= r) {
        return t_min[tree_index];
    }
    int mid = (L + R) / 2;
    int ans = min(
        get_min(l, r, L, mid, tree_index * 2),
        get_min(l, r, mid + 1, R, tree_index * 2 + 1)
    );
    return ans;
}

void change_element_min(int index, int value, int L, int R, int tree_index=1) {
    if (L > R) {
        return;
    }
    if (L > index || R < index) {
        return;
    }
    if (L == R) {
        t_min[tree_index] = value;
        return;
    }
    int mid = (L + R) / 2;
    change_element_min(index, value, L, mid, tree_index * 2);
    change_element_min(index, value, mid + 1, R, tree_index * 2 + 1);
    t_min[tree_index] = min(t_min[tree_index * 2], t_min[tree_index * 2 + 1]);
}

void print_t_min(vector<int> &v){ 
    for(int i = 0; i < v.size()*2; i++) { 
        cout << t_min[i] << ' '; 
    } 
    cout << endl; 
} 



int t_max[4000000];

void build_max(vector<int> &a, int l, int r, int tree_index=1) {
    if (l > r) {
        return;
    }
    if (l == r) {
        t_max[tree_index] = a[l];
        return;
    }

    int mid = (l + r) / 2;
    build_max(a, l, mid, tree_index * 2);
    build_max(a, mid + 1, r, tree_index * 2 + 1);
    t_max[tree_index] = max(t_max[tree_index * 2], t_max[tree_index * 2 + 1]);
}

void build_max(vector<int> & a) {
    build_max(a, 0, a.size() - 1);
}


int get_max(int l, int r, int L, int R, int tree_index=1) {
    if (r < L or R < l) {
        return -1e9;
    }
    if (l <= L and R <= r) {
        return t_max[tree_index];
    }
    int mid = (L + R) / 2;
    int ans = max(
        get_max(l, r, L, mid, tree_index * 2),
        get_max(l, r, mid + 1, R, tree_index * 2 + 1)
    );
    return ans;
}

void change_element_max(int index, int value, int L, int R, int tree_index=1) {
    if (L > R) {
        return;
    }
    if (L > index || R < index) {
        return;
    }
    if (L == R) {
        t_max[tree_index] = value;
        return;
    }
    int mid = (L + R) / 2;
    change_element_max(index, value, L, mid, tree_index * 2);
    change_element_max(index, value, mid + 1, R, tree_index * 2 + 1);
    t_max[tree_index] = max(t_max[tree_index * 2], t_max[tree_index * 2 + 1]);
}


void print_t_max(vector<int> &v){ 
    for(int i = 0; i < v.size()*2; i++) { 
        cout << t_max[i] << ' '; 
    } 
    cout << endl; 
} 



const ll N = (ll)100001;

ll poww(ll n, ll x) {
    if (x == 2) {
        return (n * n) % 12345;
    }
    else if (x == 3) {
        return (n * n * n) % 23456;
    }
    return -1;
}


int main() {
    freopen("rvq.in", "r", stdin);
    freopen("rvq.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        a[i] = poww(i, 2) + poww(i, 3);
    }   


    build_max(a);
    build_min(a);

    int L = 0;
    int R = 100000;
    
    int t;
    cin >> t;

    while (t--) {
        int x, y;
        cin >> x >> y;
        // x--; y--;

        if (x > 0) {
            // max - min
            cout << (get_max(x, y, L, R) - get_min(x, y, L, R)) << "\n";
        }
        else if (x < 0) {
            ll xi = abs(x);
            // xi--;
            // a[xi] = y
            change_element_min(xi, y, L, R);
            change_element_max(xi, y, L, R);
        }
    }




    return 0;
}
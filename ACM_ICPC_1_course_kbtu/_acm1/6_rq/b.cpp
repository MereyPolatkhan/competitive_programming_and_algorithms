#include <bits/stdc++.h>

using namespace std;

#define ll long long 

ll n, q; 


struct segtree {

    ll t[4000007];

    void build(vector<ll> &a, ll l, ll r, ll tree_index=1) {
        if (l > r) {
            return;
        }
        if (l == r) {
            t[tree_index] = a[l];
            return;
        }

        ll mid = (l + r) / 2;
        build(a, l, mid, tree_index * 2);
        build(a, mid + 1, r, tree_index * 2 + 1);
        t[tree_index] = (t[tree_index * 2] + t[tree_index * 2 + 1]);
    }

    void build(vector<ll> & a) {
        build(a, 0, a.size() - 1);
    }


    ll get_sum(ll l, ll r, ll L, ll R, ll tree_index=1) {
        if (r < L or R < l) {
            return 0;
        }
        if (l <= L and R <= r) {
            return t[tree_index];
        }
        ll mid = (L + R) / 2;
        ll ans =  get_sum(l, r, L, mid, tree_index * 2) + get_sum(l, r, mid + 1, R, tree_index * 2 + 1);
        
        return ans;
    }

    void change_element(ll index, ll value, ll L, ll R, ll tree_index=1) {
        // cout << "  >>>> "  << L << " " << R << "\n";
        if (index < 0 || index > n - 1) {
            return;
        }
        if (L > R) {
            return;
        }
        if (L > index || R < index) {
            return;
        }
        if (L == R) {
            t[tree_index] = value;
            return;
        }
        ll mid = (L + R) / 2;
        change_element(index, value, L, mid, tree_index * 2);
        change_element(index, value, mid + 1, R, tree_index * 2 + 1);
        t[tree_index] = (t[tree_index * 2] + t[tree_index * 2 + 1]);
    }

};

int main() {
   
    segtree s;
    
    cin >> n >> q;

    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    s.build(a);

    while (q--) {
        char c;
        cin >> c;
        if (c == '?') {
            ll left, right;
            cin >> left >> right;
            left--;
            right--;
            cout << s.get_sum(left, right, 0, n - 1) << "\n";
        }       
        else {
            ll ind, d;
            cin >> ind >> d;
            ind--;

            s.change_element(ind, d, 0, n - 1);
        }
    }

    return 0;
}
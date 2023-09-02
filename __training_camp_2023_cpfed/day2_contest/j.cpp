#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

void print(vector<int>& a) {
    cout << " ==> ";
    for (int &i: a) cout << i << " ";
    cout << "\n\n";
}

vector<ll> make_pref(vector<int> b) {
    vector<ll> a;
    for (int &x: b) a.pb(x);

    for (int i = 1; i < a.size(); i++) {
        a[i] += a[i - 1];
    }

    return a;
}

vector<ll> make_suf(vector<int> b) {
    vector<ll> a;
    for (int &x: b) a.pb(x);

    for (int i = a.size() - 2; i >= 0; i--) {
        a[i] += a[i + 1];
    }
    return a;
}



// check when N = 1;

int n, m;

ll func(vector<ll> &pf, vector<int> &a, int i) {
    if (i == 0) {
        return pf[n - 1] - pf[0];
    }
    if (i == n - 1) {
        return pf[n - 2];
    }

    ll all = pf[n - 1] + m - a[i];
    ll left = pf[i - 1];
    ll right = pf[n - 1] - pf[i];

    return max(max(left, right), all);
}

void solve() {

    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (n == 1) {
        cout << m << "\n";
        return;
    }

    vector<ll> pf = make_pref(a);


    vector<ll> res;

    for (int i = 0; i < n; i++) {
        res.pb(func(pf, a, i));
    }

    for (ll &x: res) cout << x << " ";
}


/*  things to check:
    1) long long    
    2) array sizes
    3) corner cases (n = 1, n = 0, etc.)
    4) clear
*/

















int main() {    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}


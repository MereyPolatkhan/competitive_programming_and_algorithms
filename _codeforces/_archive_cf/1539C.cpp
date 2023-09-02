#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

void print(vector<ll>& a) {
    cout << " ==> ";
    for (auto &i: a) cout << i << " ";
    cout << "\n\n";
}

void solve() {

    ll n, k, x;
    cin >> n >> k >> x;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(all(a));

    vector<ll> diffs;
    for (int i = 0; i < n - 1; i++) {
        if (a[i + 1] - a[i] <= x) { 
            continue;
        }
        else {
            diffs.pb(a[i + 1] - a[i]);
        }
    }

    // print(diffs);

    if (x > 0) { 
        for (int i = 0; i < diffs.size(); i++) {
            // diffs[i] = ceil(double(diffs[i] * 1.0) / double(x * 1.0)) - 1;
            ll res = diffs[i] / x;
            if (diffs[i] % x > 0) res++;
            diffs[i] = res - 1;
        }
    }
    // print(diffs);

    sort(all(diffs));

    int i = 0;
    while (i < diffs.size() and k >= diffs[i]) { 
        // cout << "i: " << i << " k: " << k << " diffs[i]: " << diffs[i] << "\n";
        k -= diffs[i];
        i++;
    }

    
    cout << diffs.size() - i + 1 << "\n";

}

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

/*  things to check:
    1) long long    
    2) array sizes
    3) corner cases (n = 1, n = 0, etc.)
    4) clear
*/

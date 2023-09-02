#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;

int check(ll w, vector<ll> a, ll c) {
    ll sum = 0;

    for (int i = 0; i < a.size(); i++) {
        sum += (2 * w + a[i]) * (2 * w + a[i]); 
        if (sum > c) break;
    }
    if (sum == c) return 0;
    else if (sum > c) return 1;
    return -1;
}

void solve() {

    int n; ll c;
    cin >> n >> c;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll l = 1, r = 1e9;

    while (l <= r) {
        ll w = l + (r - l) / 2;
        int res = check(w, a, c);
        if (res == 0) {
            cout << w << "\n";
            return;
        }
        else if (res == 1) {
            r = w - 1;
        }
        else {
            l = w + 1;
        }
    }

    cout << r << "\n";
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
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
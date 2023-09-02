#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pii;

bool cmp(pair<pii, ll> a, pair<pii, ll> b) {
    if (a.second == b.second) {
        return a.first.first > b.first.first; 
    }
    return a.second > b.second;
}


void solve() {
    int c, m;
    cin >> c >> m;

    map<ll, ll> mp;

    for (int i = 0; i < c; i++) {
        int x;
        cin >> x;
        mp[x]++;
    }   

    vector<pair<pii, ll>> a;

    for (const auto &x: mp) {
        a.pb({{x.first, x.second}, (ll) x.first * x.second});
    }

    sort(all(a), cmp);  


    // for (auto x: a) {
    //     cout << x.first.first << " " << x.first.second << " " << x.second << "\n";
    // }

    vector<ll> res;
    ll sum = 0;
    int i = 0;
    while (i < a.size() and sum < m) {
        sum += a[i].second;
        res.pb(a[i].first.first);
        i++;
    }   

    if (sum < m) {
        cout << "Impossible\n";
        return;
    }

    sort(all(res));
    for (ll i : res) cout << i << " ";
    cout << "\n";
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


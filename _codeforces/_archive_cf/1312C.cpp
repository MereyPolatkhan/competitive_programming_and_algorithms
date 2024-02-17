#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <cassert>
#include <queue>
#include <bitset>
#include <numeric>
#include <vector>
#include <ctime>
#include <iomanip>
#include <sstream>
 
using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;


vector<ll> get_powers(ll x, ll k) {
    cout << "x: " << x << "   k: " << k << "\n";
    vector<ll> b;
    while (x) {
        b.pb(x % k);
        x /= k;
    }
    cout << "b: "; for (ll x: b) cout << x << " "; cout << "\n\n\n";
    return b;
}

void solve() {

    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(all(a));
    ll start = 0;
    while (start < n and !a[start]) {
        start++;
    }
    

    ll power = 0;
    map<ll, ll> mp;
    for (ll i = start; i < n; i++) {
        vector<ll> degree = get_powers(a[i], k);
        bool flag = false;
        for (int i = 0; i < degree.size(); i++) {
            if (degree[i]) {
                flag = true;
            }
            mp[i] += degree[i];
        }
        if (!flag) {
            cout << "NO\n";
            return;
        }
    }

    for (auto it: mp) {
        if (it.second >= 2) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}



int main() { 
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);


    ll T = 1;
    cin >> T;
    for (ll test = 1; test <= T; test++) {
        solve();
    }

    return 0;
}
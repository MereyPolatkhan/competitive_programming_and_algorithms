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

#include <climits>
#include <stack>
 
using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef unsigned short int usi;



void solve2() {
    int n;
    cin >> n;
    vector<ll> al(n), ar(n), c(n);
    for (int i = 0; i < n; i++) cin >> al[i];
    for (int i = 0; i < n; i++) cin >> ar[i];
    for (int i = 0; i < n; i++) cin >> c[i];


    multiset<ll> l(all(al));
    multiset<ll> r(all(ar));
    
    vector<ll> d;
    for (ll const &left: l) {
        auto right = r.lower_bound(left);
        d.pb(*right - left);
        r.erase(r.find(*right));
    }

    sort(all(d));
    sort(rall(c));

    ll res = 0;

    for (int i = 0; i < n; i++) {
        res += d[i] * c[i];
    }
    cout << res << "\n";
}


void solve() {
    int n;
    cin >> n;
    vector<ll> l(n), r(n), c(n);
    for (int i = 0; i < n; i++) cin >> l[i];
    for (int i = 0; i < n; i++) cin >> r[i];
    for (int i = 0; i < n; i++) cin >> c[i];

    sort(all(l));
    sort(all(r));
    sort(rall(c));

    ll res = 0;
    for (int i = 0; i < n; i++) {
        res +=( r[i] - l[i]) * c[i];
    }

    cout << res << "\n";
}

int main() { 
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);


    int T = 1;
    cin >> T;
    for (int test = 1; test <= T; test++) {
        solve();
    }

    return 0;
}


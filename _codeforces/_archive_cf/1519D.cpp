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
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef unsigned short int usi;

int n;

ll prefix_sum(vector<ll> &p, int r) {
    return p[r];
}
ll suffix_sum(vector<ll> &p, int l) {
    return p[n] - p[l - 1];
}


ll calc(vector<ll> &a, vector<ll> &b, vector<ll> &p, int l, int r) {
    ll cur = 0; 
    ll res = 0;
    

    while (l >= 1 and r <= n) {
        cur += a[r] * b[l] + a[l] * b[r];
        l--, r++;
        ll temp = 0;
        if (l >= 1) 
            temp += prefix_sum(p, l);
        if (r <= n) 
            temp += suffix_sum(p, r);

        res = max(res, cur + temp);
    }
    return res;
}



void solve() {
    cin >> n;

    vector<ll> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) 
        cin >> a[i];
    for (int i = 1; i <= n; i++) 
        cin >> b[i];

    vector<ll> p(n + 1);
    for (int i = 1; i <= n; i++)
        p[i] = a[i] * b[i];

    for (int i = 1; i <= n; i++) {
        p[i] += p[i - 1];
    }

    ll res = p[n];
    for (int i = 1; i <= n; i++) {
        res = max(res, calc(a, b, p, i, i + 1));
        res = max(res, calc(a, b, p, i - 1, i + 1) + a[i] * b[i]);
    }
    cout << res << "\n";
}

int32_t main() { 
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);


    int T = 1;
    // cin >> T;
    for (int test = 1; test <= T; test++) {
        solve();
    }

    return 0;
}

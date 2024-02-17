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

void solve() {
    int m;
    cin >> m;

    map<ll, ll> mp;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        mp[x]++;
    }

    vector<ll> a;
    for (auto &it: mp) {
        a.pb(it.first);
    }

    sort(all(a));


    ll res = 0;
    for (auto &it: mp) {
        res += ((it.second - 1) * it.second) / 2;
    }

    cout << (res + 1LL * mp[1] * mp[2]) << "\n";
}



int main() { 
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // cout << "\nTime elapsed: " << double(clock()) / CLOCKS_PER_SEC << " s.\n";
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int T = 1;
    cin >> T;
    for (int test = 1; test <= T; test++) {
        // cout << "test: #" << test << "\n";
        solve();
    }

    return 0;
}


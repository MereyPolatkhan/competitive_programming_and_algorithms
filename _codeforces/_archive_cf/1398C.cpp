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



void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> a(n + 1);
    for (int i = 0; i < n; i++) {
        a[i + 1] = (int)s[i] - (int)'0';
    }
    for (int i = 1; i <= n; i++) {
        a[i] += a[i - 1];
    }
    // for (int i = 1; i <= n; i++) {
    //     cout << "i: " << i << "\ta[i]: " << a[i] << "\n";
    // }
    map<int, int> mp;
    ll res = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == i)
            res++;
        mp[a[i] - i]++;
    }

    for (auto &it: mp) {
        res += 1LL * (it.second - 1) * it.second / 2; 
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
    cin >> T;
    for (int test = 1; test <= T; test++) {
        solve();
    }

    return 0;
}

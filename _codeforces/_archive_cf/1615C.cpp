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

    string a, b;
    cin >> a >> b;

    map<pii, int> mp;
    for (int i = 0; i < n; i++) {
        mp[{a[i] - '0', b[i] - '0'}]++;
    }

    int res = INT_MAX;
    if (mp[{1, 0}] == mp[{0, 1}]) {
        res = min(res, mp[{1, 0}] * 2);
    }
    if (mp[{1, 1}] - 1 == mp[{0, 0}]) {
        res = min(res, mp[{0, 0}] * 2 + 1);
    }
    if (res == INT_MAX) 
        cout << "-1\n";
    else 
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

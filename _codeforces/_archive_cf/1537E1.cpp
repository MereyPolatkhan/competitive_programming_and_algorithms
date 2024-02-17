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

int n, k;
string func(string &s) {
    string res = s;
    while (res.size() < k) {
        res += s;
    }
    while (res.size() > k) {
        res.pop_back();
    }
    return res;
}

void solve() {
    cin >> n >> k;

    string s;
    cin >> s;

    string res(k, 'z');
    for (int len = 1; len <= n; len++) {
        string pref = s.substr(0, len);
        res = min(func(pref), res);
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

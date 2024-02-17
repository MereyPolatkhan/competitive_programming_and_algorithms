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
    int n, m;
    cin >> n >> m;

    vector<int> a(n + 1);
    int index = 1e9;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] != i)
            index = i;
    }


    double res = 1;
    while (m--) {
        int j; double p;
        cin >> j >> p;
        if (j >= index) 
            res *= (1 - p);
    }

    if (index == 1e9)
        res = 1;
    else 
        res = 1 - res;
    cout << fixed << setprecision(10) << res << "\n";
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

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

    set<int> a;
    for (int i = 1; i <= n; i++) {
        if (gcd(i, n) == 1)
            a.insert(i);
    }

    ll p = 1;
    for (int x: a) {
        p *= x;
        p %= n;
    }

    if (p % n > 1) {
        a.erase(p % n);
    }

    cout << a.size() << "\n";
    for (int x: a) {
        cout << x << " ";
    }
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
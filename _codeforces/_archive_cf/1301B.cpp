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


int func(vector<int> a, int x) {
    for (int &y: a) {
        if (y == -1)
            y = x; 
    }

    int m = 0;
    for (int i = 0; i < a.size() - 1; i++) {
        m = max(m, abs(a[i] - a[i + 1]));
    }
    return m;
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &x: a) 
        cin >> x;

    int min = 1e9, max = -1e9;
    for (int i = 0; i < n; i++) {
        int x = a[i];
        if (x == -1)
            continue;
        if (i >= 1 and a[i - 1] == -1 or i + 1 < n and a[i + 1] == -1)
            min = ::min(min, x), max = ::max(max, x);
    }


    int k = (min + max) / 2;
    int m = func(a, k);

    // if ((min + max) % 2) {
    //     int k2 = k + 1;
    //     int m2 = func(a, k2);

    //     if (m > m2) {
    //         m = m2, k = k2;
    //     }
    // }

    cout << m << " " << k << "\n";
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

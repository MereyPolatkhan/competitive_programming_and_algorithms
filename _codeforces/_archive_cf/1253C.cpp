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

    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(all(a));


    ll sum = 0;
    int k = 1;
    for (int i = n; i >= 1; i -= m) {
        for (int j = i; j >= max(i - m + 1, 1); j--) {
            sum += a[j] * k;
        }
        k++;
    }

    for (int j = 1; j <= m; j++) {
        for (int i = j; i <= n; i += m) {
            if (i + m <= n)
                a[i + m] += a[i]; 
        }
    }


    vector<ll> res;
    for (int i = n; i >= 1; i--) {
        res.pb(sum);
        sum -= a[i];
    }

    reverse(all(res));
    for (auto x: res) 
        cout << x << " ";
    cout << "\n";
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

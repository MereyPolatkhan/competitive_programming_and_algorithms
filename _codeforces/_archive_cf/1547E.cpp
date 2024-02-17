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

int const inf = 1e9 + 3e5 + 1;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> c(k), t(k);
    for (int i = 0; i < k; i++) {
        cin >> c[i];
    }
    for (int i = 0; i < k; i++) {
        cin >> t[i];
    }

    vector<int> a(n + 1, inf);
    for (int i = 0; i < k; i++) {
        a[c[i]] = t[i];
    }

    vector<int> prefix = a, suffix = a;

    for (int i = 2; i <= n; i++) {
        prefix[i] = min(prefix[i], prefix[i - 1] + 1);
    }
    for (int i = n - 1; i >= 1; i--) {
        suffix[i] = min(suffix[i], suffix[i + 1] + 1);
    }

    for (int i = 1; i <= n; i++) {
        cout << min(prefix[i], suffix[i]) << " ";
    }
    cout << "\n";
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
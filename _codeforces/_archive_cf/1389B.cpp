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
    int n, k, z;
    cin >> n >> k >> z;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) 
        cin >> a[i];

    vector<int> pf = a, mx = a;
    
    for (int i = 1; i <= n; i++) {
        pf[i] += pf[i - 1];
    }   

    mx[1] = a[1] + a[2];
    for (int i = 2; i <= n; i++) {
        mx[i] = max(mx[i - 1], a[i - 1] + a[i]);
    }
    
    // for (int i = 1; i <= n; i++) cout << pf[i] << " "; cout << "\n";
    // for (int i = 1; i <= n; i++) cout << mx[i] << " "; cout << "\n";

    int res = 0;
    for (int t = 0; t <= z; t++) {
        int j = k - 2 * t + 1;
        if (j >= 1)
            res = max(res, pf[j] + mx[j + 1] * t);
        // cout << "j: " << j << "\tt: " << t << "\n";
    }   
    cout << res << "\n";

    cout << "\n\n\n";
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

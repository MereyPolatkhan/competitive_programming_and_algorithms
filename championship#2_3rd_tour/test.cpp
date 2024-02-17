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

    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (n == 1) {
        cout << 1 << "\n";
        return;
    }

    sort(all(a));


    int res = 1;
    int i = 0;
    while (i + 1 < n) {
        int d = a[i + 1] - a[i];
        int j = i;
        while (j + 1 < n and a[j + 1] - a[j] == d) 
            j++;

        int cnt = j - i + 1; 

        // cout << i << " " << j << " = " << cnt << " d: " << d << "\n";
        if (d>0)
            res = max(res, 1 + min((n - 1) / d, cnt - 1));

        i = j;    
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

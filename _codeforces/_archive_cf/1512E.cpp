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


ll sum(int l, int r) {
    return 1LL * (r - l + 1) * (l + r) / 2;
}

void solve() {
    int n, l, r, s;
    cin >> n >> l >> r >> s;

    int k = r - l + 1;

    vector<int> res;
    for (int i = n; i >= 1; i--) {
        if (sum(i - k + 1, i) >= s and s - i >= sum(1, k - 1)) {
            res.pb(i);
            k--;
            s -= i;
        }
    }

    if (s) {
        cout << -1 << "\n";
    }
    else {
        vector<int> a(n + 1);
        set<int> st;
        for (int i = 1; i <= n; i++) {
            st.insert(i);
        }
        
        for (int i = l, j = 0; i <= r; i++, j++) {
            a[i] = res[j];
            st.erase(res[j]);
        }

        for (int i = 1; i <= n; i++) {
            if (a[i])
                continue;
            
            a[i] = *st.begin();
            st.erase(st.begin());
        }

        for (int i = 1; i <= n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
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

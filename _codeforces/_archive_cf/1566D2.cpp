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

bool cmp(const pii &a, const pii &b) {
    if (a.first == b.first) {
        return a.second > b.second;
    }   
    return a.first < b.first;
}

int n, m, sz;

ll func(vector<pii> &b) {
    sort(all(b), &cmp);

    ll res = 0;
    multiset<int> st;

    for (pii &x: b) {
        if (st.size()) {
            auto it = st.lower_bound(x.second);
            res += distance(st.begin(), it);
        }
        st.insert(x.second);
    }

    return res;
}

void solve() {
    cin >> n >> m;

    sz = n * m;
    vector<pii> a(sz + 1);
    for (int i = 1; i <= sz; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(all(a));

    ll res = 0;
    for (int i = 1; i <= sz; i += m) { 
        vector<pii> b(a.begin() + i, a.begin() + i + m);
        res += func(b);
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
    cin >> T;
    for (int test = 1; test <= T; test++) {
        solve();
    }

    return 0;
}

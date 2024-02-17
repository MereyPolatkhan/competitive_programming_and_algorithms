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

// sort(all(a));
// sort(rall(b));

// cout << "\n";
// for (int x: a) cout << x << " "; cout << "\n";
// for (int x: b) cout << x << " "; cout << "\n";


int front(multiset<int> &st) {
    return *st.begin();
}

int back(multiset<int> &st) {
    return *st.rbegin();
}


void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    multiset<int> st1(all(a));
    multiset<int> st2(all(b));

    // for (int x: st1) cout << x << " "; cout << "\n";
    // for (int x: st2) cout << x << " "; cout << "\n";
    // cout << "\n\n\n";

    ll d = 0;
    while (st1.size()) {
        if (back(st1) - front(st2) > back(st2) - front(st1)) {
            d += back(st1) - front(st2);
            st1.erase(st1.find(back(st1)));
            st2.erase(st2.find(front(st2)));
        }
        else {
            d += back(st2) - front(st1);
            st2.erase(st2.find(back(st2)));
            st1.erase(st1.find(front(st1)));
        }
    }
    cout << d << "\n";
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

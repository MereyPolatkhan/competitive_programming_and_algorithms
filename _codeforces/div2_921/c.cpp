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

bool check(set<char> &st, int k) {
    for (char c = 'a'; c < 'a' + k; c++) {
        if (st.count(c) == 0) {
            return false;
        }
    }
    return true;
}

void solve() {
    int n, k, m;
    cin >> n >> k >> m;
    string s;
    cin >> s;

    set<char> st;
    string res = "";
    int cnt = 0;
    for (char c: s) {
        st.insert(c);
        if (check(st, k)) {
            cnt++;
            res += c;
            st.clear();
        }
    }

    if (cnt >= n) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
        for (char c = 'a'; c < 'a' + k; c++) {
            if (st.count(c) == 0) {
                res += c;
            }
        }
        while (res.size() < n) {
            res += res;
        }
        cout << res.substr(0, n) << "\n";
    }

    cout << "\n\n";
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

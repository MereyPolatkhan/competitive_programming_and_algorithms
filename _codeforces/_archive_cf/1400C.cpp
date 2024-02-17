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
    string s;
    cin >> s;

    int x;  
    cin >> x;

    string w(s.size(), '1');

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') {
            if (i - x >= 0) {
                w[i - x] = '0';
            }
            if (i + x < s.size()) {
                w[i + x] = '0';
            }
        }
    }
    

    string t(w.size(), '0');
    for (int i = 0; i < w.size(); i++) {
        if (i - x >= 0 and w[i - x] == '1' or i + x < w.size() and w[i + x] == '1') {
            t[i] = '1';
        }
        else {
            t[i] = '0';
        }
    }

    if (s == t) {
        cout << w << "\n";
    }
    else {
        cout << -1 << "\n";
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

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

int func(string &s, int l, int r, char c = 'a') {
    if (l == r) {
        // cout << "l : " << l << "\t r : " << r << "\t return: ";
        // cout << (s[l] != c) << "\t c: " << c << "\n";
        return (s[l] != c);
    }
    int mid = (l + r) / 2;
    int cntl = 0, cntr = 0;
    for (int i = l; i <= r; i++) {
        if (s[i] != c)
            continue;

        if (i <= mid)
            cntl++;
        else 
            cntr++;
    }
    // cout << "c: " << c << "\n";
    // cout << "l, r: " << l << ", " << r << "\n";
    // cout << "cntl, cntr: " << cntl << ", " << cntr << "\n\n";

    int left_val = ((r - l + 1) / 2 - cntl) + func(s, mid + 1, r, c + 1);
    // cout << "c: " << c << "\tleft: " << left_val << "\n";
    int right_val = ((r - l + 1) / 2 - cntr) + func(s, l, mid, c + 1);
    // cout << "c: " << c << "\tright: " << right_val << "\n";

    return min(left_val, right_val);
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    cout << func(s, 0, n - 1) << "\n";
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

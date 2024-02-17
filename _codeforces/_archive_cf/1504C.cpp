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
    string s;
    cin >> s;

    int cnt1 = count(all(s), '1');

    if (s[0] == '0' or s[n - 1] == '0' or cnt1 % 2) {
        cout << "NO\n";
        return;
    }

    vector<char> a(n), b(n);
    for (int i = 0, lcnt1 = 0, lcnt0 = 0; i < n; i++) {
        if (s[i] == '1') {
            if (lcnt1 < cnt1 / 2) {
                a[i] = b[i] = '(';
            }
            else {
                a[i] = b[i] = ')';
            }
            lcnt1++;
        }
        else {
            if (lcnt0 % 2) {
                a[i] = '(';
                b[i] = ')';
            }
            else {
                a[i] = ')';
                b[i] = '(';
            }
            lcnt0++;
        }
    }

    cout << "YES\n";
    for (char c: a) cout << c << ""; cout << "\n";
    for (char c: b) cout << c << ""; cout << "\n";
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

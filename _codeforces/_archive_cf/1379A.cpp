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


int n;
const string w = "abacaba";
string s;

bool check_cnt(string &s) {
    int cnt = 0;
    for (int i = 0; i < s.size() - w.size() + 1; i++) {
        if (s.substr(i, w.size()) == w) 
            cnt++;
    }
    return cnt == 1;
}

bool check(int l, int r) {
    for (int i = l; i <= r; i++) {
        if (s[i] != '?' and s[i] != w[i - l]) 
            return false;
    }
    return true;
}

void solve() {
    cin >> n;
    cin >> s;

    for (int l = 0, r = w.size() - 1; r < n; l++, r++) {
        if (check(l, r)) {
            string temp = s.substr(0, l) + w + s.substr(r + 1);
            if (check_cnt(temp)) {
                replace(all(temp), '?', 'z');
                cout << "Yes\n" << temp << "\n";
                return;
            }
        }
    }

    cout << "NO\n";
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

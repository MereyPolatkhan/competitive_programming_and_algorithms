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
#include <stack>


using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef unsigned short int usi;

int it = 0;

void solve() {
    ++it;
    int n;
    cin >> n;

    string s;
    cin >> s;
    if (it == 819) {
        cout << s;
    }
    int res = 1e9;
    int l = 0;
    map<char, int> mp;

    for (int r = 0; r < n; r++) {
        mp[s[r]]++;
        while (s[l] != 'a') {
            mp[s[l]]--;
            l++;
        }

        if (r - l + 1 >= 2) {
            if (mp['a'] > mp['b'] and mp['a'] > mp['c']) {
                while (l < r and mp['a'] >= 2) {
                    res = min(res, r - l + 1);
                    mp[s[l]]--;
                    l++;
                }
            }
            else if (mp['b'] > mp['a'] + 1 or mp['c'] > mp['a'] + 1) {
                while (l < r) {
                    mp[s[l]]--;
                    l++;
                }
            }
        }
    }
    if (res == 1e9) 
        cout << -1 << "\n";
    else
        cout << res << "\n";
}

int main() { 
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
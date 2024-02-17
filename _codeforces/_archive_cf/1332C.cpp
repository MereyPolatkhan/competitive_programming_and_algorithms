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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int i = 0;
    int j = k - 1;

    int res = 0;
    while (i <= j) {
        map<char, int> mp;
        for (int index = i; index < n; index += k) {
            mp[s[index]]++;
        }
        if (i < j)
            for (int index = j; index < n; index += k) {
                mp[s[index]]++;
            }
        int mx = 0;
        int all = 0;
        for (auto it: mp)
            mx = max(mx, it.second), all += it.second;

        res += all - mx;
        i++, j--;
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

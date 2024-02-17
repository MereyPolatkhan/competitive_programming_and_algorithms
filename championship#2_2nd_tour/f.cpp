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

#include <climits>
#include <stack>
 
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

    map<int, map<int, int>> mp;
    ll res = 0;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        mp[x][y]++;
    }


    for (auto it: mp) {
        // cout << it.first << ": ";
        vector<pii> temp;
        ll all = 0;
        for (auto j : it.second) {
            // cout << "\t"<< j.first << ": " << j.second << "\n";
            int eq = abs(j.first - j.second);
            int del = j.second;
            all += del;
            temp.pb({eq, del});
        }

        ll sum = INT_MAX;
        for (auto ed: temp) {
            int eq = ed.first;
            int del = ed.second;
            sum = min(sum, min(all, eq + (all - del)));
        }

        // cout << it.first << " => " << sum << "\n";
        res += sum;
        // cout << "\n\n";
    }

    cout << res << "\n";
}


int main() { 
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);


    int T = 1;
    // cin >> T;
    for (int test = 1; test <= T; test++) {
        solve();
    }

    return 0;
}


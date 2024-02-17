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
typedef pair<double, double> pii;
typedef unsigned short int usi;



pii get_center(pii q, pii w) {
    return {(q.first + w.first) / 2, (q.second + w.second) / 2};
}

void solve() {
    int n;
    cin >> n;

    vector<pii> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    map<pii, int> mp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mp[get_center(a[i], a[j])]++;
        }
    }

    int cnt = 0;
    for (auto it: mp) {
        cnt = max(cnt, it.second);
    }

    cout << n - cnt << "\n";
}


int main() { 
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}


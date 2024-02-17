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

    vector<pii> a(n + 1);
    for (int i = 1; i <= n; i++) 
        cin >> a[i].first >> a[i].second;


    int l = 0, r = n + 1;

    while (l + 1 < r) {
        int m = (l + r) / 2;
        int back = 0, front = m - 1, cnt = 0;

        for (int i = 1; i <= n; i++) {
            if (front <= a[i].first and back <= a[i].second) {
                front--, back++, cnt++;
            }
        }

        if (cnt >= m) {
            l = m;
        }
        else {
            r = m;
        }
    }

    
    cout << l << "\n";
    
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

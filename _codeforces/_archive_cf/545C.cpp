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

    vector<pii> a(n);
    for (int i = 0; i < n; i++) 
        cin >> a[i].first >> a[i].second;

    a.pb({INT_MAX, INT_MAX});

    int cnt = 1, last = a[0].first;

    for (int i = 1; i < n; i++) {   
        if (last < a[i].first - a[i].second) {
            last = a[i].first;
            cnt++;
        }
        else if (a[i].first + a[i].second < a[i + 1].first) {
            last = a[i].first + a[i].second;
            cnt++;
        }
        else {
            last = a[i].first;
        }
    }

    cout << cnt << "\n";
    
}

int32_t main() { 
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

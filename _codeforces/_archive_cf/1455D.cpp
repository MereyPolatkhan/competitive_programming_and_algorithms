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
    int n, x;
    cin >> n >> x;

    vector<int> a(n + 1, -1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int i = 1, cnt = 0;
    while (i <= n) {
        while (i <= n and a[i - 1] <= a[i]) {
            i++;
        }
        if (i > n) {
            break;
        }
        while (a[i - 1] > x) {
            i--;
        }
        if (a[i] > x) {
            swap(a[i], x);
            cnt++;
        }
        else {
            cout << -1 << "\n";
            return;
        }
        i = 1;
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
    cin >> T;
    for (int test = 1; test <= T; test++) {
        solve();
    }

    return 0;
}

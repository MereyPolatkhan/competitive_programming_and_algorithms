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
    int n, t;
    cin >> n >> t;

    int k;
    cin >> k;

    int l = 1, r = n;
    int sum, mid, cnt0; 
    for (int i = 1; i <= 20; i++) {
        mid = (l + r) / 2;
        cout << "? " << l << " " << mid << "\n";
        cout.flush();
        cin >> sum;
        cnt0 = mid - l + 1 - sum;

        if (cnt0 < k) {
            k -= cnt0;
            l = mid + 1;
        }
        else {
            r = mid;
        }

        if (l == r) {
            cout << "! " << l;
            exit(0);
            return;
        }
    }
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

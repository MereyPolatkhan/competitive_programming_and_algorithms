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
#define int long long


bool check(int y, vector<int> cnt) {
    for (int it = 0; it < 31; it++) {
        for (int i = 29; i >= 0; i--) {
            if (y < pow(2, i) or cnt[i] == 0)     
                continue;

            int deg = 1;
            int temp = pow(2, i);
            int c = 0;
            while (deg * temp <= y) {
                deg *= temp;
                c++;
            }
        
            c = min(c, cnt[i]);
            cnt[i] -= c;
            y -= (pow(2, i) * c);
        }
    }

    return y == 0;
}


void solve() {
    int q;
    cin >> q;   

    vector<int> cnt(30, 0);
    while (q--) {
        int w;
        cin >> w;
        if (w == 1) {
            // add;
            int x;
            cin >> x;
            cnt[x]++;
        }
        else if (w == 2) {
            // get;
            int y;
            cin >> y;

            if (check(y, cnt)) {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
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


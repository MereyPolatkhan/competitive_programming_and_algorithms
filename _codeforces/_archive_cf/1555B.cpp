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



int func(int x1, int x2, int w, int W) {
    int res = INT_MAX;
    if (x2 - x1 + w <= W) {
        res = min(res, max(0, x2 - (W - w)));
        res = min(res, max(0, w - x1));
    }
    return res;
}

void solve() {
    int W, H;
    int x1, y1, x2, y2;
    int w, h;
    
    cin >> W >> H;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> w >> h;


    int res = min(func(x1, x2, w, W), func(y1, y2, h, H));
    
    if (res == INT_MAX) {
        cout << -1 << "\n";
    }
    else {
        cout << setprecision(9) << fixed << (double) res << "\n";
    }
}



int main() { 
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}


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

struct lrc {
    ll l = 1e9 + 7, r = -1, cost = 1e9 + 7;
};


void solve() {
    int n;
    cin >> n;

    vector<lrc> a(n);
    lrc L, R, D;

    for (int i = 0; i < n; i++) {
        ll l, r, cost;
        cin >> l >> r >> cost;

        if (l == L.l)
            L.cost = min(L.cost, cost);
        else if (l < L.l) 
            L = {l, r, cost};
        
        if (r == R.r)
            R.cost = min(R.cost, cost);
        else if (R.r < r) 
            R = {l, r, cost};

        
        if (r - l == D.r - D.l) 
            D.cost = min(D.cost, cost);
        else if (r - l > D.r - D.l)
            D = {l, r, cost};

        
        if (D.r - D.l == R.r - L.l) 
            cout << min(D.cost, R.cost + L.cost) << "\n";
        else 
            cout << R.cost + L.cost << "\n";
    }


}



int main() { 
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
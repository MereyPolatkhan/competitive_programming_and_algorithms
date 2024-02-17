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
typedef long double ld;

typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef unsigned short int usi;
typedef pair<int, ll> pill;


struct element {
    int x, y, a;
};

struct line {
    ll m, c;
    ll eval(ll x) {
        return m * x + c;
    }
    ld intersectX(line l) {
        return (ld) (c - l.c) / (l.m - m);
    }
};

int const N = 2e5;
ll dp[N];
bool cmp(element a, element b) {
    if (a.x == b.x) 
        return a.y < b.y;

    return a.x < b.y;
}
void solve() {
    int n;
    cin >> n;

    vector<element> a(n);
    for (int i = 0; i < n; i++) 
        cin >> a[i].x >> a[i].y >> a[i].a;

    sort(all(a), cmp);


    deque<line> dq;

    dq.push_front({0, 0});
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        while (dq.size() >= 2 and dq.back().eval(a[i].y) <= dq[dq.size() - 2].eval(a[i].y)) 
            dq.pop_back();

        dp[i] = dq.back().eval(a[i].y) + a[i].x * a[i].y - a[i].a;

        ans = max(ans, dp[i]);
        
        line cur = {-a[i].x, dp[i]};

        while (dq.size() >= 2 and cur.intersectX(dq[0]) >= dq[0].intersectX(dq[1])) {
            dq.pop_front();
        }

        dq.push_front(cur);
    }
    cout << ans << "\n";
}




int main() { 
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}


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


#define X first
#define Y second


struct Line {
    double ax, ay, bx, by;
    double b, k;

    Line(double ax, double ay, double bx, double by) {
        this->ax = ax;
        this->ay = ay;
        this->bx = bx;
        this->by = by;

        this->b = get_b();
        this->k = get_k();
    }

    double get_b() {
        return ay - get_k() * ax;
    }
    
    double get_k() {
        if (abs(bx - ax) < 1e-9) {
            return 0;
        }
        return (by - ay) / (bx - ax);    
    }

    bool intersects(Line l1, Line l2) {
        double k1 = l1.k;
        double k2 = l2.k;
        double b1 = l1.b;
        double b2 = l2.b;

        if (abs(k1 - k2) < 1e-9) { 
            return false;
        }

        double x_intersect = (b2 - b1) / (k1 - k2);
        double y_intersect = k1 * x_intersect + b1;

        if (x_intersect >= min(l1.ax, l1.bx) && x_intersect <= max(l1.ax, l1.bx) &&
            x_intersect >= min(l2.ax, l2.bx) && x_intersect <= max(l2.ax, l2.bx) &&
            y_intersect >= min(l1.ay, l1.by) && y_intersect <= max(l1.ay, l1.by) &&
            y_intersect >= min(l2.ay, l2.by) && y_intersect <= max(l2.ay, l2.by)) {
            return true;
        }

        return false;
    }
};




void solve() {
    vector<pair<double, double>> a(4);
    for (int i = 0; i < 4; i++) {
        cin >> a[i].first >> a[i].second;
    }

    Line l1(a[0].X, a[0].Y, a[1].X, a[1].Y);
    Line l2(a[2].X, a[2].Y, a[3].X, a[3].Y);

  
    if (l1.intersects(l1, l2)) 
        cout << "NO\n";
    else    
        cout << "YES\n";
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

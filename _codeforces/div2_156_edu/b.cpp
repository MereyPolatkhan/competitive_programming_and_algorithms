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

double px, py, ax, ay, bx, by;

bool checkA(double r) {
    double c1 = abs(px - ax);
    double c2 = abs(py - ay);

    double hyp = sqrt(c1 * c1 + c2 * c2);
    double hyp0 = sqrt(ax * ax + ay * ay);

    return hyp <= r and hyp0 <= r;
}


bool checkB(double r) {
    double c1 = abs(px - bx);
    double c2 = abs(py - by);

    double hyp = sqrt(c1 * c1 + c2 * c2);
    double hyp0 = sqrt(bx * bx + by * by);

    return hyp <= r and hyp0 <= r;
}



bool checkAB(double r) {
    double ab = sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by));
    if (ab > 2 * r) {
        return false;
    } 

    double c1 = abs(ax - px);
    double c2 = abs(ay - py);

    if (sqrt(c1 * c1 + c2 * c2) > r) {
        return false;
    }

    if (sqrt(bx * bx + by * by) > r) {
        return false;
    }

    return true;
}

bool checkBA(double r) {
    double ab = sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by));
    if (ab > 2 * r) {
        return false;
    } 

    double c1 = abs(bx - px);
    double c2 = abs(by - py);

    if (sqrt(c1 * c1 + c2 * c2) > r) {
        return false;
    }

    if (sqrt(ax * ax + ay * ay) > r) {
        return false;
    }

    return true;   
}

bool check(double r) {
    return checkAB(r) or checkBA(r) or checkA(r) or checkB(r);
}



void solve() {
    cin >> px >> py;
    cin >> ax >> ay;
    cin >> bx >> by;


    double l = 0, r = 1e9;

    for (int i = 0; i < 200; i++) {
        double mid = (l + r) / 2.0;
        if (check(mid)) {
            r = mid;
        }    
        else {
            l = mid;
        }
    }
    cout << fixed << setprecision(10) << r << "\n";
}




int main() { 
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}


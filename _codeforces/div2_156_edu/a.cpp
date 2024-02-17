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
    ll n;
    cin >> n;

    int a = 1;
    int b = 2;
    int c = n - a - b;


    while (a > 0 and b > 0 and c > 0 and c % 3 == 0) {
        b++;
        c--;
        if (b % 3 == 0 || c % 3 == 0) {
            b++;
            c--;
        }
    }


    if (c <= 0 || c == a || c == b) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    cout << a << " " << b << " " << c << "\n";
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


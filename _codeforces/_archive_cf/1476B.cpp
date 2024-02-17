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
#include <stack>


using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef unsigned short int usi;


    
void solve() {
    int n, k;
    cin >> n >> k;
    vector<double> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    double d = a[0];
    double res = 0;

    for (int i = 1; i < n; i++) {
        if (a[i] * 100 > d * k) {
            double delta = ceil(100.0 * a[i] / k);
            res += (delta - d); 
            d = delta;
        }
        d += a[i];
    }

    cout << (ll)res << "\n";

}


int main() { 
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }


    return 0;
}



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

// n <= 1e3, a[i] <= |4e3|
int sum(vector<int> &a) {
    int res = 0;
    for (int x: a) {
        res += x;
    }
    return res;
}
void solve() {
    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    for (int &x: a) 
        cin >> x;

    
    if (count(all(a), x) == n) {
        cout << 0 << "\n";
        return;
    }

    if (count(all(a), x)) {
        cout << 1 << "\n";
        return;
    }

    if (sum(a) % n == 0 and sum(a) / n == x) {
        cout << 1 << "\n";
        return;
    }

    cout << 2 << "\n";

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

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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> b(n);
    int j = 0;
    if (n % 2) {        
        if (a[0] + a[1]) {
            b[0] = b[1] = -a[2];
            b[2] = a[0] + a[1];
        }
        else if (a[0] + a[2]) {
            b[0] = b[2] = -a[1];
            b[1] = a[0] + a[2];
        }
        else if (a[1] + a[2]) {
            b[1] = b[2] = -a[0];
            b[0] = a[1] + a[2];
        }
        j = 3;
    }
    for (int i = j; i < n; i += 2) {
        b[i] = a[i + 1];
        b[i + 1] = -1 * a[i];
    }

    for (int x: b) 
        cout << x << " ";
    cout << "\n";
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

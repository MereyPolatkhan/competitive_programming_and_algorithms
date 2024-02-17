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

    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<int> b(n + 1, -1);
    vector<bool> used(1000000, false);
    used[a[n]] = true;
    for (int i = 1; i <= n; i++) {
        if (a[i - 1] != a[i]) {
            b[i] = a[i - 1];
            used[b[i]] = true;
        }
    }


    int val = 0;
    for (int i = 1; i <= n; i++) {
        if (b[i] != -1)
            continue;
        while (used[val])
            val++;
        
        b[i] = val;
        used[val] = true;
    }
    for (int i = 1; i <= n; i++) 
        cout << b[i] << " ";
    cout << "\n";
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

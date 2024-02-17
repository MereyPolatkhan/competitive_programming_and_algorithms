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
    for (int i = 0; i < n; i++) 
        cin >> a[i];

    int res = a[0];

    int i = 1;
    while (i < n) {
        if (!a[i]) {
            i++;
        }
        else {
            int j = i;
            while (j + 1 < n and a[j + 1])
                j++;
            
            res += (j - i + 1) / 3;
            i = j + 1;
        }
    }
    cout << res << "\n";
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
        if (test == 0) {
            int n;
            cin >> n;
            for (int i = 0; i < n; i++) {
                int x; cin >> x; cout << x;
            }
            cout << ";";
            return 0;
        }
        solve();
    }

    return 0;
}

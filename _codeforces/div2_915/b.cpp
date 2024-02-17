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

#include <climits>
#include <stack>
 
using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef unsigned short int usi;


int const N = 1e5 + 8;
vector<int> g[N];
vector<bool> used(N, false);


void solve() {

    int n;
    cin >> n;

    // clear g[];
    for (int i = 1; i <= n; i++) {
        g[i].clear();
        used[i] = false;
    }


    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (g[i].size() == 1) {
            cnt++;
        }
    }

    cout << (cnt + 1) / 2 << "\n";

    // for (int i = 1; i <= n; i++) {
    //     cout << i << " --> ";
    //     for (int j : g[i]) {
    //         cout << j << " ";
    //     }
    //     cout << "\n";
    // }

    // cout << "\n";
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


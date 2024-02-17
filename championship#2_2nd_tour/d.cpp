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


int const MAXN = 1e3;
int a[MAXN + 7][MAXN + 7];
// int used[MAXN + 7][MAXN + 7];
int n, m;
int res = 0;


void dfs(int i, int j, int len, int prevdelta) {
    if (res > len)
        return;
    if (a[i - 1][j] - a[i][j] > prevdelta) {
        dfs(i - 1, j, len + 1, a[i - 1][j] - a[i][j]);
    }

    if (a[i + 1][j] - a[i][j] > prevdelta) {
        dfs(i + 1, j, len + 1, a[i + 1][j] - a[i][j]);

    }


    if (a[i][j - 1] - a[i][j] > prevdelta) {
        dfs(i, j - 1, len + 1, a[i][j - 1] - a[i][j]);


    }

    if (a[i][j + 1] - a[i][j] > prevdelta) {
        dfs(i, j + 1, len + 1, a[i][j + 1] - a[i][j]);

    }

    res = max(res, len);
    return;
}

void dfs(int i, int j) {
    dfs(i, j, 1, 0);
}

void solve() {
    cin >> n >> m;
        

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }



    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dfs(i, j);
        }   
    }



    cout << res << "\n";
}


int main() { 
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


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

char a[1000][1000];
int used[1000][1000];
int n, m;
int used2[1000][1000];


bool check(int i, int j) {
    if (i == 0 or j == 0 or 
        i == n + 1 or j == m + 1 or 
        used[i][j] or 
        a[i][j] == '.') {
        return false;
    }
    return true;
}

void dfs(int i, int j, int &cnt, int &l) {
    if (used2[i][j] == 0 and a[i][j + 1] == '*' and a[i + 1][j] == '*') {
        used2[i][j]++;
        l++;
    }
    if (used2[i][j] == 0 and a[i - 1][j] == '*' and a[i][j + 1] == '*') {
        used2[i][j]++;
        l++;
    }
    if (used2[i][j] == 0 and a[i][j - 1] == '*' and a[i - 1][j] == '*') {
        used2[i][j]++;
        l++;
    }
    if (used2[i][j] == 0 and a[i + 1][j] == '*' and a[i][j - 1] == '*') {
        used2[i][j]++;
        l++;
    }



    if (check(i - 1, j - 1)) {
        used[i - 1][j - 1]++;
        dfs(i - 1, j - 1, ++cnt, l);
    }
    if (check(i - 1, j + 1)) {
        used[i - 1][j + 1]++;
        dfs(i - 1, j + 1, ++cnt, l);
    }
    if (check(i + 1, j - 1)) {
        used[i + 1][j - 1]++;
        dfs(i + 1, j - 1, ++cnt, l);
    }
    if (check(i + 1, j + 1)) {
        used[i + 1][j + 1]++;
        dfs(i + 1, j + 1, ++cnt, l);
    }
    if (check(i - 1, j)) {
        used[i - 1][j]++;
        dfs(i - 1, j, ++cnt, l);
    }
    if (check(i, j - 1)) {
        used[i][j - 1]++;
        dfs(i, j - 1, ++cnt, l);
    }
    if (check(i + 1, j)) {
        used[i + 1][j]++;
        dfs(i + 1, j, ++cnt, l);
    }
    if (check(i, j + 1)) {
        used[i][j + 1]++;
        dfs(i, j + 1, ++cnt, l);
    }

    
}


void solve() {
    cin >> n >> m;


    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            a[i][j] = '.';
            used[i][j] = 0;
            used2[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    int cnt = 0;
    int l = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == '*' and used[i][j] == 0) {
                cnt = 0;
                l = 0;
                dfs(i, j, cnt, l);

                if (cnt == 3 and l == 1) {
                    continue;
                }
                else {
                    // cout << "i: " << i << " j: " << j << " cnt: " << cnt << "  l: " << l << "\n";
                    cout << "NO\n";
                    return;
                    
                }
            }
        }
    }
    cout << "YES\n";
}
/*  things to check:
    !  freopen
    !  clear & resize SET, MAP, VECTOR, etc. or write in local functions
    1) long long    
    2) array sizes
    3) corner cases (n = 1, n = 0, etc.)
*/

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


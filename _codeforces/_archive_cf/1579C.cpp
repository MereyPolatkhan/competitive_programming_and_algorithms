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


int n, m, k;

bool isCenter(int i, int j, vector<string> &a) {
    int cnt = 0;
    while (i >= 0 and j - cnt >= 0 and j + cnt < m) {
        if (a[i][j - cnt] == '*' and a[i][j + cnt] == '*') {
            cnt++;
            i--;
        }
        else {
            break;
        }
    }
    return --cnt >= k;
}

void draw(int i, int j, vector<vector<int>> &used, vector<string> &a) {
    int cnt = 0;
    while (i >= 0 and j - cnt >= 0 and j + cnt < m) {
        if (a[i][j - cnt] == '*' and a[i][j + cnt] == '*') {
            used[i][j - cnt] = used[i][j + cnt] = true;
            cnt++;
            i--;
        }
        else 
            return;
    }
}

void solve() {

    cin >> n >> m >> k;

    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<int>> used(n, vector<int> (m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '*' and isCenter(i, j, a)) {
                draw(i, j, used, a);
            }
        }
    }


    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << used[i][j] << " ";
    //     }
    //     cout << "\n";
    // }


    

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '*' and used[i][j] == false) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
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

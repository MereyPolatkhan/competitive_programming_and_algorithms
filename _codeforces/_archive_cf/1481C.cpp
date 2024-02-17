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
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), b(n + 1), c(m + 1);

    for (int i = 1; i <= n; i++) 
        cin >> a[i];

    for (int i = 1; i <= n; i++) 
        cin >> b[i];

    for (int i = 1; i <= m; i++) 
        cin >> c[i];


    map<int, deque<int>> mp;

    for (int i = 1; i <= n; i++) {
        if (a[i] != b[i]) {
            mp[b[i]].push_front(i);
        }
        else {
            mp[b[i]].push_back(i);
        }
    }

    int pivot_fence = -1;
    vector<int> res(m + 1);
    for (int i = m; i >= 1; i--) {
        int color = c[i];
        if (mp[color].size() == 0) {
            if (pivot_fence == -1) {
                cout << "NO\n";
                return;
            }
            else {  
                res[i] = pivot_fence;
            }   
            continue;
        }
        int fence = mp[color].front(); mp[color].pop_front();
        res[i] = fence;
        if (pivot_fence == -1) {
            pivot_fence = fence;
        }
    }
    for (int i = 1; i <= m; i++) {
        a[res[i]] = c[i];
    }

    for (int i = 1; i <= n; i++) {
        if (a[i] != b[i]) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
    for (int i = 1; i <= m; i++) {
        cout << res[i] << " ";
    }
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

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

    string a, b;
    cin >> a >> b;

    vector<int> prefix(m), suffix(m);

    for (int i = 0, j = 0; j < m; j++) {
        while (i < n and a[i] != b[j]) {
            i++;
        }
        prefix[j] = i++;
    }

    for (int i = n - 1, j = m - 1; j >= 0; j--) {
        while (i >= 0 and a[i] != b[j]) {
            i--;
        }
        suffix[j] = i--;
    }

    // cout << "p: "; for (int x: prefix) cout << x << " "; cout << "\n";
    // cout << "s: "; for (int x: suffix) cout << x << " "; cout << "\n";
    int res = 0;
    for (int i = 0; i < m - 1; i++) {
        res = max(res, suffix[i + 1] - prefix[i]);
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
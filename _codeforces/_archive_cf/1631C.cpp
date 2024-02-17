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

bool check(vector<pii> &res, int k) {
    int sum = 0;
    for (auto &[f, s]: res) {
        sum += (f & s);
    }
    return sum == k;
}

void solve() {  
    int n, k;
    cin >> n >> k;

    vector<bool> used(n, false);
    vector<pii> res;

    if (k == 0) {
        used[0] = used[n - 1] = true;
        res.pb({0, n - 1});
    }
    else if (k == n - 1) {
        if (n <= 4) {
            cout << -1 << "\n";
            return;
        }
        used[n - 1] = used[n - 2] = true;
        res.pb({n - 1, n - 2});
        
        used[1] = used[n - 3] = true;
        res.pb({1, n - 3});
        
        used[2] = used[0] = true;
        res.pb({2, 0});
    }
    else {
        res.pb({k, n - 1});
        res.pb({n - 1 - k, 0});  
        used[0] = used[n - 1 - k] = true;
        used[k] = used[n - 1] = true;
    }
    for (int i = 0; i < n / 2; i++) {
        int j = n - 1 - i;
        if (used[i] or used[j]) 
            continue;
        else {
            res.pb({i, j});
        }
    }

    if (check(res, k)) {
        for (auto &[f, s]: res) {
            cout << f << " " << s << "\n";
        }
    }
    else {
        cout << "-1\n";
    }
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
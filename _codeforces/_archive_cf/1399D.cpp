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

    string s;
    cin >> s;

    vector<set<int>> a(2);
    for (int i = 0; i < n; i++) {   
        if (s[i] == '0') 
            a[0].insert(i);
        else 
            a[1].insert(i);
    }

    vector<int> used(n, 0);
    int color = 1;
    int x = -1;
    bool flag = 0;
    while (a[0].size() and a[1].size()) {
        if (*a[0].begin() < *a[1].begin())
            flag = 0;
        else 
            flag = 1;
        x = -1;
        while (a[flag].lower_bound(x) != a[flag].end()) {
            x = *a[flag].lower_bound(x);
            a[flag].erase(x);

            used[x] = color;
            flag = 1 - flag;
        }
        // cout << "0: "; for (int j: a[0]) cout << j << " "; cout << "\n";
        // cout << "1: "; for (int j: a[1]) cout << j << " "; cout << "\n\n";
        color++;
    }

    for (int j: a[0]) {
        used[j] = color++;
    }
    for (int j: a[1]) {
        used[j] = color++;
    }
    cout << --color << "\n";
    for (int x: used) {
        cout << x << " ";
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

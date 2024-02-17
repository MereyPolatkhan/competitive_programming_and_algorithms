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


double const e = 1e-6;


double calc(int i, int j, vector<int> &a) {
    return ((double)(a[j] - a[i])) / ((double)(j - i));
}

bool check(double x, double y) {
    if (x > y) 
        return (x - y) <= e;
    return (y - x) <= e;
}

int func(int index, double d, vector<int> &a) { 
    int cnt = 0;

    int l = index - 1; 
    double left = a[index] - d;
    while (l >= 0) {
        if (!check(left, (double)a[l]))
            cnt++;
        l--;
        left -= d;
    }

    int r = index + 1;
    double right = a[index] + d;
    while (r < (int)a.size()) {
        if (!check(right, (double)a[r])) 
            cnt++;
        r++;
        right += d;
    }

    return cnt;
}


void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (n <= 2) {
        cout << 0 << "\n";
        return;
    }
    int res = INT_MAX;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            res = min(res, func(i, calc(i, j, a), a));
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
    cin >> T;
    for (int test = 1; test <= T; test++) {
        solve();
    }

    return 0;
}
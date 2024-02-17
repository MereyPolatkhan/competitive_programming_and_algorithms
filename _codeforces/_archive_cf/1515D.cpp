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


int func(int d, vector<int> &cnt) {
    int res = 0;

    sort(rall(cnt));

    for (int x: cnt) {
        if (x % 2)
            x--;

        if (x <= d) {
            res += x / 2;
            d -= x;
        }
        else {
            res += d / 2;
            d = 0;
            break;  
        }
    }

    return res + d;
}

void solve() {
    int n, l, r;
    cin >> n >> l >> r;

    vector<int> a(n);
    vector<int> cnt1(n + 1, 0), cnt2(n + 1, 0);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i < l)
            cnt1[a[i]]++;
        else
            cnt2[a[i]]++;
    }   

    for (int i = 1; i <= n; i++) {
        int mn = min(cnt1[i], cnt2[i]);
        cnt1[i] -= mn, cnt2[i] -= mn;
        l -= mn, r -= mn;
    }

    if (l == r) {
        cout << l << "\n";
        return;
    }
    else if (l > r) {
        cout << func(l - r, cnt1) + r << "\n";
    }
    else {
        cout << func(r - l, cnt2) + l << "\n";
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
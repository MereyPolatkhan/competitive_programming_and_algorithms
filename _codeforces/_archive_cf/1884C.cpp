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
#include <stack>


using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef unsigned short int usi;

int func(vector<pii> &a) {
    sort(all(a));
    int cnt = 0;
    int res = 0;

    for (pii &it: a) {
        if (it.second == 0) {
            cnt++;
        }   
        else {
            cnt--;
        }
        res = max(res, cnt);
    }

    return res;
}

void print(vector<pii> &a) {
    for (auto it: a) {
        cout << it.first << " ";
    }
    cout << "\n";
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<pii> a;
    vector<pii> b;


    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;

        if (l != 1) {
            a.pb({l, 0});
            a.pb({r, 1});
        }
        if (r != m) {
            b.pb({l, 0});
            b.pb({r, 1});
        }
    }

    // cout << "a: ";
    // print(a);
    // cout << "\nb: ";
    // print(b);
    // cout << "\n\n";

    cout << max(func(a), func(b)) << "\n";
}   



int main() { 
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}

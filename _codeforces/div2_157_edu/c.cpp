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

int const MAX_SIZE = 5;
int const MAX_SUM = 45;

int cnt[MAX_SIZE + 1][MAX_SUM + 1];
vector<string> a;
int n;

int get_sum(string s) {
    int res = 0;
    for (int i = 0; i < s.size(); i++) {
        res += (int)s[i] - (int)'0';
    }
    return res;
}

ll calc(string & s, int until) {
    ll res = 0;
    for (int i = s.size() % 2; i <= until; i += 2) {
        int l = s.size() + i;
        int sum1 = get_sum(s.substr(0, l / 2));
        int sum2 = get_sum(s.substr(l / 2));

        int delta = sum1 - sum2;
        if (delta >= 0) {
            // cout << "s: " << s << "\t\t" << i << "\t\t\t" << cnt[i][delta] << "\n";
            res += cnt[i][delta];
        }
    }
    return res;
}

ll func() {
    ll res = 0;
    for (string s: a) {
        res += calc(s, s.size());

        reverse(all(s));
        res += calc(s, s.size() - 1);
    }
    return res;
}

void solve() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i].size()][get_sum(a[i])]++;
    }

    cout << func();
}





int main() { 
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}


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

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> a;
    for (int i = 0; i < n; i++) {
        if (s[i] == '*') {
            a.pb(i + 1);
        }
    }



    int k = a.size();
    if (k == 0) {
        cout << 0 << "\n";
        return;
    }
    int center = a[k / 2];
    ll res = 0;
    int j = 1;


    for (int i = 0; i < k / 2; i++) {
        res += (center - j - a[i]);
        j++;
    }
    j = 1;
    for (int i = k / 2 + 1; i < k; i++) {
        res += (a[i] - (center + j));
        j++;
    }

    cout << res << "\n";
}


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

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


string a, b;
int n, m;
int from, till;


bool check(string &s) {
    if (s.size() > b.size()) {
        return false;
    }
    else if (s.size() == b.size()) {
        return s == b;
    }

    if (b.substr(0, s.size()) == s) {
        string right = b.substr(s.size());
        reverse(all(right));

        int r = till - 1;
        int l = r - right.size() + 1;

        if (l >= 0 and r < a.size()) {
            return a.substr(l, r - l + 1) == right;
        }
    }
    
    return false;
}
    
void solve() {
    cin >> a >> b;
    n = a.size(), m = b.size();

    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= n - i; j++) {
            string s = a.substr(i, j);
            from = i, till = i + j - 1;
            if (check(s)) {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
}


int main() { 
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}



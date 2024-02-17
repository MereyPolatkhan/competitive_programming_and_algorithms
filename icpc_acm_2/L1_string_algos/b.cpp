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

vector<int> p_f(string s) { // O(n)
    int n = s.size();
    vector<int> p(n);
    p[0] = 0;
    for (int i = 1; i < n; i++) {
        int j = p[i - 1];
        while (j > 0 && s[j] != s[i])
            j = p[j - 1];
        if (s[i] == s[j]) 
            j = j + 1;
        p[i] = j;
    }
    return p;
}

void solve() {
    string b, a;
    cin >> b >> a;

    string q = a + "&" + b;

    vector<int> p = p_f(q);

    vector<int> res;
    for (int i = 0; i < p.size(); i++) {
        if (p[i] == a.size()) {
            res.pb(i - a.size() * 2 + 1);
        }
    }
    cout << res.size() << "\n";
    for (int i : res) cout << i << " ";
    cout << "\n";
}

/*  things to check:
    !  freopen
    !  clear & resize SET, MAP, VECTOR, etc. or write in local functions
    1) long long    
    2) array sizes
    3) corner cases (n = 1, n = 0, etc.)
*/

int main() { 
    freopen("search.in", "r", stdin);
    freopen("search.out", "w", stdout);

    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}


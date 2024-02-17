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
    string s;
    cin >> s;

    int n = s.size();
    int const prime = 31;
    vector<ull> h(n + 1), p(n + 1);

    h[0] = 0, p[0] = 1;
    for (int i = 1; i <= n; i++) 
        h[i] = h[i - 1] * prime + s[i - 1];
    
    for (int i = 1; i <= n; i++)
        p[i] = p[i - 1] * prime;




    int q;
    cin >> q;

    while (q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--, b--, c--, d--;
        ull h1 = h[b + 1] - h[a] * p[b + 1 - a];
        ull h2 = h[d + 1] - h[c] * p[d + 1 - c];
        if (h1 == h2) 
            cout << "Yes\n";
        else 
            cout << "No\n";
    }

}


/*  things to check:
    !  freopen
    !  clear & resize SET, MAP, VECTOR, etc. or write in local functions
    1) long long    
    2) array sizes
    3) corner cases (n = 1, n = 0, etc.)
*/

int main() { 
    #ifdef LOCAL 
    freopen("input.txt", "r", stdin);
    #else
    freopen("substrcmp.in", "r", stdin);
    freopen("substrcmp.out", "w", stdout);
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


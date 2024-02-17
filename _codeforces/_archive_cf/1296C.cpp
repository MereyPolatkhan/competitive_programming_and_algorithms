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

    map<pii, int> st;
    st[{0, 0}] = 0;
    int i = 0, j = 0;

    int l = 0, r = INT_MAX;

    for (int index = 0; index < n; index++) {
        if (s[index] == 'U') { 
            i++;
        }
        if (s[index] == 'R') {
            j++;
        }
        if (s[index] == 'D') {
            i--;
        }
        if (s[index] == 'L') {
            j--;
        }

        if (st.count({i, j})) { 
            if (r - l > index + 1 - st[{i, j}]) {
                r = index + 1, l = st[{i, j}];
            }
        }
        st[{i, j}] = index + 1;
    }   
    if (r - l == INT_MAX)
        cout << -1 << "\n";
    else 
        cout << ++l << " " << r << "\n";
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

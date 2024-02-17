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



void solve() {
    int n, m, x;
    cin >> n >> m >> x;

    vector<pii> a(n);
    for (int i = 0; i < n; i++) 
        cin >> a[i].first, a[i].second = i;


    set<pii> st;
    for (int i = 1; i <= m; i++) {
        st.insert({0, i});
    }

    vector<int> res(n, 0);

    for (pii &elem: a) {
        pii x_min = *st.begin();
        st.erase(st.begin());

        res[elem.second] = x_min.second;
        x_min.first += elem.first;
        st.insert(x_min);
    }

    if (st.rbegin()->first - st.begin()->first <= x) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
    for (int i: res)    
        cout << i << " ";
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
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // cout << "\nTime elapsed: " << double(clock()) / CLOCKS_PER_SEC << " s.\n";
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int T = 1;
    cin >> T;
    for (int test = 1; test <= T; test++) {
        // cout << "test: #" << test << "\n";
        solve();
    }

    return 0;
}


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



int n, m;
vector < pair < int, int > > g[100005];
long long int dist[100005];


void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        g[a].push_back(make_pair(b, w));
        g[b].push_back(make_pair(a, w));
    }
    int s = 1;
    int t = n;
    
    long long int inf = (long long int)(1e15);
    for (int i = 1; i <= n; i++) {
        if (i == s) {
            dist[i] = 0;
        } else {
            dist[i] = inf;
        }
    }
    
    set < pair < long long int, int > > st;
    st.insert(make_pair(dist[s], s));

    vector<int> come(n + 1, -1);
    while (!st.empty()) {
        int v = st.begin() -> second;
        st.erase(st.begin());
        for (auto elem : g[v]) {
            int to = elem.first;
            int w = elem.second;   
            if (dist[to] > dist[v] + w) {
                // come from

                come[to] = v;

                st.erase(make_pair(dist[to], to));
                dist[to] = dist[v] + w;
                st.insert(make_pair(dist[to], to));
            }
        }
    }
    
    if (dist[t] == inf) {
        cout << -1;
    } else {
        vector<int> res;
        int i = n;
        while (i != -1) {
            res.pb(i);
            i = come[i];
        }
        reverse(all(res));
        for (int i : res) {
            cout << i << " ";
        }
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
    // freopen("output.txt", "w", stdout);
    // #else
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


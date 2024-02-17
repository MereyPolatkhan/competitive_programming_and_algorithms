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

int const N = 105;
int a[N][N];
vector<pii> g[N];
set<pii> cnt;
int n;



bool dijkstra(int start) {
    vector<int> dist(n + 1, 1e9);
    dist[start] = 0;

    set < pair < long long int, int > > st;

    st.insert(make_pair(dist[start], start));

    vector<int> come(n + 1, -1);
    while (!st.empty()) {
        int v = st.begin() -> second;
        st.erase(st.begin());
        for (auto elem : g[v]) {
            int to = elem.first;
            int w = elem.second;   
            if (dist[to] >= dist[v] + w) {
                // come from

                come[to] = v;

                st.erase(make_pair(dist[to], to));
                dist[to] = dist[v] + w;
                st.insert(make_pair(dist[to], to));
            }
        }
    }

    // cout << "start: " << start << "\n";
    // for (int i = 1; i <= n; i++) {
    //     cout << dist[i] << " ";
    // }
    // cout << "\n";
    // cout << "come: \n";
    // for (int i = 1; i <= n; i++) {
    //     cout << come[i] << " ";
    // }
    // cout << "\n";
    // cout << "i: \n";
    // for (int i = 1; i <= n; i++) {
    //     cout << i << " ";
    // }
    // cout << "\n\n\n";



    for (int i = 1; i <= n; i++) {
        if (i == start) {
            continue;
        }

        if (dist[i] < a[start][i]) {
            return false;
        }
        else if (dist[i] == a[start][i] and come[i] != start) {
            int fst = i;
            int scd = start;
            if (fst > scd) 
                swap(fst, scd);
            cnt.insert({fst, scd});
        }   
    }
    return true;
}


void solve() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if (i == j) {
                continue;
            }
            else if (a[i][j] == 0) {
                cout << -1 << "\n";
                return;
            } 
            else {
                g[i].push_back({j, a[i][j]});
                g[j].push_back({i, a[i][j]});
            }
        }
    }

    
    for (int i = 1; i <= n; i++) {
        bool flag = dijkstra(i);
        if (flag == false) {
            cout << - 1 << "\n";
            return;
        }
    }


    // cout << "cnt : \n";
    // for (const pii it: cnt) {
    //     cout << it.first << " " << it.second << "\n";
    // }
    cout << cnt.size() << "\n";

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


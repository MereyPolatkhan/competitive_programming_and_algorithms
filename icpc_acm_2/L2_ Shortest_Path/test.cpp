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

int const N = 1e5 + 7;
int n, m;
vector<pii> g[N];
vector<int> dist;


void func(vector<int> &a, map<int, int> &mp) {
    int i = 0;
    while (i < a.size()) {
        int j = i + 1;
        int x = a[i];
        while (x == a[j] - 1) {
            x++;
            j++;
        }
        for (int k = i; k < j; k++)
            mp[a[k]] = x + 1;
        i = j;
    }
}
void solve() {
    cin >> n >> m;  

    for (int i = 1; i <= m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        g[x].pb({y, w});
        g[y].pb({x, w});
    }

    vector<map<int, int>> wait(n + 1);

    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        vector<int> temp(k);
        for (int j = 0; j < k; j++) {
            cin >> temp[j];
        }
        func(temp, wait[i]);
    }

    int start = 1;
    int target = n;

    dist.resize(n + 1, INT_MAX);
    dist[start] = 0;
    while (wait[start].count(dist[start])) {
        dist[start]++;
    }
    set<pii> st;

    st.insert({dist[start], start});

    while (st.size()) {
        int v = st.begin()->second;

        st.erase(st.begin());

        for (auto elem: g[v]) {
            int to = elem.first;
            int w = elem.second;

            int val = dist[v] + w;
            while (to!=target and wait[to].count(val)) {
                val++;
            }

            if (dist[to] > val) {
                st.erase(make_pair(dist[to], to));
                dist[to] = val;
                st.insert(make_pair(dist[to], to));
            }
        }
    }


    if (dist[target] == INT_MAX) {
        cout << -1 << "\n";
    }
    else {
        cout << dist[target] << "\n";
    }
}


int main() { 
    int n;
    cin >> n;

    vector<int> a(n);;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    map<int, int> mp;

    func(a, mp);

    for (auto i: mp) {
        cout << i.first << ": " << i.second << "\n";
    }
    


    return 0;
}

/*  things to check:
    !  freopen
    !  clear & resize SET, MAP, VECTOR, etc. or write in local functions
    1) long long    
    2) array sizes
    3) corner cases (n = 1, n = 0, etc.)
*/

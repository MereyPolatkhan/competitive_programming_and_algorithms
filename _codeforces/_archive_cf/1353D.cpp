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


int n;
vector<int> a;

void solve() {
    cin >> n;
    a.resize(n + 1, 0);

    priority_queue<pair<int, pii>> pq;

    pq.push({1 + n, {-1, -n}});
    int cnt = 1;
    while (pq.size()) {
        int l = pq.top().second.first;
        int r = pq.top().second.second;
        l = -l;
        r = -r;
        pq.pop();

        // cout << "l: " << l << "  r: " << r << "\n";

        int mid = (l + r) / 2;
        a[mid] = cnt++;
        if (mid - 1 - l >= 0)
            pq.push({mid - 1 - l, {-l, -mid + 1}});
        if (r - (mid + 1) >= 0)
            pq.push({r - (mid + 1), {-mid - 1, -r}});
    }

    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n\n\n\n";
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

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


    int n;
    cin >> n;

    priority_queue<pii> pq;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;

        if (x)
            pq.push({x, i});
    }
     

    vector<pii> res;
    while (pq.size() >= 2) {
        pii x = pq.top(); pq.pop();
        pii y = pq.top(); pq.pop();
        res.pb({x.second, y.second});
        if (x.first > 1)
            pq.push({x.first - 1, x.second});
        if (y.first > 1)
            pq.push({y.first - 1, y.second});
    }   

    cout << res.size() << "\n";
    for (pii &x: res) 
        cout << x.first << " " << x.second << "\n";

    cout << "\n";
}




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


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

struct cmp {
    bool operator() (const pair<int, int>& a, const pair<int, int>& b) const {
        return a.second > b.second;
    }
};

void print(priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq) {
    while (pq.size()) {
        cout << pq.top().first << " " << pq.top().second << "\n";
        pq.pop();
    }
    cout << "\n\n";
}

void solve() {
    int n;
    cin >> n;

    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    
    sort(a.begin(), a.end());

    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

    for (auto &cur: a) {
        if (pq.size())cout << "top(): " << pq.top().first << " " << pq.top().second << "\n";
        else cout << "empty\n";
        if (pq.empty() or pq.top().second >= cur.first) {
            pq.push(cur);
        }
        else {
            pq.pop();
            pq.push(cur);
        }

        print(pq);
    }


    cout << pq.size() << "\n";
}


int32_t main() { 
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);


    int T = 1;
    // cin >> T;
    for (int test = 1; test <= T; test++) {
        solve();
    }

    return 0;
}

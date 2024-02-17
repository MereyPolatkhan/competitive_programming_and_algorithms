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
    ll n, x;
    cin >> n >> x;
    ll res = 0;
    vector<ll> a(n);
    priority_queue<ll> pq;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pq.push(a[i]);
    }


    while (pq.size() and pq.top() <= x) {
        res++;
        pq.pop();
        x = (x + 1) / 2;
    }

    while (x > 1 and pq.size()) {
        res++;
        ll elem = pq.top(); pq.pop();
        elem -= x;
        if (elem)
            pq.push(elem);
        x = (x + 1) / 2;
    }


    while (pq.size()) {
        res += pq.top();
        pq.pop();
    }

    cout << res << "\n";
    
}


int main() { 
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


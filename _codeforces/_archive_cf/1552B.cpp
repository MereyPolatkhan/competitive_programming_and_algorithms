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
vector<ll> a;

bool check(ll XOR) {
    int cnt = 0;
    ll cur = 0;
    for (int i = 0; i < n; i++) {
        cur ^= a[i];
        if (cur == XOR) {
            cnt++;
            cur = 0;
        }
    }
    return cnt > 1 and cnt % 2;
}

void solve() {
    cin >> n;
    a.resize(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll XOR = 0;
    for (int i = 0; i < n; i++) {
        XOR ^= a[i];
    }

    if (XOR == 0 or check(XOR)) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}   


int main() { 
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int T = 1;
    cin >> T;
    for (int test = 1; test <= T; test++) {
        solve();
    }

    return 0;
}
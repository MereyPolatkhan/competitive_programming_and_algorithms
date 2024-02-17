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
    int up = 0, down = 0, left = 0, right = 0;

    set<pii> st;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        st.insert({x, y});
    }

    for (auto it: st) {
        if (it.first > 0)
            up = 1;
        if (it.first < 0) 
            down = 1;
        if (it.second > 0)
            right = 1;
        if (it.second < 0)
            left = 1;
    }
    if (up and down and left and right)
        cout << "NO\n";
    else 
        cout << "YES\n";
}


int main() { 
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


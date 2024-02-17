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


struct node {
    int t, l, h;
}; 

void solve() {
    int n, m;
    cin >> n >> m;

    vector<node> a(n);
    node cur = {0, m, m};
    bool flag = true;
    for (int i = 0; i < n; i++) {
        int time, low, high;
        cin >> time >> low >> high;

        cur.l = max(cur.l - (time - cur.t), low);
        cur.h = min(cur.h + (time - cur.t), high);
        cur.t = time;
        // cout << "after: " << time << " => " << cur.l << " " << cur.h << "\n";
        if (cur.l > cur.h) {
            flag = false;
        }
    }
    if (flag) 
        cout << "YES\n";
    else    
        cout << "NO\n";

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

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

void func(int &a, int &b){
    if (a and b) 
        a--, b--;
}

bool check(int x) {
    return x >= 0 and x <= n - 2;
}

bool check2(int u, int r, int d, int l) {
    func(u, r);
    func(r, d);
    func(d, l);
    func(l, u);

    return (check(u) and check(r) and check(d) and check(l));
}   

void solve() {
    cin >> n;
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (check2(a, b, c, d) 
    or  check2(b, c, d, a) 
    or  check2(c, d, a, b) 
    or  check2(d, a, b, c)
    ) 
        cout << "YES\n";
    else    
        cout << "NO\n";
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
        // if (test == 45) {
        //     int n, a, b, c, d;
        //     cin >> n >> a >> b >> c >> d;
        //     cout << n << "_" << a << "_" << b << "_" << c << "_" << d << ";";
        //     return 0;
        // }

        solve();
    }

    return 0;
}


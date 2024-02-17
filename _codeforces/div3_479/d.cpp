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
bool flag = false;

bool check(ull x, ull y)  {
    return x * 2 == y or x == y * 3;
}

void func(ull start, vector<ull> a) {
    unordered_map<ull, bool> used;
    vector<ull> res;

    used[start] = true;
    res.pb(start);

    for (auto x: a) {
        for (auto y: a) {
            if (!used[y] and check(start, y)) {
                start = y;
                used[start] = true;
                res.pb(start);
                break;
            }
        }
    
    }   

    for (auto x: a) {
        if (used[x] == false) {
            return;
        }
    }

    flag = true;
    for (auto x: res) {
        cout << x << " ";
    }
    cout << "\n";
}


void solve() {

    cin >> n;

    vector<ull> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    

    for (int i = 0; i < n; i++) {
        func(a[i], a);
        if (flag) {
            return;
        }
    }


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
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}


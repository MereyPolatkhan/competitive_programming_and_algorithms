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
string a, b;

int find(int i) {
    for (int j = i + 1; j < n; j++) {
        if (a[j] == b[i]) {
            return j;
        }
    }
    return -1;
}


void solve() {

    cin >> n;

    cin >> a >> b;

    vector<int> res;

    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) 
            continue;

        int index = find(i);
        if (index == -1) {
            cout << -1 << "\n";
            return;
        }

        for (int j = index - 1; j >= i; j--) {
            res.pb(j);
            swap(a[j], a[j + 1]);
        }
    }

    // cout << "a: " << a << "  b: " << b << "\n";
    cout << res.size() << "\n";
    for (auto it: res) {
        cout << it + 1 << " ";
    }
    cout << "\n";
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


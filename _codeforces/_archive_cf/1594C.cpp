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



void solve() {
    int n; char c;
    cin >> n >> c;

    string s;
    cin >> s;

    if (count(all(s), c) == n) {
        cout << 0 << "\n";
        return;
    }
    
    for (int i = 1; i <= n; i++) {
        bool flag = true;
        for (int j = i; j <= n; j += i) {
            if (s[j - 1] != c) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << 1 << "\n" << i << "\n";
            return;
        }
    }

    cout << 2 << "\n" << n - 1 << " " << n << "\n";

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
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}


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
    int n;
    cin >> n;
    if (n <= 3) {
        cout << -1 << "\n";
        return;
    }
    else if (n == 4) {
        cout << "3 1 4 2\n";
        return;
    }
    vector<int> a;

    int m;
    for (int i = 1; i <= n; i += 2) {
        a.pb(i);
        m = i;
    }
    m -= 3;
    a.pb(m);
    
    if (n % 2 == 1) {
        n--;
    }
    for (int i = n; i >= 2; i -= 2) {
        if (i != m) {
            a.pb(i);
        }
    }
    for (int i : a) cout << i << " ";
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
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}


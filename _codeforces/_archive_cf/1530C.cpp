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

    vector<int> a(n);
    vector<int> b(n);

    for (int i = 0; i < n; i++) 
        cin >> a[i];
    
    for (int i = 0; i < n; i++) 
        cin >> b[i];

    
    sort(all(a));
    sort(all(b));

    ll Sa = 0, Sb = 0;

    for (int i = n / 4; i < n; i++) {
        Sa += a[i];
        Sb += b[i];
    }

    int i = n;
    int j = n / 4;

    int cnt = 0;
    while (Sa < Sb) {
        Sa += 100;
        Sb += 0;
        if 
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
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}


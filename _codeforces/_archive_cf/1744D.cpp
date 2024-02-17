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

 
int calc(int x) {
    int cnt = 0;
    while (x % 2 == 0) {
        x /= 2;
        cnt++;
    }
    return cnt;
}

void solve() {

    int n;
    cin >> n;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int cnt2 = 0;
    for (int i = 1; i <= n; i++) {
        cnt2 += calc(a[i]);
    }
    

    if (cnt2 >= n) {
        cout << 0 << "\n";
        return;
    }


    vector<int> powers;
    for (int i = 1; i <= n; i++) {
        powers.pb(calc(i));
    }

    sort(rall(powers));

    int operations = 0; 
    for (int &x: powers) {
        if (cnt2 < n) {
            cnt2 += x;
            operations++;
        }
        else {
            break;
        }
    }        

    if (cnt2 < n) {
        cout << -1 << "\n";
    }
    else {
        cout << operations << "\n";
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


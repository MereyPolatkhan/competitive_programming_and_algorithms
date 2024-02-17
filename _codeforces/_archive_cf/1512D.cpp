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


bool func1(vector<int> &a) {
    ll sum = 0;
    int n = a.size();

    for (int i = 0; i < n - 2; i++) {
        sum += a[i];
    }
    
    if (sum == a[n - 2]) {
        for (int i = 0; i < n - 2; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
        return true;
    }
    return false;
}

bool func2(vector<int> &a) {
    ll sum = 0; 
    int n = a.size();

    for (int i = 0; i < n - 1; i++) {
        sum += a[i];
    }

    for (int i = 0; i < n - 1; i++) {
        if (sum - a[i] == a.back()) {
            for (int j = 0; j < n - 1; j++) {
                if (j != i) {
                    cout << a[j] << " ";
                }
            }
            cout << "\n";
            return true;
        }
    }
    return false;
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n + 2);
    
    for (int i = 0; i < n + 2; i++) {
        cin >> a[i];
    }

    sort(all(a));

    if (func1(a)) {
        return;
    }

    if (func2(a)) {
        return;
    }

    cout << -1 << "\n";
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


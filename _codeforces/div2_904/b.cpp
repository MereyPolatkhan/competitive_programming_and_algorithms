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

int n;
long long func(vector<bool> &a, int index, set<int> st1, set<int> st0) {
    int j = n - index + 1; 
    long long res = 0;

    while (st1.size() and st0.size() and j <= *st1.rbegin()) {
        int one = *st1.rbegin();
        st1.erase(one);


        set<int>::iterator it = st0.lower_bound(one);
        if (it == st0.begin()) {
            return -1;
            // pizdec
        }
        else {
            it--;
            st1.insert(*it);
            res += abs(*it - one);
            st0.erase(it);
        }

    }

    return res;
}

void solve() {

    cin >> n;

    string s;
    cin >> s;


    vector<bool> a(n + 1);
    set<int> ones;
    set<int> zeros;

    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            a[i + 1] = true;
            ones.insert(i + 1);
        }
        else {
            a[i + 1] = false;
            zeros.insert(i + 1);
        }
    }

    if (*max_element(all(a)) == 0) {
        for (int i = 0; i < n; i++) {
            cout << 0 << " ";
        }
        cout << "\n";
        return;
    }


    vector<long long> res;
    for (int i = 1; i <= n; i++) {
        int flag = func(a, i, ones, zeros);
        if (flag != -1) {
            cout << flag << " ";
        }
        else {
            for (int j = i; j <= n; j++) {
                cout << -1 << " ";
            }
            cout << "\n";
            return;
        }
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
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}


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


int n = 2, m;

void print(vector<int>& a) {
    cout << " ==> ";
    for (int &i: a) cout << i << " ";
    cout << "\n";
}



void solve() {
    cin >> m;

    vector<vector<int>> a(2, vector<int> (m));

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    vector<int> s = a[0], p = a[1];

    for (int i = m - 2; i >= 0; i--) {
        s[i] += s[i + 1];
    }

    for (int i = 0; i < m - 1; i++) {
        p[i + 1] += p[i];
    }

    // cout << "s: "; // print(s);
    // cout << "p: "; // print(p);



    if (m >= 2) {
        vector<int> b;
        b.pb(s[1]);
        for (int i = 0; i < m - 2; i++) {
            b.pb(max(p[i], s[i + 2]));
        }
        b.pb(p[m - 2]);
        sort(all(b));
        cout << b[0] << "\n";
        // cout << "b: ";
        // print(b);
    }
    else {
        cout << 0 << "\n";
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
    freopen("output.txt", "w", stdout);
    #endif
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}


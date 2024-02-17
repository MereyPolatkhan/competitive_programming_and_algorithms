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
    char a = 'a', b = 'a';
    ll cnta = 0, cntb = 0;

    

    int q;
    cin >> q;

    bool other = false;
    while (q--) {
        int d, k;
        cin >> d >> k;
        string s;
        cin >> s;

        
        for (char c: s) {
            if (d == 1) {
                if (c == 'a') 
                    cnta += k;
                else 
                    other = true;

            }
            if (d == 2) {
                if (c != 'a') {
                    b = c;
                }
                if (c == 'a') 
                    cntb += k;
            }
        }
        
        if ((int)a < (int)b) {
            cout << "YES\n";
        }
        else if (a == b and other == false and cnta < cntb) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
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
    #endif
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}


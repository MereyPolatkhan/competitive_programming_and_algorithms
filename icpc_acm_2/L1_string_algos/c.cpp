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

ll my_hash(string s) {
    const int p = 31;
	ll h = 0;
	for (int i = 0; i < s.length(); i++) {
		h = h * p + s[i];
	}
	return h;
}



void solve() {
    string s;
    cin >> s;
    
    unordered_set<ll> st;

    for (int i = 1; i <= s.size(); i++) {       
        for (int j = 0; j < s.size(); j++) {
            if (j + i <= s.size()) {
                st.insert(my_hash(s.substr(j, i)));
            }
        }
    }

    cout << st.size() << "\n";
}

/*  things to check:
    !  freopen
    !  clear & resize SET, MAP, VECTOR, etc. or write in local functions
    1) long long    
    2) array sizes
    3) corner cases (n = 1, n = 0, etc.)
*/

int main() { 
    freopen("unequal.in", "r", stdin);
    freopen("unequal.out", "w", stdout);

    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}


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
#include <stack>


using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef unsigned short int usi;

void solve() {
    string s;
    cin >> s;

    ll pos;
    cin >> pos;

    int n = s.size();

    stack<char> st;

    for (char &c: s) {
        while (st.size() and st.top() > c and pos > n) {
            st.pop();
            pos -= n;
            n--;
        }
        st.push(c);
    }    

    while (pos > n) {
        st.pop();
        pos -= n;
        n--;
    }

    string res = "";
    while (st.size()) {
        res += st.top();
        st.pop();
    }
    reverse(all(res));

    cout << res[pos - 1] << "";


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

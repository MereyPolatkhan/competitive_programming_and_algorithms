
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


void solve() {
    int n;
    cin >> n;
    
    string s;
    cin >> s;

    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (st.size() and s[st.top()] < s[i]) {
            st.pop();
        }
        st.push(i);
    }

    set<int> idx;
    while (st.size()) {
        idx.insert(st.top());
        st.pop();
    }

    string t = "";
    for (int i: idx) {
        t += s[i];
    }

    int j = 0;
    while (j < t.size() and t[0] == t[j]) {
        j++;
    }
    int res = t.size() - j;

    sort(all(t));
    int i = 0;
    for (int c: idx) {
        s[c] = t[i++];
    }

    string cp = s;
    sort(all(cp));
    if (cp == s) 
        cout << res << "\n";

    else {
        cout << -1 << "\n";
    }
}


int main() { 
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);


    int T = 1;
    cin >> T;
    for (int test = 1; test <= T; test++) {
        solve();
    }

    return 0;
}

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


ll func(priority_queue<int> &pq) {
    ll res = 0;

    while (pq.size()) {
        vector<int> temp;
        res++;
        while (pq.size()) {
            int x = pq.top(); pq.pop();
            x /= 2;
            if (x)
                temp.pb(x);
        }
        for (int j : temp) 
            pq.push(j);
    }

    return res;
}

void solve() {
    string s;
    cin >> s;

    set<char> st;
    for (int i = 0; i < s.size(); i++){ 
        st.insert(s[i]);
    }

    ll res = INT_MAX;
    for (const char &c: st) {
        int cnt = 0;    
        priority_queue<int> pq;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == c) {
                if (cnt) pq.push(cnt);
                cnt = 0;
            }
            else {
                cnt++;
            }
        }
        if (cnt)
            pq.push(cnt);

        res = min(res, func(pq));
    }
    cout << res << "\n";
    // cout << "\n\n\n";
}


int main() { 
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // cout << "\nTime elapsed: " << double(clock()) / CLOCKS_PER_SEC << " s.\n";
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);
    // cout.tie(0);


    int T = 1;
    cin >> T;
    for (int test = 1; test <= T; test++) {
        // cout << "test: #" << test << "\n";
        solve();
    }

    return 0;
}
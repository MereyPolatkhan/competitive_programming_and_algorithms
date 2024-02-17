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
    int n, k;
    cin >> n >> k;



    priority_queue<int, vector<int>, greater<int> > AB, A, B;

    
    for (int i = 0; i < n; i++) {
        int t, alice, bob;
        cin >> t >> alice >> bob;

        if (alice and bob) {
            AB.push(t);
        }
        else if (alice) {
            A.push(t);
        }   
        else if (bob) {
            B.push(t);
        }
    }

    int res = 0;

    while (k--) {
        if (AB.size() and A.size() and B.size()) {
            if (AB.top() <= A.top() + B.top()) {
                res += AB.top();
                AB.pop();
            }
            else {
                res += A.top() + B.top();
                A.pop();
                B.pop();
            }
        }
        else if (AB.size()) {
            res += AB.top();
            AB.pop();

        }
        else if (A.size() and B.size()) {
            res += A.top() + B.top();
            A.pop();
            B.pop();
        }
        else {
            cout << -1 << "\n";
            return;
        }
    }

    cout << res << "\n";
}

int32_t main() { 
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);


    int T = 1;
    // cin >> T;
    for (int test = 1; test <= T; test++) {
        solve();
    }

    return 0;
}

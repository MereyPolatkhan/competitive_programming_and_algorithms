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


int n, q;
string s;

vector<string> a;
set<char> used;

const string abc = "abc";

void func1(string temp = "") {
    if (temp.size() == 3) {
        a.push_back(temp);
        return;
    }
    for (int i = 0; i < 3; i++) {
        if (used.count(abc[i])) {
            continue;
        }
        temp.push_back(abc[i]);
        used.insert(abc[i]);

        func1(temp);
        
        temp.pop_back();
        used.erase(abc[i]);
    }
}

void func2(string &t) {
    string temp = t;
    while (t.size() < n) {
        t += temp;
    }

    while (t.size() > n) {
        t.pop_back();
    }
}


void func3(vector<int> &p, string &t) {
    for (int i = 1; i <= n; i++) {
        p[i] = (s[i - 1] != t[i - 1]);
    }
    for (int i = 1; i <= n; i++) {
        p[i] += p[i - 1];
    }
}

void solve() {
    cin >> n >> q;
    cin >> s;

    func1();

    vector<vector<int>> prefixes(6, vector<int> (n + 1, 0));
    for (int i = 0; i < a.size(); i++) {
        func2(a[i]);
        func3(prefixes[i], a[i]);
    }


    while (q--) {
        int l, r;
        cin >> l >> r;
        int mn = s.size();
        for (int i = 0; i < prefixes.size(); i++) {
            mn = min(mn, prefixes[i][r] - prefixes[i][l - 1]);
        }
        cout << mn << "\n";
    }
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

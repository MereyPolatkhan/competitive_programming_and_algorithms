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
void dfs(int v, map<int, set<pii>> &mp, vector<int> &res, int cur) {
    for (pii const &p: mp[v]) {
        int x = p.first;
        int index = p.second;

        res[index] = 5 - cur;
        cur = 5 - cur;

        mp[x].erase({v, index});

        dfs(x, mp, res, cur);
    }   
}

void solve() {
    cin >> n;
    
    map<int, set<pii>> mp;
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        mp[x].insert({y, i});
        mp[y].insert({x, i});
    }

    for (auto &it: mp) {
        if (it.second.size() >= 3) {
            cout << -1 << "\n";
            return;
        }
    }


    vector<int> res(n - 1, 0);
    dfs(1, mp, res, 2);

    for (int &d: res) 
        cout << d << " ";
    
    cout << "\n";
}




int main() { 
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // cout << "\nTime elapsed: " << double(clock()) / CLOCKS_PER_SEC << " s.\n";
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int T = 1;
    cin >> T;
    for (int test = 1; test <= T; test++) {
        // cout << "test: #" << test << "\n";
        solve();
    }

    return 0;
}


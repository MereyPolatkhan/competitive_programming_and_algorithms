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

bool cmp(set<int> a, set<int> b) {
    return a.size() > b.size();
}


int it = 0;
void solve() {

    int n, k;
    cin >> n >> k;

    vector<int> a(n);

    for (int i = 0; i < n; i++) 
        cin >> a[i];



    map<int, set<int>> mp;
    for (int i = 0; i < n; i++) {
        if (mp[a[i]].size() < k)
            mp[a[i]].insert(i);
    }

    cout << "map:\n";
    for (auto &it: mp) {
        cout << it.first << ": ";
        for (int j: it.second) {
            cout << j << " ";
        }
        cout << "\n";
    }
    cout << "\n\n";


    vector<set<int>> b;
    set<int> c;
    for (auto &it: mp) {
        if (it.second.size() == k) 
            b.pb(it.second);
        else
            c.insert(it.second.begin(), it.second.end()); 
    }

    set<int> temp;
    for (int const &elem: c) {
        temp.insert(elem);
        if (temp.size() == k) {
            b.pb(temp);
            temp.clear();
        }
    }

    cout << "b: \n";
    for (auto st: b) {
        for (int i: st) 
            cout << i << " ";
        cout << "\n";
    }
    cout << "\n\n";


    vector<int> res(n, 0);
    for (int i = 0; i < b.size(); i++) {
        if (b[i].size() < k) 
            continue;

        int color = 1;
        for (const int & index: b[i]) {
            res[index] = color++;
        }
    }

    // ++it;
    // if (it == 185) {
    //     cout << "n=" << n << "__k=" << k << "___";
    //     cout << "a=";
    //     for (int i : a) {
    //         cout <<  i << "_";
    //     }
    //     cout << ";";
    //     return;
    // }
    for (int x: res) 
        cout << x << " ";

    cout << "\n";


}


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

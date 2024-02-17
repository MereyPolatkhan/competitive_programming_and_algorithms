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

    string a, b;
    cin >> a >> b;

    map<char, int> mp1, mp2;

    for (char c: a)    
        mp1[c]++;
    for (char c: b)
        if (mp1[c]) 
            mp1[c]--;
    

    for (char c: b) 
        mp2[c]++;
    for (char c: a) 
        if (mp2[c])
            mp2[c]--;
    
    


    for (auto &it1: mp1) {
        if (it1.second % k) 
            continue;

        for (auto &it2: mp2) {
            if (it2.second % k or it1.first > it2.first) 
                continue;

            if (it1.second >= it2.second) {
                it1.second -= it2.second;
                it2.second = 0;
            }
            else {
                it2.second -= it1.second;
                it1.second = 0;
            }
        }
    }

    for (auto &it1: mp1) {
        if (it1.second) {
            cout << "NO\n";
            return;
        }
    }

    for (auto &it2: mp2) {
        if (it2.second) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";

    return;

    cout << "mp1: \n";
    for (auto it: mp1) {
        cout << it.first << " : " << it.second << "\n";
    }
    cout << "\n";

    cout << "mp2: \n";
    for (auto it: mp2) {
        cout << it.first << " : " << it.second << "\n";
    }
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";

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


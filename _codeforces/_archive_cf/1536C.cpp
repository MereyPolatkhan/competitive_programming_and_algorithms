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



int n;
string s;

 

void solve() {
    cin >> n;
    cin >> s;   

    map<double, int> mp;
    map<char, int> pref;

    for (int i = 0; i < n; i++) {
        pref[s[i]]++;
        if (pref['D'] and pref['K']) {
            mp[(double)pref['D'] / (double)pref['K']]++;
            cout << mp[(double)pref['D'] / (double)pref['K']] << " ";
        }
        else {
            cout << pref['D'] + pref['K'] << " ";
        }
    }
    cout << "\n";   
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
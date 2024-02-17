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
    string s;
    cin >> s;
    int n = s.size();

    map<char, int> mp;
    for (char &c: s) {
        mp[c]++;
    }

    int index = -1;
    for (int i = 0; i < n; i++) {
        if (mp['0'] and mp['1']) {
            if (s[i] == '1') {
                mp['0']--;
            }   
            if (s[i] == '0') {
                mp['1']--;
            }
        }
        else if (mp['0']) {
            if (s[i] == '1') {
                mp['0']--;
            }
            else {
                index = i;  
                break;
            }
        }
        else if (mp['1']) {
            if (s[i] == '0') {
                mp['1']--;
            }
            else {
                index = i;
                break;
            }
        }
    }
    if (index == -1) {
        cout << 0 << "\n";
    }
    else 
        cout << n - index << "\n";
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


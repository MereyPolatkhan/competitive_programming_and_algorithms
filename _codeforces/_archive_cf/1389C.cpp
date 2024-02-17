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


int ctoi(char c) {
    return (int)c - (int)'0';
}


int func(int x, int y, string &s) {
    int res = 0;
    for (int i = 0; i < s.size(); i++) {
        if (ctoi(s[i]) == x) {
            res++;
            swap(x, y);
        }
    }

    if (x != y and res % 2) 
        res--;

    return res;
}



void solve() {
    string s;
    cin >> s;

    int res = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            res = max(res, func(i, j, s));
        }
    }
    cout << s.size() - res << "\n";
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
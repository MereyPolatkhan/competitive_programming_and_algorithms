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
    char c = s[0];
    int x = (int)s[1] - (int)'0';

    vector<string> a;
    for (int i = 1; i <= 8; i++) {
        string temp = "";
        if (i != x) {
            temp += c;
            temp += to_string(i);
            a.pb(temp);
        }
    }

    for (char i = 'a'; i <= 'h'; i++) {
        if (i != c) {
            string temp = "";
            temp += i;
            temp += to_string(x);
            a.pb(temp);
        }
    }
    for (auto y: a) {
        cout << y << "\n";
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


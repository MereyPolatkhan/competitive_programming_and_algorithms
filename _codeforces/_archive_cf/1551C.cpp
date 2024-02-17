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

const char other = '$';


bool cmp(pii &a, pii &b) {
    return a.first - a.second < b.first - b.second;
}

int func(vector<string> &a, char dominant) {
    vector<map<char, int>> mpv;
    int cnt_dominant = 0, cnt_other = 0;
    for (string &s: a) {
        map<char, int> lcl;
        for (char &c: s) {
            if (c == dominant)
                lcl[dominant]++, cnt_dominant++;
            else    
                lcl[other]++, cnt_other++;
        }
        mpv.push_back(lcl);
    }

    vector<pii> temp;
    for (auto &v: mpv) {
        temp.pb({v[dominant], v[other]});
    }

    sort(all(temp), &cmp);

    int n = a.size();
    int i = 0;
    while (i < temp.size() and cnt_dominant <= cnt_other) {
        cnt_dominant -= temp[i].first, cnt_other -= temp[i].second;
        i++, n--;
    }
    return n;
}


void solve() {
    int n;
    cin >> n;
    vector<string> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int res = 0;
    for (char c = 'a'; c <= 'z'; c++) {
        res = max(res, func(a, c));
    }
    cout << res << "\n";
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
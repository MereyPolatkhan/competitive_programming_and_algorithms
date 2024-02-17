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


#define V first
#define T second

void solve() {
    int n, l;
    cin >> n >> l;

    vector<int> a(n);
    for (int i = 0; i < n; i++) 
        cin >> a[i];

    
    vector<pair<double, double>> p(n), s(n);
    double v, start;

    v = 1, start = 0;
    for (int i = 0; i < n; i++) {
        p[i] = {v, (a[i] - start) / v++};
        start = a[i];
    }
    v = 1, start = l;
    for (int i = n - 1; i >= 0; i--) {
        s[i] = {v, (start - a[i]) / v++};
        start = a[i];
    }


    for (int i = 1; i < n; i++) { 
        p[i].T += p[i - 1].T;
    }
    for (int i = n - 2; i >= 0; i--) {
        s[i].T += s[i + 1].T;
    }

    cout << fixed << setprecision(10);
    // for (auto x: p) cout << x.T << "\t"; cout << "\n";
    // for (auto x: s) cout << x.T << "\t"; cout << "\n";
    // cout << "\n";


    int x = -1;
    double lucky = -1;
    for (int i = 0; i < n; i++) {
        if (p[i].T < s[i].T)
            x = i;
        if (p[i].T == s[i].T)   
            lucky = p[i].T;
    }
    if (lucky != -1) {
        cout << lucky << "\n";
        return;
    }

    int y = x + 1;


    double pV, sV, pT, sT, S;
    if (x == -1) {  
        pV = 1;
        sV = s[y].V;

        pT = 0;
        sT = s[y].T;

        S = a[0];
    }
    else if (y == n) {
        sV = 1;
        pV = p[x].V;

        sT = 0;
        pT = p[x].T;

        S = l - a.back();
    }
    else {
        pV = p[x].V;
        sV = s[y].V;

        pT = p[x].T;
        sT = s[y].T;

        S = a[y] - a[x];
    }
    // cout << "x: " << x << "  y: " << y << "\n";
    // cout << "pV: " << pV << "\t";
    // cout << "sV: " << sV << "\t";
    // cout << "pT: " << pT << "\t";
    // cout << "sT: " << sT << "\t";
    // cout << "S: " << S << "\n";


    if (pT < sT) {
        S -= pV * abs(sT - pT);
        cout << S / (pV + sV) + sT << "\n";
    }
    else {
        S -= sV * abs(sT - pT);
        cout << S / (pV + sV) + pT << "\n";
    }

    // cout << "\n\n";
    // cout << "\n\n";
}

int32_t main() { 
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

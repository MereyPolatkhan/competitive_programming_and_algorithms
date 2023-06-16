#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;


int calc(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

void solve() {

    int n, m;
    cin >> n >> m;

    int i, j;
    cin >> i >> j;

    int d11 = calc(i, j, 1, 1);
    int d1m = calc(i, j, 1, m);
    int dn1 = calc(i, j, n, 1);
    int dnm = calc(i, j, n, m);


    vector<int> a = {d11, d1m, dn1, dnm};

    sort(all(a));


    if (a.back() == d11 || a.back() == dnm) {
        cout << 1 << " " << 1 << " " << n << " " << m << "\n";
        return;
    }

    
    if (a.back() == d1m || a.back() == dn1) {
        cout << 1 << " " << m << " " << n << " " << 1 << "\n";
        return;
    }
    
}

int main() {    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}

/*  things to check:
    1) long long    
    2) array sizes
    3) corner cases (n = 1, n = 0, etc.)
    4) clear
*/

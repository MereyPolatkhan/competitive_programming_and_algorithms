#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;



void solve() {

    int n;
    cin >> n;

    vector<pii> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    

    sort(all(a));

    int i = 0;

    while (i < n) {
        int j = i;
        while (a[j].)
    }
}   


/*  things to check:
    1) long long    
    2) array sizes
    3) corner cases (n = 1, n = 0, etc.)
    4) clear
*/

















int main() {    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}


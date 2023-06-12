#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;
typedef pair<int, int> pii;


void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    string s;
    cin >> s;

    vector<pair<int, int>> unlike, like;

    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            unlike.pb({a[i], i});
        }
        else {
            like.pb({a[i], i});
        }
    }

    sort(all(unlike));
    sort(all(like));

    int cnt = 1;
    for (int i = 0; i < unlike.size(); i++) {
        a[unlike[i].second] = cnt++;
    }   
    for (int i = 0; i < like.size(); i++) {
        a[like[i].second] = cnt++;
    }
    for (int &x: a) cout << x << " "; cout << "\n";

}

int main() {    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
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

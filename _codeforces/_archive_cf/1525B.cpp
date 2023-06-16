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

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    bool flag = true;
    for (int i = 1; i <= n; i++) {
        if (a[i] != i) {
            flag = false;
            break;
        }
    }

    if (flag) {
        cout << 0 << "\n";
    }
    else if (a[1] == 1 || a[n] == n) {
        cout << 1 << "\n";
    }
    else if (a[1] == n and a[n] == 1) {
        cout << 3 << "\n";
    }   
    else {
        cout << 2 << "\n";
    }
    
}

int main() {    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
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

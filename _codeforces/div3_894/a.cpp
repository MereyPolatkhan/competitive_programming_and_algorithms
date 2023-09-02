#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;
typedef pair<int, int> pii;


void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    string vika = "vika";
    int ind = 0;

    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if (ind < 4 and a[i][j] == vika[ind]) {
                ind++;
                break;
            }
        }
    }

    if (ind == 4) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }


 
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

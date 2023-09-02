#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;


void solve() {
    int n = 8;
    char a[n][n];
    char c = '#';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            if (a[i][j] == c and 
                a[i - 1][j - 1] == c and 
                a[i - 1][j + 1] == c and 
                a[i + 1][j + 1] == c and 
                a[i + 1][j - 1] == c) {
                    cout << i + 1 << " " << j + 1 << "\n";
                    return;
                }
        }
    }
}

/*  things to check:
    !  clear & resize SET, MAP, VECTOR, etc. or write in local functions
    1) long long    
    2) array sizes
    3) corner cases (n = 1, n = 0, etc.)
*/

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


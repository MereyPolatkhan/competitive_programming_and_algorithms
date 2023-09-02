#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

int counter(vector<vector<bool>> &used, int i1, int j1, int n, vector<string> &a) {
    int cnt0 = 0, cnt1 = 0;
    int i2 = n - 1 - i1, j2 = n - 1 - j1;
    int i3 = j1, j3 = n - 1 - i1;
    int i4 = j2, j4 = n - 1 - i2;

    used[i1][j1] = true;
    used[i2][j2] = true;
    used[i3][j3] = true;
    used[i4][j4] = true;



    if (a[i1][j1] == '1') cnt1++;
    else cnt0++;

    if (a[i2][j2] == '1') cnt1++;
    else cnt0++;

    if (a[i3][j3] == '1') cnt1++;
    else cnt0++;
    
    if (a[i4][j4] == '1') cnt1++;
    else cnt0++;



    return min(cnt1, cnt0);
}

void solve() {
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<bool>> used(n, vector<bool>(n, false));
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!used[i][j]) {
                res += counter(used, i, j, n, a);
            }
        }
    }    
    cout << res << "\n";
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


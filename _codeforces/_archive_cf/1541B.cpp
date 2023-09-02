#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
  
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

void print(vector<int>& a) {
    cout << " ==> ";
    for (int &i: a) cout << i << " ";
    cout << "\n\n";
}




int test_case = 0;

void solve() {
    // cout << "\n\ntest_case: " << ++test_case << "\n";
   
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> p(2 * n + 1, -1e9);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        p[a[i]] = i;
    }

    ll res = 0;
    for (int i = 2; i <= 2 * n - 1; i++) {
        for (int j = 1; j * j < i; j++) {
            if (i % j == 0) {
                if (p[j] + p[i / j] == i) {
                    res++;
                }
            }
        }
    }
    cout << res << "\n";
}   








int main() {    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

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
